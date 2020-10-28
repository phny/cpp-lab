#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

std::mutex mx;
std::condition_variable cv;
std::queue<int> q;

bool finished = false;

void producer(int n) {
  for (int i = 0; i < n; ++i) {
    {
      std::lock_guard<std::mutex> lk(mx);
      q.push(i);
      std::cout << "pushing " << i << std::endl;
      std::this_thread::sleep_for(std::chrono::seconds(1));
      cv.notify_all();
    }
  }
  {
    std::lock_guard<std::mutex> lk(mx);
    finished = true;
  }
  cv.notify_all();
}

void consumer() {
  while (true) {
    std::unique_lock<std::mutex> lk(mx);
    cv.wait(lk, [] { return finished || !q.empty(); });
    while (!q.empty()) {
      std::cout << "consuming " << q.front() << std::endl;
      q.pop();
    }
    if (finished)
      break;
  }
}

int main() {
  std::thread p(producer, 10);
  std::thread c(consumer);
  c.detach();
  p.join();
  std::cout << "finished!" << std::endl;
}