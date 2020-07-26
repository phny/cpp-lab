/*************************************************************************
        > File Name: cuda_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年07月09日 星期四 16时13分07秒
 ************************************************************************/

#include <cuda_runtime.h>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>
#include <unistd.h>

#include <faiss/gpu/StandardGpuResources.h>

using namespace std;

std::mutex mutex_;

faiss::gpu::StandardGpuResources *CudaAllocator(int device_id) {
  std::unique_lock<std::mutex> locker(mutex_);
  std::cout << "get gpu resource " << std::endl;
  cudaGetDevice(&device_id);
  cudaSetDevice(device_id);

  // 申请 gpu 资源并且初始化设备
  faiss::gpu::StandardGpuResources *gpu_resource =
      new faiss::gpu::StandardGpuResources();
  gpu_resource->initializeForDevice(device_id);

  return gpu_resource;
}

void CudaDeAllocator(faiss::gpu::StandardGpuResources *gpu_resource) {
  int device_id = 0;
  cudaSetDevice(device_id);
  delete gpu_resource;
}

int main() {
  int device_id = 0;

  std::future<faiss::gpu::StandardGpuResources *> f1 =
      std::async(std::launch::async, CudaAllocator, device_id);
  std::future<faiss::gpu::StandardGpuResources *> f2 =
      std::async(std::launch::async, CudaAllocator, device_id);
  std::future<faiss::gpu::StandardGpuResources *> f3 =
      std::async(std::launch::async, CudaAllocator, device_id);

  auto *gpu_1 = f1.get();
  auto *gpu_2 = f2.get();
  auto *gpu_3 = f3.get();

  sleep(5);

  std::vector<faiss::gpu::StandardGpuResources *> v{gpu_1, gpu_2, gpu_3};
  for (auto &gpu : v) {
    CudaDeAllocator(gpu);
  }

  cudaDeviceReset();

  std::cout << "after delete cuda handle resource" << std::endl;

  sleep(10);

  return 0;
}
