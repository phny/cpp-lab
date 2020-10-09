#include <cuda_runtime.h>
#include <future>
#include <iostream>
#include <mutex>
#include <sstream>
#include <thread>
#include <unistd.h>

#include <faiss/Index.h>
#include <faiss/gpu/GpuIndexIVFPQ.h>
#include <faiss/gpu/StandardGpuResources.h>

using namespace std;

std::mutex mutex_;

class DeviceScope {
public:
  explicit DeviceScope(int device) {
    cudaGetDevice(&prev_device_);
    if (prev_device_ != device) {
      cudaSetDevice(device);
    } else {
      prev_device_ = -1;
    }
  }
  ~DeviceScope() {
    if (prev_device_ != -1) {
      cudaSetDevice(prev_device_);
    }
  }

private:
  int prev_device_;
};

faiss::gpu::StandardGpuResources *CudaAllocator(int device_id) {
  // 函数锁
  std::unique_lock<std::mutex> locker(mutex_);

  // 获取当前线程的id
  std::thread::id tid = std::this_thread::get_id();
  std::cout << "current thread id =" << tid << std::endl;

  DeviceScope scope(device_id);

  // 申请 gpu 资源并且初始化设备
  faiss::gpu::StandardGpuResources *gpu_resource =
      new faiss::gpu::StandardGpuResources();
  gpu_resource->initializeForDevice(device_id);

  // 创建索引
  faiss::gpu::GpuIndexIVFPQConfig gpu_index_config;
  gpu_index_config.device = device_id;
  faiss::gpu::GpuIndexIVFPQ *pq_index = new faiss::gpu::GpuIndexIVFPQ(
      gpu_resource, 256, 1024, 32, 8, faiss::METRIC_L2, gpu_index_config);

  return gpu_resource;
}

int main() {
  std::future<faiss::gpu::StandardGpuResources *> f1 =
      std::async(std::launch::async, CudaAllocator, 3);
  std::future<faiss::gpu::StandardGpuResources *> f2 =
      std::async(std::launch::async, CudaAllocator, 4);
  std::future<faiss::gpu::StandardGpuResources *> f3 =
      std::async(std::launch::async, CudaAllocator, 5);

  auto *g1 = f1.get();
  auto *g2 = f2.get();
  auto *g3 = f3.get();

  std::cout << "finished get device" << std::endl;

  sleep(3);

  std::vector<faiss::gpu::StandardGpuResources *> v{g1, g2, g3};
  int device = 3;
  for (auto &gpu : v) {
    DeviceScope scope(device);
    delete gpu;
    gpu = NULL;
    cudaDeviceReset();
    std::cout << "release device: " << device << std::endl;

    device++;
  }

  std::cout << "after delete cuda handle resource" << std::endl;

  sleep(100);

  return 0;
}