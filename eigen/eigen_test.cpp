#include <iostream>
#include <unordered_map>
#include <vector>

#include <Eigen/Core>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

template <typename T>
std::vector<std::vector<size_t>> SimilarityToEdge(const MatrixBase<T> &input,
                                                  const float threshold) {
  std::vector<std::vector<size_t>> res;
  for (size_t i = 0; i < input.rows(); i++) {
    for (size_t j = 0; j < input.cols(); j++) {
      if (input(i, j) > threshold) {
        res.emplace_back(std::vector<size_t>{i, j});
      }
    }
  }

  return res;
}

std::unordered_map<int64_t, std::vector<int64_t>>
EdgeToConnectedGraph(const std::vector<std::vector<size_t>> &edages,
                     const int num_cluster) {}

void Test1() {
  MatrixXf input(3, 3);
  input << 1, 0.55806044, 0.6348896, 0.55806044, 1, 0.91158394, 0.6348896,
      0.91158394, 1;

  cout << input.rows() << " " << input.cols() << endl;

  MatrixXf l = input.triangularView<StrictlyUpper>();
  cout << l << endl;

  auto res = SimilarityToEdge(l, 0.5);
  for (auto item : res) {
    for (auto i : item) {
      cout << i << " ";
    }
    cout << endl;
  }
}

// 矩阵初始化
void Test2() {
  MatrixXi m(6, 6);
  auto a = MatrixXi::Zero(3, 3);
  auto b = MatrixXi::Zero(3, 3);
  auto c = MatrixXi::Ones(3, 3);
  auto d = MatrixXi::Zero(3, 3);

  m << a, b, c, d;
  cout << m.rows() << " " << m.cols() << endl;
  cout << m << endl;
}

// 矩阵初始化
void Test3() {
  int lhs_face_num = 3;
  int lhs_body_num = 4;
  int rhs_face_num = 5;
  int rhs_body_num = 6;

  Eigen::MatrixXi face_label(lhs_face_num + rhs_face_num, 2);
  Eigen::MatrixXi body_label(lhs_body_num + rhs_body_num, 2);
  for (size_t i = 0; i < lhs_face_num + rhs_face_num; i++) {
    if (i < lhs_face_num) {
      face_label(i, 0) = 1;
      face_label(i, 1) = 0;
    } else {
      face_label(i, 0) = 0;
      face_label(i, 1) = 1;
    }
  }
  for (size_t i = 0; i < lhs_body_num + rhs_body_num; i++) {
    if (i < lhs_body_num) {
      body_label(i, 0) = 1;
      body_label(i, 1) = 0;
    } else {
      body_label(i, 0) = 0;
      body_label(i, 1) = 1;
    }
  }

  cout << face_label << endl;
  cout << "---------" << endl;
  cout << body_label << endl;
}

int main() {
  // Test1();
  // Test2();
  Test3();

  return 0;
}