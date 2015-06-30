#include "kernel.h"

using namespace std;
using namespace cv;
using namespace cv::gpu;

struct result{
	int fern[10];
	int res;
	float conf;
};

struct proData{
	int size, nstructs, structSize, featureSizeSize;
	float var, thr_fern;
};

struct boundingbox{
	int x;
	int y;
	int width; 
	int height;
	int sidx;
};
struct feature{
	uchar x1, y1, x2, y2;
};

__global__ void kernel(float* posteriors, feature* featureData, proData * dt, boundingbox* bbdata, const PtrStepSz<uchar1> img, const PtrStepSz<float1> iisum, PtrStep<float1> iisqsum, result *result)
{
	int i = threadIdx.x + blockIdx.x * blockDim.x;
	if (i < (*dt).size){
		result[i].res = 0;
		int fern[10];
		feature featureTmp;
		float brs = iisum(bbdata[i].y + bbdata[i].height, bbdata[i].x + bbdata[i].width).x;
		float bls = iisum(bbdata[i].y + bbdata[i].height, bbdata[i].x).x;
		float trs = iisum(bbdata[i].y, bbdata[i].x + bbdata[i].width).x;
		float tls = iisum(bbdata[i].y, bbdata[i].x).x;
		float brsq = iisqsum(bbdata[i].y + bbdata[i].height, bbdata[i].x + bbdata[i].width).x;
		float blsq = iisqsum(bbdata[i].y + bbdata[i].height, bbdata[i].x).x;
		float trsq = iisqsum(bbdata[i].y, bbdata[i].x + bbdata[i].width).x;
		float tlsq = iisqsum(bbdata[i].y, bbdata[i].x).x;
		float mean = (brs + tls - trs - bls) / ((float)bbdata[i].height*(float)bbdata[i].width);
		float sqmean = (brsq + tlsq - trsq - blsq) / ((float)bbdata[i].height*(float)bbdata[i].width);
		if (sqmean - mean*mean >= (*dt).var){
			int leaf;
			for (int t = 0; t<(*dt).nstructs; t++){
				leaf = 0;
				for (int f = 0; f<(*dt).structSize; f++){
					featureTmp = featureData[bbdata[i].sidx*(*dt).featureSizeSize + t*(*dt).structSize + f];
					leaf = (leaf << 1) + (img(bbdata[i].y + featureTmp.y1, bbdata[i].x + featureTmp.x1).x > img(bbdata[i].y+featureTmp.y2, bbdata[i].x+featureTmp.x2).x);
				}
				fern[t] = leaf;
			}
			float votes = 0;
			for (int t = 0; t <(*dt).nstructs; t++) {
				votes += posteriors[t*(int)pow(2.0f, (float)(*dt).structSize)+ fern[t]];
			}
			result[i].conf = votes;
			for (int t = 0; t<10; t++){
				result[i].fern[t] = fern[t];
			}
			if (votes>(*dt).nstructs*(*dt).thr_fern){
				result[i].res = 1;
			}
		}
		else{
			result[i].conf = 0.0;
		}
	}
}

void safeCall(cudaError e){
	if (e != cudaSuccess){
		printf("CUDA error: %s\n", cudaGetErrorString(e));
		system("pause");
	}
}

void processWithCuda(TLD *tld, const Mat &img, const FerNNClassifier &classifier){
	GpuMat gpuiisum, gpuiisqsum, gpuimg;
	gpuiisum.upload(tld->iisum);
	gpuiisum.convertTo(gpuiisum, CV_32F);
	gpuiisqsum.upload(tld->iisqsum);
	gpuiisqsum.convertTo(gpuiisqsum, CV_32F);
	gpuimg.upload(img);
	vector<BoundingBox> grid = tld->grid;
	proData dt;
	dt.size = grid.size();
	dt.var = tld->var;
	dt.nstructs = classifier.nstructs;
	dt.structSize = classifier.structSize;
	dt.thr_fern = classifier.thr_fern;
	boundingbox * data = new boundingbox[dt.size];
	for (int i = 0; i < dt.size; i++){
		data[i].x = grid[i].x;
		data[i].y = grid[i].y;
		data[i].width = grid[i].width;
		data[i].height = grid[i].height;
		data[i].sidx = grid[i].sidx;
	}
	int featureSize = classifier.features.size();
	int featureSizeSize = classifier.features[0].size();
	dt.featureSizeSize = featureSizeSize;
	feature * featureData = new feature[featureSize*featureSizeSize];
	for (int i = 0; i < featureSize; i++){
		for (int j = 0; j < featureSizeSize; j++){
			featureData[i*featureSizeSize + j].x1 = classifier.features[i][j].x1;
			featureData[i*featureSizeSize + j].y1 = classifier.features[i][j].y1;
			featureData[i*featureSizeSize + j].x2 = classifier.features[i][j].x2;
			featureData[i*featureSizeSize + j].y2 = classifier.features[i][j].y2;
		}
	}
	boundingbox *dev_bbdata = NULL;
	feature *dev_featureData = NULL;
	proData *dev_dt = NULL;
	float * dev_posteriors = NULL;
	int posteriorsSize = classifier.posteriors.size();
	int posteriorsSizeSize = classifier.posteriors[0].size();
	float *posteriors = new float[posteriorsSize*posteriorsSizeSize];
	for (int i = 0; i < posteriorsSize; i++){
		for (int j = 0; j < posteriorsSizeSize; j++){
			posteriors[i*posteriorsSizeSize + j] = classifier.posteriors[i][j];
		}
	}
	safeCall(cudaMalloc((void**)&dev_posteriors, posteriorsSize*posteriorsSizeSize*sizeof(float)));
	safeCall(cudaMalloc((void**)&dev_featureData, featureSize*featureSizeSize*sizeof(feature)));
	safeCall(cudaMalloc((void**)&dev_bbdata, dt.size*sizeof(boundingbox)));
	safeCall(cudaMalloc((void**)&dev_dt, sizeof(proData)));
	safeCall(cudaMemcpy(dev_posteriors, posteriors, posteriorsSize*posteriorsSizeSize*sizeof(float), cudaMemcpyHostToDevice));
	safeCall(cudaMemcpy(dev_dt, &dt, sizeof(proData), cudaMemcpyHostToDevice));
	safeCall(cudaMemcpy(dev_bbdata, data, dt.size*sizeof(boundingbox), cudaMemcpyHostToDevice));
	safeCall(cudaMemcpy(dev_featureData, featureData, featureSize*featureSizeSize*sizeof(feature), cudaMemcpyHostToDevice));

	result *dev_result = NULL;
	result *res = new result[dt.size];
	safeCall(cudaMalloc((void**)&dev_result, dt.size*sizeof(result)));
	kernel << <1024, 1024 >> >(dev_posteriors, dev_featureData, dev_dt, dev_bbdata, gpuimg, gpuiisum, gpuiisqsum, dev_result);
	safeCall(cudaMemcpy(res, dev_result, dt.size * sizeof(result), cudaMemcpyDeviceToHost));

	int output = 0;
	for (int i = 0; i < dt.size; i++){
		if (res[i].res)
			output++;
	}
	printf("%d %d\n", dt.size, output);

	for (int i = 0; i < dt.size; i++){
		tld->tmp.conf[i] = res[i].conf;
		for (int j = 0; j < 10; j++){
			tld->tmp.patt[i][j] = res[i].fern[j];
		}
		if (res[i].res){
			tld->dt.bb.push_back(i);
		}
	}

	safeCall(cudaFree(dev_posteriors));
	safeCall(cudaFree(dev_bbdata));
	safeCall(cudaFree(dev_dt));
	safeCall(cudaFree(dev_featureData));
	safeCall(cudaFree(dev_result));
	
	delete data;
	delete featureData;
	delete res;

	return;
}
