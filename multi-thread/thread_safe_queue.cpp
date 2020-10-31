#include <condition_variable>
#include <iostream>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>

using namespace std;

template <typename T> class Queue {
private:
  mutable std::mutex mx;
  std::queue<T> queue;
  std::condition_variable cv;

public:
  Queue() {}

  Queue(Queue const &other) {
    std::lock_guard<std::mutex> lock(other.mx);
    queue = other.queue;
  }
  void push(T new_value) {
    std::lock_guard<std::mutex> lock(mx);
    queue.push(new_value);
    cv.notify_one();
  }
  void wait_and_pop(T &value) {
    std::unique_lock<std::mutex> lock(mx);
    cv.wait(lock, [this] { return !queue.empty(); });
    value = queue.front();
    queue.pop();
  }
  std::shared_ptr<T> wait_and_pop() {
    std::unique_lock<std::mutex> lock(mx);
    cv.wait(lock, [this] { return !queue.empty(); });
    std::shared_ptr<T> res(std::make_shared<T>(queue.front()));
    queue.pop();
    return res;
  }
  bool try_pop(T &value) {
    std::lock_guard<std::mutex> lock(mx);
    if (queue.empty())
      return false;
    value = queue.front();
    queue.pop();
    return true;
  }
  std::shared_ptr<T> try_pop() {
    std::lock_guard<std::mutex> lock(mx);
    if (queue.empty())
      return std::shared_ptr<T>();
    std::shared_ptr<T> res(std::make_shared<T>(queue.front()));
    queue.pop();
    return res;
  }
  bool empty() const {
    std::lock_guard<std::mutex> lock(mx);
    return queue.empty();
  }

  int32_t size() const {
    std::lock_guard<std::mutex> lock(mx);
    return queue.size();
  }
};

/// @brief 测试
void queue_test(Queue<int> &queue, int n) {
  for (int i = 0; i < n; i++) {
    queue.push(i);
  }
}

int main(int argc, char *argv[]) {
  auto queue = Queue<int>();

  std::cout << "before size: " << queue.size() << std::endl;

  std::thread t1 = std::thread(queue_test, std::ref(queue), 10);
  std::thread t2 = std::thread(queue_test, std::ref(queue), 10);

  t1.join();
  t2.join();

  while (!queue.empty()) {
    auto item = queue.try_pop();
    std::cout << *item.get() << std::endl;
  }

  std::cout << "after size: " << queue.size() << std::endl;

  return 0;
}