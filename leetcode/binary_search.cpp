#include <iostream>
#include <vector>

using namespace std;

/// @brief 二分查找
int BinarySearch(const std::vector<int> &vec, int target) {
  // [left, right]: 左闭合，右闭合区间
  size_t left = 0;
  size_t right = vec.size() - 1;
  while (left <= right) {
    size_t mid = left + (right - left) / 2;
    if (vec[mid] == target) {
      return mid;
    } else if (vec[mid] < target) {
      left = mid + 1;
    } else if (vec[mid] > target) {
      right = mid - 1;
    }
  }
  return -1;
}

/// @brief 左边界的二分查找
int LeftBoundBinarySearch(const std::vector<int> &vec, int target) {
  size_t left = 0;
  size_t right = vec.size() - 1;
  while (left <= right) {
    size_t mid = left + (right - left) / 2;
    if (vec[mid] == target) {
      right = mid - 1;
    } else if (vec[mid] < target) {
      left = mid + 1;
    } else if (vec[mid] > target) {
      right = mid - 1;
    }
  }
  if (left >= vec.size() || vec[left] != target) {
    return -1;
  }
  return left;
}

/// @brief 右边界的二分查找
int RightBoundBinarySearch(const std::vector<int> &vec, int target) {
  size_t left = 0;
  size_t right = vec.size() - 1;
  while (left <= right) {
    size_t mid = left + (right - left) / 2;
    if (vec[mid] == target) {
      left = mid + 1;
    } else if (vec[mid] < target) {
      left = mid + 1;
    } else if (vec[mid] > target) {
      right = mid - 1;
    }
  }
  if (right < 0 || vec[right] != target) {
    return -1;
  }
  return right;
}

int main(int argc, char *argv[]) { return 0; }