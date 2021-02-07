/*************************************************************************
        > File Name: ../copy_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年04月03日 星期五 18时01分41秒
 ************************************************************************/

// copy algorithm example
#include <algorithm> // std::copy
#include <iostream>  // std::cout
#include <vector>    // std::vector

int main() {
  std::vector<int> v1{1, 2, 3};
  std::vector<int> v2{4, 5, 6};
  std::vector<int> dst;
  std::copy(v1.begin(), v1.end(), std::back_inserter(dst));
  std::copy(v2.begin(), v2.end(), std::back_inserter(dst));

  for_each(dst.begin(), dst.end(), [](const int i) { std::cout << i << " "; });
  std::cout << std::endl;

  return 0;
}
