#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

std::mutex g_mutex;
int g_count = 0;

/*
使用 unique_lock 自动加锁、解锁。
unique_lock 与 lock_guard
原理相同，但是提供了更多功能（比如可以结合条件变量使用）。
注意：mutex::scoped_lock 其实就是 unique_lock<mutex> 的 typedef。
unique_lock 和 lock_guard 详细比较:
https://stackoverflow.com/questions/6731027/boostunique-lock-vs-boostlock-guard
*/

void Counter() {
  std::unique_lock<std::mutex> lock(g_mutex);

  int i = ++g_count;
  std::cout << "count: " << i << std::endl;
}

int main() {
  const std::size_t SIZE = 4;

  std::vector<std::thread> v;
  v.reserve(SIZE);

  for (std::size_t i = 0; i < SIZE; ++i) {
    v.emplace_back(&Counter);
  }

  for (std::thread &t : v) {
    t.join();
  }

  return 0;
}