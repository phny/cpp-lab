/*************************************************************************
        > File Name: map_map_insert_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年05月22日 星期五 22时25分58秒
 ************************************************************************/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  map<int64_t, int64_t> m;
  map<int64_t, int64_t> m1;
  m[1] = 1;
  m[2] = 2;
  m[3] = 3;

  m1[4] = 4;
  m1[5] = 5;
  m1[6] = 6;

  m.insert(m1.begin(), m1.end());

  for (auto &i : m) {
    cout << i.first << ": " << i.second << endl;
  }

  return 0;
}
