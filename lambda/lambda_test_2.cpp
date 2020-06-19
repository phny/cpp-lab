/*************************************************************************
> File Name: lambda_test_2.cpp
> Author:
> Mail:
> Created Time: 2020年04月24日 星期五 14时08分36秒
************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main() {
  // 通过 lambda 表达式来初始化 vector
  int nums = 10;
  std::vector<int> ret = [nums] {
    std::vector<int> v;
    v.resize(10);
    for (int i = 0; i < nums; i++) {
      v[i] = i * i;
    }
    return v;
  }();

  for (auto &i : ret) {
    cout << i << endl;
  }
  return 0;
}
