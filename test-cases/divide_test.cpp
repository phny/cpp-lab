/*************************************************************************
        > File Name: ../divide_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年04月01日 星期三 14时23分21秒
 ************************************************************************/

#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

void test(int64_t n, long *&ids);

int main(int argc, char *argv[]) {

  // long* l = new long[4];
  // long * p = l;
  // for (int64_t i = 0; i < 4; i++) {
  //   test(i, p);
  //   p++;
  // }
  // for (int64_t i = 0; i < 4; i++) {
  //   std::cout << l[i] << std::endl;
  // }

  std::vector<int64_t> v = {1, 2, 3, 4, 5};
  v.resize(2);
  for (auto i : v) {
    cout << i << " ";
  }
}

void test(int64_t n, long *&ids) {
  *ids = n;
  std::cout << n << ":" << *ids << std::endl;
}
