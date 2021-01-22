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

int main() {
  MatrixXf input(3, 3);
  input << 1, 0.55806044, 0.6348896, 0.55806044, 1, 0.91158394, 0.6348896,
      0.91158394, 1;
  MatrixXf l = input.triangularView<StrictlyUpper>();
  cout << l << endl;

  auto res = SimilarityToEdge(l, 0.5);
  for (auto item : res) {
    for (auto i : item) {
      cout << i << " ";
    }
    cout << endl;
  }

  return 0;
}