#include <iostream>
#include <map>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

using DataType = std::unordered_map<int, std::tuple<int, std::vector<int>>>;

int64_t CheckSize(const DataType &data) {
  int64_t sum = 0;
  for (auto it = data.begin(); it != data.end(); ++it) {
    auto v = std::get<1>(it->second);
    sum += v.size();
  }
  return sum;
}

void unordered_map_erase_test() {
  std::unordered_map<int, int> m;
  m.insert({1, 1});
  m.insert({2, 2});
  m.insert({3, 3});
  m.insert({4, 4});
  m.insert({5, 5});

  // delete
  std::vector<int> vec{1, 2, 3, 7, 8, 9};
  for (auto i : vec) {
    m.erase(i);
  }

  // print
  for (auto i : m) {
    std::cout << i.first << " " << i.second << std::endl;
  }

  // get size
  std::cout << m.size() << std::endl;
}

void test2() {
  std::unordered_map<int, std::vector<int64_t>> m;
  // auto list = {1,2,3,4,5};
  // for (auto i : list) {

  // }
  m[100].push_back(2);

  for (auto i : m) {
    cout << i.first << endl;
    for (auto j : i.second) {
      cout << j << endl;
    }
  }

  m.erase(1000);
  m.erase(100);

  cout << "================" << endl;

  for (auto i : m) {
    cout << i.first << endl;
    for (auto j : i.second) {
      cout << j << endl;
    }
  }
}

/// @brief pair 作为unordered_map的key
struct pair_hash {
  template <class T1, class T2>
  std::size_t operator()(const std::pair<T1, T2> &p) const {
    auto h1 = std::hash<T1>{}(p.first);
    auto h2 = std::hash<T2>{}(p.second);
    // Mainly for demonstration purposes, i.e. works but is overly simple
    // In the real world, use sth. like boost.hash_combine
    return h1 ^ h2;
  }
};

int main(int argc, char *argv[]) {

  std::unordered_map<std::pair<int, int>, int, pair_hash> m;

  m.insert(std::make_pair(std::make_pair(1, 2), 3));

  return 0;
}