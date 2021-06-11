/*************************************************************************
        > File Name: ../random_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年03月26日 星期四 15时45分26秒
 ************************************************************************/

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <random>
#include <set>
#include <time.h>
#include <vector>

#include "utils/random_utils.hpp"

using namespace std;

/// @brief 随机生成Cluster的 feature_ids
/// @param[in] start 随机数的最小值
/// @param[in] end 随机数的最大值
/// @param[out] entity_ids 产生随机数存放容器
/// @param[in] a 随机数个数起始值
/// @param[in] b 随机数个数结束值
void RandomGenerateFeatureIds(int64_t start, int64_t end,
                              std::vector<int64_t> &entity_ids, int a, int b) {
  srand((unsigned)time(NULL));
  int64_t feature_ids_len = (rand() % (b - a + 1)) + a;
  for (int i = 0; i < feature_ids_len; i++) {
    int64_t num = (rand() % (end - start + 1)) + start;
    entity_ids.push_back(num);
  }
}

void RandomGenerateFeatureIds_2(int64_t start, int64_t end,
                                std::vector<int64_t> &entity_ids,
                                int random_number_num_start_ind,
                                int random_number_num_end_ind) {
  std::random_device rd;
  std::default_random_engine e(rd());
  std::uniform_int_distribution<> u_1(random_number_num_start_ind,
                                      random_number_num_end_ind);
  std::uniform_int_distribution<> u(start, end);

  int rand_number_num = u_1(e);

  for (size_t i = 0; i < rand_number_num; i++) {
    entity_ids.push_back(u(e));
  }
}

int main() {
  // std::vector<int64_t> v;
  // RandomGenerateFeatureIds(0, 100, v, 10000, 10000);
  // std::set<int64_t> s;
  // for (auto& i : v) {
  //  s.insert(i);
  //}
  // cout << s.size() << endl;

  // vector<int64_t> v2;
  // RandomGenerateFeatureIds_2(1, RAND_MAX, v2, 1, 100);
  // cout << "random number nums: " << v2.size() << endl;
  // std::set<int64_t> s;
  // for (auto &num : v2) {
  //   s.insert(num);
  //   cout << num << endl;
  // }
  // cout << "different nums: " << s.size() << endl;

  // std::vector<int64_t> res;
  // for (size_t i = 0; i < 1000; i++) {
  //   int64_t n = RandomGenerateInteger(0, 100);
  //   res.push_back(n);
  // }

  // for (auto i : res) {
  //   std::cout << i << std::endl;
  // }

  // for (size_t i = 0; i < 1000; i++) {
  //   int64_t region_id = ConstructRegionID();
  //   int64_t camera_id = ConstructCameraID();
  //   int64_t timestamp = ConstructTimestamp();
  //   int64_t seq = ConstructSeq();
  //   cout << "region_id: " << region_id << ", camera_id: " << camera_id << ",
  //   timestamp: " << timestamp << ", seq: " << seq << endl; auto feature_id =
  //   ConstructFeatureID(region_id, camera_id, timestamp, seq); std::cout <<
  //   feature_id << std::endl;
  // }

  std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto it = std::min_element(v.begin(), v.end());
  v.erase(it);
  // v.erase(v.begin() + 1);
  cout << "v.size: " << v.size() << endl;
  for (auto i : v) {
    cout << i << endl;
  }

  return 0;
}
