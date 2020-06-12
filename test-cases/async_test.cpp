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
#include <thread>
#include <vector>

using namespace std;

// 判断素数
bool is_prime(int x) {
  std::cout << "Calculating " << x << ", Please, wait...\n";
  std::this_thread::sleep_for(std::chrono::milliseconds(5000));
  for (int i = 2; i < x; ++i) {
    if (x % i == 0) {
      return false;
    }
  }

  return true;
}

// 往数组push值
// 注意:  C++11的std::thread构造函数不支持std::ref的这种用法,
// 所以使用指针代替引用！或者用std::bind、lambda等解决
void PushToVec(std::vector<int64_t> *v, int n) {
  cout << "generate use: " << n << endl;
  // 待研究。。。
  // std::future<void> fut = std::async(std::launch::async, [&] (const int n) {
  //    for (int i = 0; i < n; i++) {
  //        v->push_back(i);
  //    }
  //});
  // fut.get();

  for (int i = 0; i < n; i++) {
    v->push_back(i);
  }
  std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}

int main() {
  int64_t a = 313222313;
  int64_t b = 3132223343313;
  int64_t c = 9399488994337;

  // std::launch::async 要求线程立即启动
  std::future<bool> a_fut = std::async(std::launch::async, is_prime, a);
  std::future<bool> b_fut = std::async(std::launch::async, is_prime, b);
  std::future<bool> c_fut = std::async(std::launch::async, is_prime, c);

  // 线程运行的同时主线程继续执行
  cout << "Do other things" << endl;

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

  std::vector<int64_t> v1;
  std::vector<int64_t> v2;

  std::future<void> v1_fut = std::async(std::launch::async, PushToVec, &v1, 10);
  std::future<void> v2_fut = std::async(std::launch::async, PushToVec, &v2, 20);

  cout << "Keep do other things" << endl;

  v1_fut.get();
  v2_fut.get();

  for_each(v1.begin(), v1.end(), [](const int64_t i) { cout << i << " "; });
  cout << endl;
  for_each(v2.begin(), v2.end(), [](const int64_t i) { cout << i << " "; });
  cout << endl;

  return 0;
}
