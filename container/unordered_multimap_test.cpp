#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int helper(std::unordered_map<int, int> &m, int n) {
  // base case
  if (n == 1 || n == 2)
    return 1;
  // 已经计算过
  if (m.find(n) != m.end()) {
    return m.at(n);
  }
  m.insert({n, helper(m, n - 1) + helper(m, n - 2)});
  return m.at(n);
}

int fib2(int N) {
  if (N < 1)
    return 0;
  // 备忘录全初始化为 0
  std::unordered_map<int, int> m;
  // 进行带备忘录的递归
  return helper(m, N);
}

int main(int argc, char *argv[]) {
  int b = fib2(40);

  cout << b << endl;

  return 0;
}
