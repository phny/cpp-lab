
// remove_if example
#include <algorithm> // std::remove_if
#include <iostream>  // std::cout
#include <vector>

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  auto it_end = std::remove_if(v.begin(), v.end(), [](const int i) {
    return i < 2;
  }); // 2 4 6 8 ? ? ? ? ?

  v.resize(it_end - v.begin());

  std::cout << "after remove, the range contains: \n";
  for (auto i : v) {
    std::cout << i << std::endl;
  }

  return 0;
}
