#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "cuda_device_runtime_api.h"
#include <TLD.h>

void processWithCuda(TLD *tld, const cv::Mat &img, const FerNNClassifier &classifier);