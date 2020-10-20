#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <unistd.h>

std::mutex mtx;
std::condition_variable cv;
bool first_step = false;
bool second_step = false;
bool third_step = false;

void worker(int id) {
  std::unique_lock<std::mutex> lck(mtx);
  cv.wait(lck, [] { return first_step == true; });
  std::cout << "thread " << id << " finish step one" << std::endl;

  cv.wait(lck, [] { return second_step == true; });
  std::cout << "thread " << id << " finish step second" << std::endl;

  cv.wait(lck, [] { return third_step == true; });
  std::cout << "thread " << id << " finish step third" << std::endl;

  // 释放锁
  lck.unlock();
}

void go() {
  {
    // 重要：每次唤醒都需要lock
    std::unique_lock<std::mutex> lck(mtx);
    std::cout << "set first step flag to true" << std::endl;
    first_step = true;
    cv.notify_all();
  }

  sleep(3);

  {
    // 重要：每次唤醒都需要lock
    std::unique_lock<std::mutex> lck(mtx);
    std::cout << "set second step flag to true" << std::endl;
    second_step = true;
    cv.notify_all();
  }

  sleep(3);

  {
    // 重要：每次唤醒都需要lock
    std::unique_lock<std::mutex> lck(mtx);
    std::cout << "set third step flag to true" << std::endl;
    third_step = true;
    cv.notify_all();
  }
}

int main() {
  std::thread threads[10];
  // 启动10个线程
  for (int i = 0; i < 10; ++i)
    threads[i] = std::thread(worker, i);

  // 唤醒
  go();

  for (auto &th : threads) {
    th.join();
  }

  return 0;
}
