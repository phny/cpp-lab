#include <iostream>
#include <vector>

using namespace std;

std::vector<int32_t> TwoSum(const std::vector<int32_t> &v, int32_t k) {
  int32_t l = 0;
  int32_t r = v.size() - 1;

  while (l < r) {
    int32_t target = v[l] + v[r];
    if (target == k) {
      break;
    }
    if (target < k) {
      l++;
    } else {
      --r;
    }
  }
  return std::vector<int32_t>{l, r};
}

int main(int argc, char *argv[]) {

  std::vector<int32_t> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto ret = TwoSum(v, 6);

  for (auto i : ret) {
    cout << i << endl;
  }

  return 0;
}