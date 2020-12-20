/*************************************************************************
        > File Name: iterator_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年04月30日 星期四 11时49分20秒
 ************************************************************************/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  std::map<int, int> m1;
  m1[0] = 0;
  m1[1] = 1;
  m1[2] = 2;
  m1[3] = 3;
  m1[4] = 4;
  m1[5] = 5;
  std::vector<int> remove_values = {2, 4, 9, 3, 3};
  for (auto val : remove_values) {
    auto it = m1.find(val);
    if (it == m1.end()) {
      continue;
    }
    m1.erase(it);
  }

  for (auto it = m1.begin(); it != m1.end(); ++it) {
    cout << it->first << ":" << it->second << endl;
  }

  return 0;
}
