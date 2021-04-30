#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/// 方法1：递归
/// @note 有bug
std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
  if (nums.empty()) {
    return {{}};
  }
  int n = nums.back();
  nums.pop_back();
  // 先递归算出前面元素的所有子集
  std::vector<std::vector<int>> res = subsets(nums);
  // 然后在之前的结果上进行追加
  for (size_t i = 0; i < res.size(); i++) {
    res.push_back(res[i]);
    res.back().push_back(n);
  }
  return res;
}

///---------------------方法2：回溯------------------------

// 存储所有的子集
static std::vector<std::vector<int>> res;

void backtrack(std::vector<int> &nums, int start, std::vector<int> &track) {
  // 前序遍历的位置
  res.push_back(track);
  // 从start开始，防止产生重复的子集
  for (size_t i = start; i < nums.size(); i++) {
    // 做选择
    track.push_back(nums[i]);
    // 递归回溯
    backtrack(nums, i + 1, track);
    // 撤销选择
    track.pop_back();
  }
}

std::vector<std::vector<int>> subsets2(std::vector<int> &nums) {
  // 记录走过的路径
  std::vector<int> track;
  backtrack(nums, 0, track);
  return res;
}

int main(int argc, char *argv[]) {
  std::vector<int> nums = {1, 2, 3, 4};
  auto res = subsets2(nums);
  for (auto v : res) {
    for (auto i : v) {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}