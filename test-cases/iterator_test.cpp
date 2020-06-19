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
  std::vector<int> v1 = {1, 2, 3, 4, 5};
  auto it = v1.begin();
  std::cout << *(it + 2) << std::endl;

  std::map<int, int> m1;
  m1[0] = 0;
  m1[1] = 1;
  m1[2] = 2;
  m1[3] = 3;
  auto m_it = m1.begin();
  // std::cout << *(m_it + 2).first << std::endl; invalid
  for (int i = 0; i < 2; i++) {
    m_it++;
  }
  std::cout << "first: " << m_it->first << "second: " << m_it->second
            << std::endl;
  return 0;
}
