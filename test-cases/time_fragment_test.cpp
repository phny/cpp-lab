/*************************************************************************
        > File Name: time_fragment_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年05月22日 星期五 09时23分22秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

void EntitySetFragmentByTime(const vector<int64_t>& v1, int64_t time_step,
                             vector<vector<int64_t>>& output) {
  // 没有需要分片的特征直接返回
  if (v1.size() < 1) {
    return;
  }

  int64_t entity_num = v1.size();
  int64_t start_timestamp = v1[0];
  int64_t end_timestamp = v1[entity_num - 1];
  int64_t next_fragment_point = start_timestamp + time_step;
  int fragments_ind = 0;
  vector<vector<int64_t>> tmp(1);

  for (int32_t i = 0; i < entity_num; i++) {
    int64_t entity = v1[i];
    if (entity < next_fragment_point) {
      tmp[fragments_ind].push_back(entity);
    } else {
      fragments_ind++;
      next_fragment_point = std::min(next_fragment_point + time_step, end_timestamp);
      tmp.resize(tmp.size() + 1);
      tmp[fragments_ind].push_back(entity);
    }
  }
  // 交换结果到输出空间
  output.swap(tmp);
}

int main() {
  vector<int64_t> v1;
  int64_t start_timestamp = 1591200000;
  for (int i = 0; i < 86400; i++) {
      v1.push_back(start_timestamp + i);
  }
  // 按照时间进行分片  
  vector<vector<int64_t>> result;
  EntitySetFragmentByTime(v1, 10000, result);
  
  // 输出每个分片结果的大小
  for (int i = 0; i < result.size(); i++) {
    cout << "fragment " << i << ": " << result[i].size() << endl;
  }
  return 0;
}
