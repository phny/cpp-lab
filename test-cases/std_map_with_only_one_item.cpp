/*************************************************************************
        > File Name: std_map_with_only_one_item.cpp
        > Author:
        > Mail:
        > Created Time: 2020年06月30日 星期二 11时10分57秒
 ************************************************************************/

#include <iostream>
#include <map>

using namespace std;

int main() {
  std::map<int, int> m;
  if (m.find(22) == m.end()) {
    std::cout << "not found 22 in m " << std::endl;
  }

  m.insert({100, 1000});

  int ret = m.begin()->first;
  std::cout << ret << std::endl;

  std::map<int, int> m2;
  std::cout << m2.begin()->first << std::endl;

  return 0;
}
