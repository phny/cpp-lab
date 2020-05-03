/*************************************************************************
        > File Name: map_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年04月23日 星期四 10时43分35秒
 ************************************************************************/

#include <iostream>
#include <map>

using namespace std;

int main() {
  map<int, int> m;
  m.insert(make_pair(2, 2));
  m.insert(make_pair(1, 1));
  m.insert(make_pair(3, 3));
  m.insert(make_pair(5, 5));

  for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
    cout << it->first << it->second << endl;
  }
}
