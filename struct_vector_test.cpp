/*************************************************************************
        > File Name: struct_vector_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年04月17日 星期五 09时48分13秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

struct Association {
  int64_t id;  ///< 匹配的id
  float score; ///< 匹配的分数
};

int main() {
  vector<Association> v;
  v.push_back({1, 0.99});
  v.push_back({2, 0.99});
  v.push_back({3, 0.99});

  for (auto &item : v) {
    cout << item.id << ":" << item.score << endl;
  }
  return 0;
}
