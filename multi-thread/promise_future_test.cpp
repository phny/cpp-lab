#include <functional>
#include <future>
#include <iostream>
#include <thread>

using namespace std;

void print_int(std::future<int> &fut) {
  // 获取线程id
  std::thread::id tid = std::this_thread::get_id();
  std::cout << "tid=" << tid << std::endl;

  // 获取共享状态
  int x = fut.get();
  std::cout << "value: " << x << std::endl;
}

int main(int argc, char *argv[]) {
  std::promise<int> prom; /// 创建promise对象

  std::future<int> fut =
      prom.get_future(); /// 获取promise内部的future，fut将和promise共享promise中的共享状态，该共享状态用于返回计算结果

  std::thread th1(
      print_int,
      std::ref(fut)); /// 创建一个线程，并通过引用方式将fut传到print_int中
  std::thread th2(
      print_int,
      std::ref(fut)); /// 创建一个线程，并通过引用方式将fut传到print_int中
  std::thread th3(
      print_int,
      std::ref(fut)); /// 创建一个线程，并通过引用方式将fut传到print_int中

  prom.set_value(10); /// 设置共享状态值

  th1.join(); /// 等待子线程
  th2.join();
  th3.join();

  return 0;
}