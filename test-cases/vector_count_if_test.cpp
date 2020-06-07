/*************************************************************************
        > File Name: vector_count_if_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年05月11日 星期一 16时40分08秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  uint32_t fixed_num = 4;
  int32_t ret = std::count_if(
      v.begin(), v.end(), [fixed_num](uint32_t i) { return i < fixed_num; });

  std::cout << ret << std::endl;

  return 0;
}
