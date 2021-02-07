#include <algorithm>
#include <array>
#include <functional>
#include <iostream>

int main() {
  std::array<int, 10> s{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};

  std::partial_sort(
      s.begin(), s.begin() + 5, s.end(),
      [](const int left, const int right) { return left > right; });
  for (int a : s) {
    std::cout << a << " ";
  }
  std::cout << std::endl;
}