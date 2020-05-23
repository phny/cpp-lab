/*************************************************************************
        > File Name: time_fragment_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年05月22日 星期五 09时23分22秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

void EntitySetFragmentByTime(const vector<int>& v1, int time_step,
                             vector<vector<int>>& output) {
  // 没有需要分片的特征直接返回
  if (v1.size() < 1) {
    return;
  }

  int entity_num = v1.size();
  int start_timestamp = v1[0];
  int end_timestamp = v1[entity_num - 1];
  int next_fragment_point = start_timestamp + time_step;
  int fragments_ind = 0;
  vector<vector<int>> tmp(1);

  for (int32_t i = 0; i < entity_num; i++) {
    int entity = v1[i];
    if (entity < next_fragment_point) {
      tmp[fragments_ind].push_back(entity);
    } else {
      fragments_ind++;
      next_fragment_point =
          std::min(next_fragment_point + time_step, end_timestamp);
      // tmp.push_back(new vector<int>());
      tmp.resize(tmp.size() + 1);
      tmp[fragments_ind].push_back(entity);
    }
  }
  output.swap(tmp);
}

int main() {
  vector<int> v1 = {1587519607, 1587519622, 1587519700, 1587600000, 1587601000,
                    1587602000, 1587603000, 1587604000, 1587608000, 1587609000,
                    1588600000, 1589600000, 1687600000};
  // vector<int> v1 = {156888934};
  // vector<int> v1 = {};
  vector<vector<int>> result;
  EntitySetFragmentByTime(v1, 17200, result);
  for (auto& fragment_vec : result) {
    for (auto& entity : fragment_vec) {
      cout << entity << " ";
    }
    cout << endl;
  }
  return 0;
}
