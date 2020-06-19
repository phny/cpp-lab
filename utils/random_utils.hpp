#ifndef RANDOM_UTILS_H_
#define RANDOM_UTILS_H_

#include <iostream>
#include <random>

/// @brief 生成指定范围内的随机数
int32_t RandomGenerateInteger(int32_t start, int32_t end) {
  // 用于产生随机数的引擎
  std::random_device rd;
  std::default_random_engine e(rd());
  std::uniform_int_distribution<> u(start, end);
  // 生成随机数
  return u(e);
}

/// @brief 生成指定范围内的随机数
int64_t RandomGenerateInteger(int64_t start, int64_t end) {
  // 用于产生随机数的引擎
  std::random_device rd;
  std::default_random_engine e(rd());
  std::uniform_int_distribution<> u(start, end);
  // 生成随机数
  return u(e);
}

#endif