/*************************************************************************
        > File Name: swap_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年04月17日 星期五 11时09分20秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v1 = {1, 2, 3};
  vector<int> v2;

  std::swap(v1, v2);

  cout << "v1" << endl;
  for (auto i : v1) {
    cout << i << endl;
  }

  cout << "v2" << endl;
  for (auto i : v2) {
    cout << i << endl;
  }

  // swap test 2
  std::vector<int> v3 = {1, 2, 3};
  std::vector<int> v4;
  v4.swap(v3);
  std::cout << "v3:" << std::endl;
  for (auto i : v3) {
    std::cout << i << endl;
  }
  std::cout << "v4:" << std::endl;
  for (auto i : v4) {
    std::cout << i << endl;
  }
  // swap test 3
  int i1 = 100;
  int i2 = 200;
  return 0;
}
