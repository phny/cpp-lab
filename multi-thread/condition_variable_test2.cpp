#include <chrono>
#include <condition_variable>
#include <iostream>
#include <thread>
#include <time.h>

std::condition_variable cv;
std::mutex cv_m; // This mutex is used for three purposes:
                 // 1) to synchronize accesses to finished
                 // 2) to synchronize accesses to std::cerr
                 // 3) for the condition variable cv
int finished = 0;

void waits() {
  auto tid = std::this_thread::get_id();
  // 等待结束信号
  {
    std::unique_lock<std::mutex> lk(cv_m);
    std::cerr << "thread: " << tid << " waiting..." << std::endl;
    cv.wait(lk, [] { return finished == 1; });
  }
  // lk.unlock(); // 这个地方需要手动的解锁，不然后面的操作都是串行的!!!

  std::cerr << "thread: " << tid << " start work" << std::endl;
  int time = rand() % 5;
  std::cout << "thread: " << tid << " sleep time: " << time << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(time));
  std::cout << "thread: " << tid << " finish work" << std::endl;
}

void signals() {
  std::this_thread::sleep_for(std::chrono::seconds(1));
  {
    std::lock_guard<std::mutex> lk(cv_m);
    std::cerr << "Notifying all threads...\n";
  }
  cv.notify_all(); // 唤醒所有等待cv的线程，但是由于 i!=1 所以不能真正唤醒。

  std::this_thread::sleep_for(std::chrono::seconds(1));

  {
    // 再次唤醒所有的线程
    std::lock_guard<std::mutex> lk(cv_m);
    finished = 1; // 满足条件
    std::cerr << "Notifying all threads again...\n";
  }
  cv.notify_all();
}

int main() {
  std::thread t1(waits), t2(waits), t3(waits), t4(signals);
  t1.join();
  t2.join();
  t3.join();
  t4.join();
}