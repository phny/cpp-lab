#include <chrono>
#include <future>
#include <iostream>
#include <thread>

using namespace std;

/*
如果 std::future
被存放在一个临时对象中，那么std::async会立马阻塞，因为临时对象在返回后立马被析构了。
例如下面的代码中将会阻塞 10s，但是如果加上 auto f = 那么只会阻塞 5s
*/

auto sleep = [](int s) {
  std::this_thread::sleep_for(std::chrono::seconds(s));
};

int main(int argc, char *argv[]) {
  // std::async( std::launch::async, sleep, 5 ); // 临时对象被析构，阻塞 5s
  // std::async( std::launch::async, sleep, 5 ); // 临时对象被析构，阻塞
  // 5s,两个线程一共阻塞 10s

  auto f1 = std::async(std::launch::async, sleep, 5); // 两个线程一共阻塞 5s
  auto f2 = std::async(std::launch::async, sleep, 5);

  return 0;
}