#include <fstream>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

class LruQueue {
public:
  LruQueue() = default;

  LruQueue(int64_t capacity) : capacity_(capacity) {}

  /// @brief 获取元素
  /// @param[in] key 输入的key
  int64_t Get(int64_t key);

  /// @brief 压入元素
  /// @param[in] key key
  /// @param[in] value value
  /// @return 返回被删除的key，没有删除返回-1
  int64_t Put(int64_t key, int64_t value);

  /// @brief 根据指定的key删除元素
  /// @note 删除操作不影响capacity,元素不存在不会产生报错
  void Remove(const int64_t key);

  /// @brief 获取所有元素
  std::vector<std::pair<int64_t, int64_t>> Data();

  /// @brief 重置大小
  /// @param[in] size 新容量
  /// @return 返回被删除的key列表
  std::vector<int64_t> Resize(int64_t capacity);

  /// @brief 重置队列
  /// @note capacity == 1
  void Reset();

  /// @brief 获取队列当前的容量
  int64_t Size();

  /// @brief 打印队列的状态
  void Status();

  void Display() {
    for (auto i : lru_) {
      cout << i.first << ":" << i.second << "->";
    }
    cout << endl;
  }

  /// @brief 序列化到流
  void SerialiazeToStream(std::ostream &os);

  /// @brief 从流中反序列化出queue
  static void DeserializeFromStream(std::istream &in, LruQueue &queue);

  void PrintTable() {
    for (auto i : table_) {
      std::cout << i.second->first << ":" << i.second->second << std::endl;
    }
  }

  LruQueue &operator=(const LruQueue &other);

private:
  std::unordered_map<int64_t, std::list<std::pair<int64_t, int64_t>>::iterator>
      table_;
  std::list<std::pair<int64_t, int64_t>> lru_;
  /// @note 默认容量是1
  int64_t capacity_ = 1;
};

int64_t LruQueue::Get(int64_t key) {
  auto it = table_.find(key);
  if (it != table_.end()) {
    lru_.splice(lru_.begin(), lru_, it->second);
    return it->second->second;
  } else {
    std::cout << "key " << key << " not found" << std::endl;
  }
  return -1;
}

int64_t LruQueue::Put(int64_t key, int64_t value) {
  int64_t res = -1;
  auto it = table_.find(key);
  if (it != table_.end()) {
    lru_.splice(lru_.begin(), lru_, it->second);
    it->second->second = value;
    return -1;
  }

  lru_.emplace_front(key, value);
  table_[key] = lru_.begin();
  // 删除链表最后的元素
  if (table_.size() > capacity_) {
    res = lru_.back().first;
    table_.erase(lru_.back().first);
    lru_.pop_back();
  }
  return res;
}

void LruQueue::Remove(const int64_t key) {
  auto it = table_.find(key);
  if (it != table_.end()) {
    table_.erase(key);
    lru_.remove(std::make_pair(key, key));
  }
}

std::vector<std::pair<int64_t, int64_t>> LruQueue::Data() {
  std::vector<std::pair<int64_t, int64_t>> res;
  for (auto i : lru_) {
    res.push_back(std::make_pair(i.first, i.second));
  }
  return res;
}

std::vector<int64_t> LruQueue::Resize(int64_t capacity) {
  std::vector<int64_t> res;
  if (capacity <= 0) {
    return res;
  }
  if (table_.empty()) {
    // 队列中没有内容
    capacity_ = capacity;
  } else {
    // 队列中已经存在内容
    if (capacity >= capacity_) {
      capacity_ = capacity;
    } else {
      // 更新table
      auto it = lru_.begin();
      for (size_t i = 0; i < capacity; i++) {
        it++;
      }
      for (; it != lru_.end(); ++it) {
        res.push_back(it->first);
        table_.erase(it->first);
      }
      // 更新链表
      lru_.resize(capacity);
      capacity_ = capacity;
    }
  }
  return res;
}

void LruQueue::Reset() {
  capacity_ = 1;
  lru_.clear();
  table_.clear();
}

int64_t LruQueue::Size() { return capacity_; }

void LruQueue::Status() {
  std::cout << "lru size: " << lru_.size() << ", table size: " << table_.size()
            << ", capacity: " << capacity_ << std::endl;
}

void LruQueue::SerialiazeToStream(std::ostream &os) {
  os.write((char *)&capacity_, sizeof(capacity_));
  std::vector<std::pair<int64_t, int64_t>> datas = Data();
  int64_t data_num = datas.size();
  os.write((char *)&data_num, sizeof(data_num));
  for (int64_t i = data_num - 1; i >= 0; i--) {
    int64_t key = datas[i].first;
    int64_t value = datas[i].second;
    os.write((char *)&key, sizeof(key));
    os.write((char *)&value, sizeof(value));
  }
}

void LruQueue::DeserializeFromStream(std::istream &in, LruQueue &queue) {
  queue.Reset();
  int64_t capacity;
  in.read((char *)&capacity, sizeof(capacity));
  queue.Resize(capacity);
  int64_t data_num;
  in.read((char *)&data_num, sizeof(data_num));
  for (int64_t i = 0; i < data_num; i++) {
    int64_t key, value;
    in.read((char *)&key, sizeof(key));
    in.read((char *)&value, sizeof(value));
    queue.lru_.emplace_front(std::make_pair(key, value));
    queue.table_.insert(std::make_pair(key, queue.lru_.begin()));
  }
}

LruQueue &LruQueue::operator=(const LruQueue &other) {
  lru_.clear();
  table_.clear();
  capacity_ = other.capacity_;
  for (auto it = other.lru_.begin(); it != other.lru_.end(); ++it) {
    lru_.emplace_front(*it);
    table_.insert({it->first, lru_.begin()});
  }
  return *this;
}

int main(int argc, char *argv[]) {
  LruQueue myqueue;
  myqueue.Resize(6);
  for (size_t i = 0; i < 6; i++) {
    myqueue.Put(i, i);
  }
  myqueue.Display();

  auto res = myqueue.Resize(20);
  for (auto i : res) {
    cout << i << " ";
  }
  cout << endl;

  for (size_t i = 10; i < 50; i++) {
    myqueue.Put(i, i);
  }
  myqueue.Display();
  myqueue.Status();

  res = myqueue.Resize(5);
  for (auto i : res) {
    cout << i << " ";
  }
  cout << endl;
  myqueue.Display();

  // cout << "serialize to file" << endl;
  // myqueue.Display();
  // std::ofstream os("cache.bin", std::ios::binary);
  // myqueue.SerialiazeToStream(os);
  // os.close();

  // cout << "after deserialize" << std::endl;
  // std::ifstream in("cache.bin", std::ios::binary);
  // LruQueue::DeserializeFromStream(in, myqueue);
  // in.close();
  // myqueue.Display();

  // auto datas2 = myqueue.Data();
  // for (auto i : datas2) {
  //     int64_t key = i.first;
  //     int64_t value = i.second;
  //     myqueue.Get(key);
  //     myqueue.Get(key);
  // }
  // cout << "after Get" << endl;
  // myqueue.Display();

  return 0;
}