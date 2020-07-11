/*************************************************************************
        > File Name: cuda_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年07月09日 星期四 16时13分07秒
 ************************************************************************/

#include <cuda_runtime.h>
#include <iostream>
#include <unistd.h>

#include <faiss/gpu/StandardGpuResources.h>

using namespace std;

int main() {
  int device_id = 0;
  cudaGetDevice(&device_id);
  cudaSetDevice(device_id);

  faiss::gpu::StandardGpuResources *gpu_resource =
      new faiss::gpu::StandardGpuResources();
  gpu_resource->initializeForDevice(0);

  sleep(10);

  delete gpu_resource;
  std::cout << "delete gpu resource" << std::endl;

  sleep(1000);
  return 0;
}
