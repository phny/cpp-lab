#ifndef RANDOM_UTILS_H_
#define RANDOM_UTILS_H_

#include <chrono>
#include <iostream>
#include <random>
#include <vector>

using std::default_random_engine;
using std::uniform_int_distribution;
using namespace std::chrono;

#define LOCATION_BITS 15
#define CAMERA_ID_BITS 7
#define TIMESTAMP_BITS 32
#define SEQ_BITS 10

#define LOCATION_MAX (std::pow(2, LOCATION_BITS) - 1)
#define CAMERA_ID_MAX (std::pow(2, CAMERA_ID_BITS) - 1)
#define SEQ_MAX (std::pow(2, SEQ_BITS) - 1)

/// @brief 生成 feature id
int64_t ConstructTimestamp() {
  int64_t timestamp =
      duration_cast<milliseconds>(system_clock::now().time_since_epoch())
          .count();
  return timestamp;
}

/// @brief 生成regionID
int64_t ConstructRegionID() {
  auto timestamp =
      duration_cast<milliseconds>(system_clock::now().time_since_epoch())
          .count();
  default_random_engine e(timestamp);
  uniform_int_distribution<int64_t> location(0, LOCATION_MAX);
  return location(e);
}

/// @brief 生成cameraID
int64_t ConstructCameraID() {
  auto timestamp =
      duration_cast<milliseconds>(system_clock::now().time_since_epoch())
          .count();
  default_random_engine e(timestamp);
  uniform_int_distribution<int64_t> camera_id(0, CAMERA_ID_MAX);
  return camera_id(e);
}

/// @brief 生成seq
int64_t ConstructSeq() {
  auto timestamp =
      duration_cast<milliseconds>(system_clock::now().time_since_epoch())
          .count();
  default_random_engine e(timestamp);
  uniform_int_distribution<int64_t> seq(0, SEQ_MAX);
  return seq(e);
}

/// @brief 生成FeatureID
int64_t ConstructFeatureID(int64_t region_id, int64_t camera_id,
                           int64_t timestamp, int64_t seq) {
  int64_t feature_id =
      (region_id << (64 - LOCATION_BITS)) |
      (camera_id << (64 - LOCATION_BITS - CAMERA_ID_BITS)) |
      (timestamp << (64 - LOCATION_BITS - CAMERA_ID_BITS - TIMESTAMP_BITS)) |
      (seq);
  return feature_id;
}

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