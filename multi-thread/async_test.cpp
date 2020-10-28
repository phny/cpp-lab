/*************************************************************************
        > File Name: async_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年06月07日 星期日 22时06分23秒
 ************************************************************************/

#include <algorithm>
#include <chrono>
#include <future>
#include <iostream>
#include <sstream>
#include <thread>
#include <vector>

using namespace std;

std::mutex mx;

// 判断素数
bool IsPrime(int x) {
  {
    std::unique_lock<std::mutex> lock(mx);
    cout << "thread " << std::this_thread::get_id() << " start" << endl;
  }
  std::this_thread::sleep_for(std::chrono::milliseconds(3000));

  for (int i = 2; i < x; ++i) {
    if (x % i == 0) {
      return false;
    }
  }

  return true;
}

/// 线程当中又开启新的线程
void PushToVec(std::vector<int64_t> &v, int n) {
  std::future<void> fut = std::async(std::launch::async, [&v, n] {
    for (int i = 0; i < n; i++) {
      v.push_back(i);
    }
    cout << "thread id: " << std::this_thread::get_id() << " finish" << endl;
  });
  // 等待线程完成
  fut.get();
}

int main() {
  int64_t a = 313222313343441;
  int64_t b = 3132223343313;
  int64_t c = 9399488994337;

  // std::launch::async 要求线程立即启动
  std::future<bool> a_fut = std::async(std::launch::async, IsPrime, a);
  std::future<bool> b_fut = std::async(std::launch::async, IsPrime, b);
  std::future<bool> c_fut = std::async(std::launch::async, IsPrime, c);

  // 线程运行的同时主线程继续执行
  std::this_thread::sleep_for(std::chrono::seconds(1));
  cout << "Keep do other things" << endl;

  // 获取每个线程的执行结果
  bool a_ret = a_fut.get();
  bool b_ret = b_fut.get();
  bool c_ret = c_fut.get();

  if (a_ret) {
    std::cout << a << " It is prime!\n";
  } else {
    std::cout << a << " It is not prime.\n";
  }

  if (b_ret) {
    std::cout << b << " It is prime!\n";
  } else {
    std::cout << b << " It is not prime.\n";
  }

  if (c_ret) {
    std::cout << c << " It is prime!\n";
  } else {
    std::cout << c << " It is not prime.\n";
  }

  // 往数组中push元素
  std::vector<int64_t> v1;
  std::vector<int64_t> v2;

  std::future<void> v1_fut =
      std::async(std::launch::async, PushToVec, std::ref(v1), 10);
  std::future<void> v2_fut =
      std::async(std::launch::async, PushToVec, std::ref(v2), 20);

  std::this_thread::sleep_for(std::chrono::seconds(1));
  cout << "Keep do other things" << endl;

  // 等带两个线程完成
  v1_fut.get();
  v2_fut.get();

  // 输出结果
  for_each(v1.begin(), v1.end(), [](const int64_t i) { cout << i << " "; });
  cout << endl;
  for_each(v2.begin(), v2.end(), [](const int64_t i) { cout << i << " "; });
  cout << endl;

  return 0;
}
