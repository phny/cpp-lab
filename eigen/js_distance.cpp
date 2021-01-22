#include <iostream>
#include <limits>
#include <math.h>
#include <vector>

#include <Eigen/Core>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

template <typename T>
T JensenshannonDistance(const T *p, const T *q, const int n) {
  T MAX = std::numeric_limits<T>::max();
  int i;
  T s = 0.0;
  T p_sum = 0.0;
  T q_sum = 0.0;

  for (i = 0; i < n; ++i) {
    if (p[i] < 0.0 || q[i] < 0.0)
      return MAX;
    p_sum += p[i];
    q_sum += q[i];
  }

  if (p_sum == 0.0 || q_sum == 0.0)
    return MAX;

  for (i = 0; i < n; ++i) {
    const T p_i = p[i] / p_sum;
    const T q_i = q[i] / q_sum;
    const T m_i = (p_i + q_i) / 2.0;
    if (p_i > 0.0)
      s += p_i * log(p_i / m_i);
    if (q_i > 0.0)
      s += q_i * log(q_i / m_i);
  }

  return sqrt(s / 2.0);
}

template <typename T>
Matrix<T, Dynamic, Dynamic>
JensenshannonDistance(const Matrix<T, Dynamic, Dynamic> &m1,
                      const Matrix<T, Dynamic, Dynamic> &m2) {
  Matrix<T, Dynamic, Dynamic> res(m1.rows(), m2.rows());
  std::vector<T> src, dst;
  for (size_t i = 0; i < m1.rows(); ++i) {
    for (size_t x = 0; x < m1.cols(); x++) {
      src.emplace_back(m1(i, x));
    }
    for (size_t j = 0; j < m2.rows(); ++j) {
      for (size_t x = 0; x < m2.cols(); x++) {
        dst.emplace_back(m2(j, x));
      }
      res(i, j) = JensenshannonDistance(src.data(), dst.data(), m1.cols());
      src.clear();
      dst.clear();
    }
  }

  return res;
}

int main(int argc, char *argv[]) {
  std::vector<float> v1 = {0.8, 0.1, 0.1};
  std::vector<float> v2 = {0.4, 0.4, 0.2};
  // 两个向量的JS散度计算
  cout << JensenshannonDistance(v1.data(), v2.data(), v1.size()) << endl;

  cout << "------------------------------" << endl;

  // 矩阵的JS散度计算
  MatrixXf m1(2, 3);
  MatrixXf m2(2, 3);

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

  MatrixXf res = JensenshannonDistance(m1, m2);
  cout << res << endl;
  cout << "use 1 - res" << endl;
  for (size_t i = 0; i < res.rows(); i++) {
    for (size_t j = 0; j < res.cols(); j++) {
      res(i, j) = 1 - res(i, j);
    }
  }
  cout << res << endl;

  return 0;
}