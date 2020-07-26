#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  std::vector<int> nb_left;
  std::vector<std::vector<int>> body_cluster;
  std::vector<int> v = {-1, -1, -1, 1, 1, 2, 2, 2, 3, 3, 4, 5, 5, 5, 5};

  int i = 0;
  for (; i < v.size(); i++) {
    if (v[i] < 0) {
      // 记录 nb_left
      nb_left.push_back(v[i]);
      continue;
    }
    break;
  }

  int start = i;         // 起始探测点
  int end = start + 1;   // 结束探测点
  int target = v[start]; // 临时目标

  for (int index = end; index < v.size(); index++) {
    if (v[index] != target) {
      end = index;
      std::vector<int> tmp(v.begin() + start, v.begin() + end);
      body_cluster.push_back(tmp);

      start = end;
      end = index + 1;
      target = v[start];

      continue;
    }
    end++;
  }
  // 添加最后的数据
  std::vector<int> last(v.begin() + start, v.begin() + end);
  body_cluster.push_back(last);

  // 输出结果
  for (auto &v : body_cluster) {
    for (auto &i : v) {
      cout << i << " ";
    }
    cout << endl;
  }

  return 0;
}