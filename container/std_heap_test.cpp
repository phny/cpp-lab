#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

void print(std::string text, std::vector<int> const &v = {}) {
  std::cout << text << ": ";
  for (const auto &e : v)
    std::cout << e << ' ';
  std::cout << '\n';
}

int main() {
  print("Max heap");

  std::vector<int> v{3, 2, 4, 1, 5, 9};
  print("initially, v", v);

  std::make_heap(v.begin(), v.end());
  print("after make_heap, v", v);

  // moves the largest to the end
  std::pop_heap(v.begin(), v.end());
  print("after pop_heap, v", v);

  auto top = v.back();
  v.pop_back();
  print("former top element", {top});
  print("after removing the former top element, v", v);

  print("\nMin heap");

  std::vector<int> v1{3, 2, 4, 1, 5, 9};
  print("initially, v1", v1);

  std::make_heap(v1.begin(), v1.end(), std::greater<int>());
  print("after make_heap, v1", v1);

  std::pop_heap(v1.begin(), v1.end(), std::greater<int>());
  print("after pop_heap, v1", v1);

  auto top1 = v1.back();
  v1.pop_back();
  print("former top element", {top1});
  print("after removing the former top element, v1", v1);

  v1.push_back(100);
  std::make_heap(v1.begin(), v1.end());
  print("after push_heap", v1);
}