/*************************************************************************
        > File Name: open_lock.cpp
        > Author:
        > Mail:
        > Created Time: 2021年03月13日 星期六 14时49分45秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

string minusOne(string s, int i) {
  if (s[i] == '9') {
    s[i] = '0';
  } else {
    s[i] -= 1;
  }
  return s;
}

string plusOne(string s, int i) {
  if (s[i] == '9') {
    s[i] = '0';
  } else {
    s[i] += 1;
  }
  return s;
}

int OpenLock(const std::vector<string> &deadends, const string target) {
  std::set<string> deads;
  for (auto i : deadends) {
    deads.insert(i);
  }
  std::set<string> visited;
  std::queue<string> queue;
  int step = 0;
  queue.push("0000");
  visited.insert("0000");
  while (!queue.empty()) {
    int sz = queue.size();
    for (int i = 0; i < sz; i++) {
      string cur = queue.front();
      queue.pop();
      if (deads.count(cur) == 1)
        continue;
      if (cur.compare(target) == 0)
        return step;
      for (int j = 0; j < 4; j++) {
        string up = plusOne(cur, j);
        if (visited.count(up) == 0) {
          queue.push(up);
          visited.insert(up);
        }
        string down = minusOne(cur, j);
        if (visited.count(down) == 0) {
          queue.push(down);
          visited.insert(down);
        }
      }
    }
    step++;
  }
  return -1;
}

int main() {
  std::vector<string> deadends = {"2382", "5422", "4928", "9983"};
  int steps = OpenLock(deadends, "2345");
  cout << steps << endl;

  return 0;
}
