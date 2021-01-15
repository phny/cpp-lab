#include <Eigen/Dense>
#include <iostream>

#include <math.h>

using namespace std;
using namespace Eigen;

/// @brief 对矩阵softmax
void SoftMax(Matrix<float, Dynamic, Dynamic, RowMajor> &input,
             Matrix<float, Dynamic, Dynamic, RowMajor> &output) {
  // find max element
  float max = input(0, 0);
  for (size_t i = 0; i < input.rows(); i++) {
    for (size_t j = 0; j < input.cols(); j++) {
      if (input(i, j) > max)
        max = input(i, j);
    }
  }
  // sub max
  Matrix<float, Dynamic, Dynamic, RowMajor> tmp(input.rows(), input.cols());
  float sum = input(0, 0) - input(0, 0);
  for (size_t i = 0; i < input.rows(); i++) {
    for (size_t j = 0; j < input.cols(); j++) {
      tmp(i, j) = exp(input(i, j) - max);
      sum += tmp(i, j);
    }
  }
  // set output
  for (size_t i = 0; i < input.rows(); i++) {
    for (size_t j = 0; j < input.cols(); j++) {
      output(i, j) = tmp(i, j) / sum;
    }
  }
}

void MatrixMul() {
  Matrix<float, Dynamic, Dynamic, RowMajor> input(2, 3);
  input(0, 0) = 1;
  input(0, 1) = 2;
  input(0, 2) = 3;
  input(1, 0) = 4;
  input(1, 1) = 5;
  input(1, 2) = 6;

  Matrix<float, Dynamic, Dynamic, RowMajor> input1(3, 2);
  input1(0, 0) = 1;
  input1(0, 1) = 2;
  input1(1, 0) = 3;
  input1(1, 1) = 4;
  input1(2, 0) = 5;
  input1(2, 1) = 6;

  cout << (input * input1) << endl;
}

void MatrixSoftMax() {
  Matrix<float, Dynamic, Dynamic, RowMajor> input(2, 3);
  Matrix<float, Dynamic, Dynamic, RowMajor> output(2, 3);

  input(0, 0) = 1;
  input(0, 1) = 2;
  input(0, 2) = 3;
  input(1, 0) = 4;
  input(1, 1) = 5;
  input(1, 2) = 6;

  cout << input << endl;
  SoftMax(input, output);
  cout << output << endl;
  cout << input << endl;
}

int main(int argc, char *argv[]) {

  MatrixSoftMax();

  // MatrixMul();

  return 0;
}