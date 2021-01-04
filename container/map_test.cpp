/*************************************************************************
        > File Name: map_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年04月23日 星期四 10时43分35秒
 ************************************************************************/

#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

void MapTest() {
  std::map<std::tuple<int32_t, int32_t>, float> m;
  m.insert({std::make_tuple(1, 2), 100});
  m.insert({std::make_tuple(2, 3), 200});
  m.insert({std::make_tuple(3, 4), 300});
  m.insert({std::make_tuple(4, 5), 400});
  m.insert({std::make_tuple(5, 6), 500});

  if (m.find(std::make_tuple(1, 2)) != m.end()) {
    std::cout << m[std::make_tuple(1, 2)] << std::endl;
  }

  std::vector<std::tuple<int32_t, int32_t, float>> t = {
      std::make_tuple(1, 2, 1.2), std::make_tuple(2, 2, 2.2),
      std::make_tuple(3, 2, 3.2)};
}

void MapTest2() {
  std::map<int64_t, std::pair<int64_t, int64_t>> m;
  m.insert({2, std::make_pair(2, 3)});
  for (auto it = m.begin(); it != m.end(); ++it) {
    cout << it->first << ":" << it->second.first << it->second.second << endl;
  }
}

void MapTest3() {
  std::unordered_map<int64_t, int32_t> m;
  std::vector<int64_t> cluster_ids = {1, 1, 2, 3, 4, 4, 4, 5, 5, 6};
  for (size_t i = 0; i < cluster_ids.size(); i++) {
    if (m.find(cluster_ids[i]) == m.end()) {
      m.insert({cluster_ids[i], 1});
    } else {
      m[cluster_ids[i]]++;
    }
  }

  for (auto it = m.begin(); it != m.end(); ++it) {
    cout << it->first << ":" << it->second << endl;
  }
}

int main() {
  // MapTest2();

  MapTest3();
  return 0;
}
