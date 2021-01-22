#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

std::vector<std::vector<int>> result;

void backtrack(const std::vector<int> &nums, std::vector<int> &track) {
  if (track.size() == nums.size()) {
    std::vector<int> tmp(track.begin(), track.end());
    result.push_back(tmp);
    return;
  }
  for (size_t i = 0; i < nums.size(); i++) {
    if (std::find(track.begin(), track.end(), nums[i]) != track.end()) {
      continue;
    }
    track.push_back(nums[i]);
    backtrack(nums, track);
    track.pop_back();
  }
}

/// @brief 返回给定数组的全部全排列
/// @param[in] nums 需要进行全排列的数字
/// @return nums全排列的结果
std::vector<std::vector<int>> permute(const std::vector<int> &nums) {
  std::vector<int> track;
  backtrack(nums, track);
  return result;
}

int main(int argc, char *argv[]) {
  std::vector<int> nums = {1, 2, 3, 4};
  auto res = permute(nums);
  for (auto vec : res) {
    for (auto i : vec) {
      cout << i << " ";
    }
    cout << endl;
  }

  return 0;
}