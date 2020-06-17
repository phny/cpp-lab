/*************************************************************************
        > File Name: ../../test-cases/vector_sum.cpp
        > Author:
        > Mail:
        > Created Time: 2020年06月13日 星期六 16时47分49秒
 ************************************************************************/

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  vector<float> v = {0.1, 0.2, 0.3, 30, 90.9};
  float sum = std::accumulate(v.begin(), v.end(), 0.0);
  cout << sum << endl;
}
