#include <stdio.h>
#include <thread>
#include <chrono>

void threadproc() {
  while (true) {
    printf("I am New Thread!\n");
    std::this_thread::sleep_for (std::chrono::seconds(1));
  }
}

void func() { 
    // 当 func 函数调用结束后，func 中局部变量 t （线程对象）被销毁了，而此时线程函数仍然在运行。
    // 这就是常所说的，使用 std::thread 类时，必须保证线程函数运行期间，其线程对象有效。这是一个很容易犯的错误
    std::thread t(threadproc);
    t.detach();
}

int main() {
  func();

  while (true) {
    //权宜之计，让主线程不要提前退出
    std::this_thread::sleep_for (std::chrono::seconds(1));
  }

  return 0;
}
