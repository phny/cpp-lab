#include <Eigen/Dense>
#include <iostream>
#include <vector>

#include <math.h>

using namespace std;
using namespace Eigen;

using namespace std;
using namespace Eigen;

template <typename T>
void VectorSoftMax(const std::vector<T> &v, std::vector<T> &s) {
  auto loge = [](T num) { return exp(num); };

  T sum = 0;
  std::transform(v.begin(), v.end(), std::back_inserter(s), loge);
  sum = accumulate(s.begin(), s.end(), sum);
  for (size_t i = 0; i < s.size(); ++i) {
    s.at(i) /= sum;
  }
}

template <typename T>
Matrix<T, Dynamic, Dynamic>
DefaultSoftMax(const Matrix<T, Dynamic, Dynamic> &input) {
  Matrix<T, Dynamic, Dynamic> res(input.rows(), input.cols());
  T max = input(0, 0);
  for (size_t i = 0; i < input.rows(); i++) {
    for (size_t j = 0; j < input.cols(); j++) {
      if (input(i, j) > max)
        max = input(i, j);
    }
  }
  Matrix<float, Dynamic, Dynamic> tmp(input.rows(), input.cols());
  float sum = 0.0f;
  for (size_t i = 0; i < input.rows(); i++) {
    for (size_t j = 0; j < input.cols(); j++) {
      tmp(i, j) = exp(input(i, j) - max);
      sum += tmp(i, j);
    }
  }
  for (size_t i = 0; i < input.rows(); i++) {
    for (size_t j = 0; j < input.cols(); j++) {
      res(i, j) = tmp(i, j) / sum;
    }
  }

  return res;
}

template <typename T>
Matrix<T, Dynamic, Dynamic>
RowSoftMax(const Matrix<T, Dynamic, Dynamic> &input) {
  Matrix<T, Dynamic, Dynamic> res(input.rows(), input.cols());
  for (size_t i = 0; i < input.rows(); i++) {
    auto row = input.row(i);
    std::vector<T> src;
    for (size_t j = 0; j < input.cols(); j++) {
      src.emplace_back(row(j));
    }
    std::vector<T> dst;
    VectorSoftMax(src, dst);
    for (size_t j = 0; j < res.cols(); j++) {
      res.row(i)(j) = dst[j];
    }
  }

  return res;
}

template <typename T>
Matrix<T, Dynamic, Dynamic>
ColSoftMax(const Matrix<T, Dynamic, Dynamic> &input) {
  Matrix<T, Dynamic, Dynamic> res(input.rows(), input.cols());
  for (size_t i = 0; i < input.cols(); i++) {
    auto col = input.col(i);
    std::vector<T> src;
    for (size_t j = 0; j < input.rows(); j++) {
      src.emplace_back(col(j));
    }
    std::vector<T> dst;
    VectorSoftMax(src, dst);
    for (size_t j = 0; j < res.rows(); j++) {
      res.col(i)(j) = dst[j];
    }
  }

  return res;
}

/// @brief 计算矩阵的softmax，等效与scipy的softmax函数
template <typename T>
Matrix<T, Dynamic, Dynamic> SoftMax(const Matrix<T, Dynamic, Dynamic> &input,
                                    int32_t axis = -1) {
  Matrix<T, Dynamic, Dynamic> res;
  if (axis == -1) {
    res = DefaultSoftMax(input);
  } else if (axis == 1) {
    res = RowSoftMax(input);
  } else if (axis == 0) {
    res = ColSoftMax(input);
  } else {
    std::cout << "axis: " << axis << " error" << std::endl;
  }

  return res;
}

void MatrixSoftMax() {
  MatrixXf input(2, 3);
  input(0, 0) = 1;
  input(0, 1) = 2;
  input(0, 2) = 3;
  input(1, 0) = 2;
  input(1, 1) = 5;
  input(1, 2) = 8;

  cout << input << endl;
  MatrixXf res = SoftMax(input);

  cout << "default: \n" << res << endl;
  res = SoftMax(input, 0);
  cout << "axis = 0: \n" << res << endl;
  res = SoftMax(input, 1);
  cout << "axis = 1: \n" << res << endl;
}

int main(int argc, char *argv[]) {
  MatrixSoftMax();

  return 0;
}