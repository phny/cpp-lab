#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T> std::vector<size_t> ArgSort(const std::vector<T> &vec) {
  // 建立下标数组
  std::vector<size_t> idx(vec.size());
  std::iota(idx.begin(), idx.end(), 0);
  // 调用sort函数，匿名函数自动捕获待排序数组(从小到大)
  std::sort(idx.begin(), idx.end(),
            [&vec](T i1, T i2) { return vec[i1] < vec[i2]; });
  return idx;
}

int main(int argc, char *argv[]) {
  std::vector<int64_t> v = {9, 3, 4, 0, 10};
  std::vector<size_t> idx = ArgSort(v);

  for (auto i : idx) {
    cout << i << endl;
  }
  for (size_t i = 0; i < idx.size(); i++) {
    cout << v[idx[i]] << endl;
  }

  return 0;
}