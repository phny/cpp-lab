#include <iostream>
#include <map>
#include <unordered_map>
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
}

int main(int argc, char *argv[]) {

  // DataType m;

  // m.insert(std::make_pair(1, std::make_tuple(1, std::vector<int>{1, 2, 3})));
  // m.insert(std::make_pair(2, std::make_tuple(1, std::vector<int>{4, 5, 6})));
  // m.insert(std::make_pair(3, std::make_tuple(1, std::vector<int>{7, 8, 9})));
  // m.insert(std::make_pair(4, std::make_tuple(1, std::vector<int>{10, 11,
  // 12})));

  // int64_t ret = CheckSize(m);
  // int64_t ret1 = CheckSize(m);
  // int64_t ret2 = CheckSize(m);

  // cout << ret << ":" << ret1 << ":" << ret2 << endl;

  unordered_map_erase_test();

  return 0;
}