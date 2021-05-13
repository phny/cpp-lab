#ifndef RANDOM_UTILS_H_
#define RANDOM_UTILS_H_

#include <iostream>
#include <random>
#include <vector>

/// @brief 生成指定范围内的随机数
int32_t RandomGenerateInteger(int32_t start, int32_t end) {
  // 用于产生随机数的引擎
  std::random_device rd;
  std::default_random_engine e(rd());
  std::uniform_int_distribution<> u(start, end);
  // 生成随机数
  return u(e);
}

#endif