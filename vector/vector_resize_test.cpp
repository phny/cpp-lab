/*************************************************************************
        > File Name: vector_resize_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年05月11日 星期一 10时06分55秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v = {1, 2, 3, 4, 5};
  vector<int> v2 = {6, 7, 8, 9, 10};

  v.resize(3);

  v.insert(v.end(), v2.begin(), v2.end());

  std::cout << "v.size: " << v.size() << endl;
  for (auto i : v) {
    cout << i << " ";
  }

  cout << endl;

  return 0;
}
