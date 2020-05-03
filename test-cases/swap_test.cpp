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
  return 0;
}
