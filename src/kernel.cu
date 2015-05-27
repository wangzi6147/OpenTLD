#include "kernel.h"

__global__ void kernel(int size, int *dev_tmp)
{
	*dev_tmp = size + 1;
}

void processWithCuda(TLD *tld){
	TLD *dev_tld = NULL;
	int *dev_tmp = 0;
	int tmp = 0;
	cudaSetDevice(0);
	cudaMalloc((void**)&dev_tmp, sizeof(int));
	cudaMalloc((void**)&dev_tld, sizeof(TLD));
	cudaMemcpy(dev_tmp, &tmp, sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(dev_tld, tld, sizeof(TLD), cudaMemcpyHostToDevice);
	printf("%d\n", tld->grid.size());
	kernel << <1, 1 >> >(tld->grid.size(), dev_tmp);
	cudaMemcpy(&tmp, dev_tmp, sizeof(int), cudaMemcpyDeviceToHost);
	printf("%d\n", tmp);
}
