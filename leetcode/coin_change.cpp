#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int dp(const std::vector<int> &coins, int amount) {
  if (amount < 0)
    return -1;
  if (amount == 0)
    return 0;

  int INF = std::numeric_limits<int>::max();
  int res = INF;

  for (auto c : coins) {
    int subproblem = dp(coins, amount - c);
    if (subproblem == -1)
      continue;
    res = std::min(res, subproblem + 1);
  }
  return res != INF ? res : INF;
}

int main(int argc, char *argv[]) {
  std::vector<int> coins = {1, 2, 5};

  int res = dp(coins, 21);

  cout << res << endl;

  return 0;
}
