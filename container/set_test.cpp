/*************************************************************************
        > File Name: set_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年04月01日 星期三 09时42分32秒
 ************************************************************************/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#include <set>
int main() {
  freopen("in.txt", "r", stdin);
  set<int> x1, x2, x;
  x1.insert(1);
  x1.insert(2);
  x2.insert(3);
  x2.insert(2);
  //交集
  set_intersection(x1.begin(), x1.end(), x2.begin(), x2.end(),
                   inserter(x, x.begin()));
  //前四个参数为两个集合的开始和结束位置迭代器，最后一个迭代器为结果集合的插入迭代器
  set<int>::iterator it = x.begin();

  while (it != x.end()) {
    cout << *it << endl;
    it++;
  }
  //并集
  set_union(x1.begin(), x1.end(), x2.begin(), x2.end(), inserter(x, x.begin()));
  it = x.begin();

  while (it != x.end()) {
    cout << *it << endl;
    it++;
  }
  //差集
  x.clear();
  set_difference(x1.begin(), x1.end(), x2.begin(), x2.end(),
                 inserter(x, x.begin()));
  // x1相对于x2的差集
  it = x.begin();
  while (it != x.end()) {
    cout << *it << endl;
    it++;
  }
  return 0;
}
