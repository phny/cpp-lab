/*************************************************************************
        > File Name: ../random_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年03月26日 星期四 15时45分26秒
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

void RandomGenerateFeatureIds(int64_t start, int64_t end, std::vector<int64_t> &entity_ids, int a, int b) {
  srand((unsigned)time(NULL));
  int64_t feature_ids_len = (rand() % (b - a + 1)) + a;
  for (int i = 0; i < feature_ids_len; i++) {
    int64_t num = (rand() % (end - start + 1)) + start;
    entity_ids.push_back(num);
  }
}

int main() {
  std::vector<int64_t> v;
  RandomGenerateFeatureIds(0, 100, v, 1, 5);
  for (auto& i : v) {
    cout << i << endl;
  }
}
