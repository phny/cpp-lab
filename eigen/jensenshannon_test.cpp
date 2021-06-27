#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

float JensenshannonDistance(const float *p, const float *q, const int n) {
  int i;
  float s = 0.0;
  float p_sum = 0.0;
  float q_sum = 0.0;

  for (i = 0; i < n; ++i) {
    if (p[i] < 0.0 || q[i] < 0.0)
      return HUGE_VAL;
    p_sum += p[i];
    q_sum += q[i];
  }

  if (p_sum == 0.0 || q_sum == 0.0)
    return HUGE_VAL;

  for (i = 0; i < n; ++i) {
    const float p_i = p[i] / p_sum;
    const float q_i = q[i] / q_sum;
    const float m_i = (p_i + q_i) / 2.0;
    if (p_i > 0.0)
      s += p_i * log(p_i / m_i);
    if (q_i > 0.0)
      s += q_i * log(q_i / m_i);
  }

  return sqrt(s / 2.0);
}

int main(int argc, char *argv[]) {
  vector<float> v1 = {1, 2, 3, 4, 5};
  vector<float> v2 = {12, 22, 32, 44, 5};

  float res = JensenshannonDistance(v1.data(), v2.data(), v2.size());
  cout << res << endl;

  return 0;
}