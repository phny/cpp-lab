#include <iostream>
#include <vector>

using namespace std;

// Utility function to print a vector
template <typename T> void print(std::vector<T> const &v) {
  for (auto &i : v) {
    std::cout << i << ' ';
  }

  std::cout << std::endl;
}

void Test0() {
  // input vector of integers
  std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // split vector into sub-vectors each of size `n`
  int n = 9;

  // determine the total number of sub-vectors of size `n`
  int size = (v.size() - 1) / n + 1;

  // create an array of vectors to store the sub-vectors
  std::vector<int> vec[size];

  // each iteration of this loop process the next set of `n` elements
  // and store it in a vector at k'th index in `vec`
  for (int k = 0; k < size; ++k) {
    // get range for the next set of `n` elements
    auto start_itr = std::next(v.cbegin(), k * n);
    auto end_itr = std::next(v.cbegin(), k * n + n);

    // allocate memory for the sub-vector
    vec[k].resize(n);

    // code to handle the last sub-vector as it might
    // contain fewer elements
    if (k * n + n > v.size()) {
      end_itr = v.cend();
      vec[k].resize(v.size() - k * n);
    }

    // copy elements from the input range to the sub-vector
    std::copy(start_itr, end_itr, vec[k].begin());
  }

  // print the sub-vectors
  for (int i = 0; i < size; i++) {
    print(vec[i]);
  }
}

std::vector<std::vector<int>> Partition(const std::vector<int> &v, int n) {
  size_t item_num = v.size();
  n = (item_num < n) ? item_num : n;
  int bunch_size = item_num / n;
  vector<vector<int>> bunches;
  bunches.reserve((item_num + 1) / bunch_size);
  for (size_t i = 0; i < item_num; i += bunch_size) {
    auto last = std::min(item_num, i + bunch_size);
    bunches.emplace_back(v.begin() + i, v.begin() + last);
  }
  return bunches;
}

template <typename T>
std::vector<T> SplitVector(const T &v, unsigned split_num) {
  split_num = (v.size() < split_num) ? v.size() : split_num;
  using Iterator = typename T::const_iterator;
  std::vector<T> rtn;
  Iterator it = v.cbegin();
  const Iterator end = v.cend();
  unsigned number_lines = (v.size() + split_num - 1) / split_num;
  while (it != end) {
    T v;
    std::back_insert_iterator<T> inserter(v);
    const auto num_to_copy =
        std::min(static_cast<unsigned>(std::distance(it, end)), number_lines);
    std::copy(it, it + num_to_copy, inserter);
    rtn.push_back(std::move(v));
    std::advance(it, num_to_copy);
  }

  return rtn;
}

// Split a vector into sub-vectors of size `n` in C++
int main() {
  vector<int> v = {1, 2, 3, 4, 5, 6, 7};
  // auto res = SplitVector(v, 5);

  // 切分数组
  auto VectorSplit = [](const std::vector<int> &v, int split_num) {
    split_num = (v.size() < split_num) ? v.size() : split_num;
    using Iterator = std::vector<int>::const_iterator;
    std::vector<std::vector<int>> res;
    Iterator it = v.cbegin();
    const Iterator end = v.cend();
    int number_lines = (v.size() + split_num - 1) / split_num;
    while (it != end) {
      std::vector<int> v;
      std::back_insert_iterator<std::vector<int>> inserter(v);
      const auto num_to_copy =
          std::min(static_cast<int>(std::distance(it, end)), number_lines);
      std::copy(it, it + num_to_copy, inserter);
      res.push_back(std::move(v));
      std::advance(it, num_to_copy);
    }
    return res;
  };

  auto res = VectorSplit(v, 1);
  for (auto item : res) {
    for (auto i : item) {
      cout << i << " ";
    }
    cout << endl;
  }

  return 0;
}