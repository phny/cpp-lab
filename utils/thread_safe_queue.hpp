namespace cstk {

/// @brief 线程安全的队列
template <typename T> class ThreadSafeQueue {
public:
  /// @brief 构造函数
  ThreadSafeQueue() {}

  /// @brief 带参数的构造函数
  ThreadSafeQueue(ThreadSafeQueue const &other) {
    std::lock_guard<std::mutex> lock(other.mx);
    queue = other.queue;
  }

  /// @brief 往队列中压入数据
  void push(T new_value) {
    std::lock_guard<std::mutex> lock(mx);
    queue.push(new_value);
    cv.notify_all();
  }

  /// @brief 弹出队列头部数据,队列为空则阻塞
  void wait_and_pop(T &value) {
    std::unique_lock<std::mutex> lock(mx);
    cv.wait(lock, [this] { return !queue.empty(); });
    value = queue.front();
    queue.pop();
  }

  /// @brief 弹出队列头部数据，并返回指向该数据的指针,队列为空则阻塞
  /// @return 返回指向返回数据的智能指针
  std::shared_ptr<T> wait_and_pop() {
    std::unique_lock<std::mutex> lock(mx);
    cv.wait(lock, [this] { return !queue.empty(); });
    std::shared_ptr<T> res(std::make_shared<T>(queue.front()));
    queue.pop();
    return res;
  }

  /// @brief 弹出队列头部数据
  /// @return 为空则返回false，反之返回true
  bool try_pop(T &value) {
    std::lock_guard<std::mutex> lock(mx);
    if (queue.empty()) {
      return false;
    }
    value = queue.front();
    queue.pop();
    return true;
  }

  /// @brief 弹出队列头部数据
  /// @return 返回指向返回数据的智能指针
  std::shared_ptr<T> try_pop() {
    std::lock_guard<std::mutex> lock(mx);
    if (queue.empty()) {
      return std::shared_ptr<T>();
    }
    std::shared_ptr<T> res(std::make_shared<T>(queue.front()));
    queue.pop();
    return res;
  }

  /// @brief 判断队列是否为空
  bool empty() const {
    std::lock_guard<std::mutex> lock(mx);
    return queue.empty();
  }

  /// @brief 返回队列的大小
  int32_t size() const {
    std::lock_guard<std::mutex> lock(mx);
    return queue.size();
  }

private:
  mutable std::mutex mx; ///< 互斥量，保证队列的操作是互斥的
  std::queue<T> queue;   ///< 存放队列数据
  std::condition_variable cv; ///< 条件变量，用于队列各个op操作之间的消息通信
};

} // namespace cstk
