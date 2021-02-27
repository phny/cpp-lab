#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

void print_container(const std::vector<int> &c) {
  for (auto &i : c) {
    std::cout << i << " ";
  }
  std::cout << '\n';
}

void test(std::vector<std::vector<int64_t>> &merge_ids) {
  std::map<uint32_t, std::vector<int64_t>> clusters = {{{1, {1}}, {2, {2}}}};

  // 去重
  auto iter = clusters.begin();
  while (iter != clusters.end()) {
    std::vector<int64_t> &cluster = iter->second;
    std::sort(cluster.begin(), cluster.end());
    auto remove_iter = std::unique(cluster.begin(), cluster.end());
    cluster.erase(remove_iter, cluster.end());

    merge_ids.push_back(cluster);
    iter++;
  }
}

int main() {
  std::vector<int> c{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  // print_container(c);

  // c.erase(c.begin());
  // print_container(c);

  // auto it = c.erase(c.begin(), c.begin()+5);
  // std::cout << c.size() << std::endl;
  // std::cout << c.end() - it << std::endl;
  // c.resize(c.end() - it);
  // print_container(c);

  // Erase all even numbers (C++11 and later)
  // for (auto it = c.begin(); it != c.end(); ) {
  //     if (*it % 2 == 0) {
  //         it = c.erase(it);
  //     } else {
  //         ++it;
  //     }
  // }
  // print_container(c);

  // 把子中心分类label映射到原始聚类label,统计可以合并的类簇

  std::vector<std::vector<int64_t>> merge_ids;
  test(merge_ids);
  for (auto v : merge_ids) {
    for (auto i : v) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
}
