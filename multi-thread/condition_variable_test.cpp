#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <unistd.h>

std::mutex mtx;
std::condition_variable cv;
bool create_flag = false; // 创建se条件变量
bool train_flag = false;  // 训练索引条件变量
bool add_flag = false;    // 添加特征条件变量
bool search_flag = false; // 检索条件变量
bool deinit_flag = false; // deinit 条件变量

void worker(int id) {
  std::unique_lock<std::mutex> lck(mtx);
  cv.wait(lck, [] { return create_flag == true; });
  std::cout << "thread " << id << " create search engine" << std::endl;

  cv.wait(lck, [] { return train_flag == true; });
  // 这里需要单卡train好，然后再拿train好的index创建其他的 se
  std::cout << "thread " << id << " train index" << std::endl;

  cv.wait(lck, [] { return add_flag == true; });
  std::cout << "thread " << id << " add features" << std::endl;

  cv.wait(lck, [] { return search_flag == true; });
  std::cout << "thread " << id << " search" << std::endl;

  cv.wait(lck, [] { return deinit_flag == true; });
  std::cout << "thread " << id << " deinit" << std::endl;

  // 释放锁
  lck.unlock();
}

void go() {
  {
    // 重要：每次唤醒都需要lock
    std::unique_lock<std::mutex> lck(mtx);
    std::cout << "set create flag to true" << std::endl;
    create_flag = true;
    cv.notify_all();
  }

  sleep(3);

  {
    std::unique_lock<std::mutex> lck(mtx);
    std::cout << "set train flag to true" << std::endl;
    train_flag = true;
    cv.notify_all();
  }

  sleep(3);

  {
    std::unique_lock<std::mutex> lck(mtx);
    std::cout << "set add flag to true" << std::endl;
    add_flag = true;
    cv.notify_all();
  }

  sleep(3);

  {
    std::unique_lock<std::mutex> lck(mtx);
    std::cout << "set search flag to true" << std::endl;
    search_flag = true;
    cv.notify_all();
  }

  sleep(3);

  {
    std::unique_lock<std::mutex> lck(mtx);
    std::cout << "set deinit flag to true" << std::endl;
    deinit_flag = true;
    cv.notify_all();
  }
}

int main() {
  std::thread threads[4];
  // 启动 4 个线程
  for (int i = 0; i < 4; ++i)
    threads[i] = std::thread(worker, i);

  // 唤醒
  go();

  for (auto &th : threads) {
    th.join();
  }

  return 0;
}
