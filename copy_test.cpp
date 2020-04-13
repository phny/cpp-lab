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
  std::string a = "skkkkkdd";
  std::string b;
  std::copy(a.begin(), a.end(), b.begin());

  std::cout << b << std::endl;

  return 0;
}
