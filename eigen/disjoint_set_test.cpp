
#include <iostream>
#include <unordered_map>
#include <vector>

#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

/// @brief JS散度计算
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

/// @brief JS散度计算
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

template <typename T>
std::vector<std::vector<size_t>>
SimilarityToEdge(const Matrix<T, Dynamic, Dynamic> &input,
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

int64_t GetFather(std::vector<int64_t> &father, int64_t u) {
  std::vector<int64_t> idx;
  while (u != father[u]) {
    idx.push_back(u);
    u = father[u];
  }
  for (auto i : idx) {
    father[i] = u;
  }

  return u;
}

std::vector<int64_t>
EdgeToConnectedGraph(const std::vector<std::vector<size_t>> &edges,
                     int data_num) {
  std::vector<int64_t> father(data_num);
  std::iota(std::begin(father), std::end(father), 0);
  for (size_t i = 0; i < edges.size(); i++) {
    int64_t u = edges[i][0];
    int64_t v = edges[i][1];
    auto fa_u = GetFather(father, u);
    auto fa_v = GetFather(father, v);
    father[fa_u] = father[fa_v];
  }
  for (size_t i = 0; i < data_num; i++) {
    GetFather(father, i);
  }

  return father;
}

std::unordered_map<int64_t, std::vector<int64_t>>
Indexing(const std::vector<int64_t> &labels,
         const std::vector<int64_t> &ignore_labels = {-1}) {
  std::unordered_map<int64_t, std::vector<int64_t>> label_to_index;
  for (int64_t i = 0; i < labels.size(); i++) {
    if (std::find(ignore_labels.begin(), ignore_labels.end(), labels[i]) !=
        ignore_labels.end()) {
      continue;
    }
    if (label_to_index.find(labels[i]) != label_to_index.end()) {
      label_to_index[labels[i]].push_back(i);
    } else {
      label_to_index.insert({labels[i], std::vector<int64_t>{i}});
    }
  }

  return label_to_index;
}

int main(int argc, char *argv[]) {
  MatrixXf labels(4, 3);
  labels << 0.8, 0.1, 0.1, 0.2, 0.5, 0.3, 0.3, 0.4, 0.3, 0.5, 0.3, 0.2;
  MatrixXf sims = JensenshannonDistance(labels, labels);
  for (size_t i = 0; i < sims.rows(); i++) {
    for (size_t j = 0; j < sims.cols(); j++) {
      sims(i, j) = 1 - sims(i, j);
    }
  }
  // 求上三角矩阵
  MatrixXf triang = sims.triangularView<StrictlyUpper>();
  cout << triang << endl;
  // 求相似边
  auto edges = SimilarityToEdge(triang, 0.8);
  for (auto item : edges) {
    for (auto i : item) {
      cout << i << " ";
    }
    cout << endl;
  }

  // 求联通图
  auto graph = EdgeToConnectedGraph(edges, labels.rows());
  for (auto i : graph) {
    cout << i << " ";
  }
  cout << endl;
  cout << "-------------------" << endl;
  auto label_to_index = Indexing(graph);
  for (auto it = label_to_index.begin(); it != label_to_index.end(); ++it) {
    cout << it->first << ": ";
    for (auto i : it->second) {
      cout << i << " ";
    }
    cout << endl;
  }

  return 0;
}