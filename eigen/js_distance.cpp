#include <iostream>
#include <limits>
#include <math.h>
#include <vector>

#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

float JensenshannonDistance(const float *p, const float *q, const int n) {
  float MAX = std::numeric_limits<float>::max();
  int i;
  float s = 0.0;
  float p_sum = 0.0;
  float q_sum = 0.0;

  for (i = 0; i < n; ++i) {
    if (p[i] < 0.0 || q[i] < 0.0)
      return MAX;
    p_sum += p[i];
    q_sum += q[i];
  }

  if (p_sum == 0.0 || q_sum == 0.0)
    return MAX;

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

Matrix<float, Dynamic, Dynamic, RowMajor>
JensenshannonDistance(Matrix<float, Dynamic, Dynamic, RowMajor> &m1,
                      Matrix<float, Dynamic, Dynamic, RowMajor> &m2) {
  Matrix<float, Dynamic, Dynamic, RowMajor> res(m1.rows(), m2.rows());
  for (size_t i = 0; i < m1.rows(); ++i) {
    for (size_t j = 0; j < m2.rows(); ++j) {
      res(i, j) =
          JensenshannonDistance(m1.row(i).data(), m2.row(j).data(), m1.cols());
    }
  }

  return res;
}

int main(int argc, char *argv[]) {
  std::vector<float> v1 = {0.8, 0.1, 0.1};
  std::vector<float> v2 = {0.7, 0.2, 0.1};
  // 两个向量的JS散度计算
  cout << JensenshannonDistance(v1.data(), v2.data(), v1.size()) << endl;

  cout << "------------------------------" << endl;

  // 矩阵的JS散度计算
  Matrix<float, Dynamic, Dynamic, RowMajor> m1(2, 3);
  Matrix<float, Dynamic, Dynamic, RowMajor> m2(2, 3);

  m1(0, 0) = 0.8;
  m1(0, 1) = 0.1;
  m1(0, 2) = 0.1;
  m1(1, 0) = 0.2;
  m1(1, 1) = 0.5;
  m1(1, 2) = 0.3;

  m2(0, 0) = 0.7;
  m2(0, 1) = 0.2;
  m2(0, 2) = 0.1;
  m2(1, 0) = 0.4;
  m2(1, 1) = 0.4;
  m2(1, 2) = 0.2;

  auto res = JensenshannonDistance(m1, m2);
  cout << res << endl;

  return 0;
}