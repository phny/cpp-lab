#ifndef DATE_UTILS_H_
#define DATE_UTILS_H_

#include <iomanip>
#include <iostream>
#include <sstream>

/// @brief 时间戳转换成字符串形式: 1569939387-->2020-03-01 00:00:00
std::string TimestampToStringDate(int64_t timestamp) {
  std::time_t t(timestamp);
  std::stringstream ss;
  ss << std::put_time(std::localtime(&t), "%F %T");
  return ss.str();
}

/// @brief 时间戳转换成字符串形式: 1569939387-->2020-03-01 00:00:00
std::string TimestampToDate(int64_t timestamp) {
  std::time_t t(timestamp);
  std::stringstream ss;
  ss << std::put_time(std::localtime(&t), "%Y-%m-%d %H:%M:%S");
  return ss.str();
}

/// @brief 时间戳转换成字符串形式: 1569939387-->20200301
std::string TimestampToIntegerDate(int64_t timestamp) {
  std::time_t t(timestamp);
  std::stringstream ss;
  ss << std::put_time(std::localtime(&t), "%Y%m%d");
  return ss.str();
}

/// @brief 将字符串形式的日期转换成时间戳: 2020-03-01 00:00:00 --> 1569939387
int64_t GetTimeStampFromStringDate(const std::string str_date) {
  std::tm t{};
  std::istringstream ss(str_date);

  ss >> std::get_time(&t, "%Y-%m-%d %H:%M:%S");
  if (ss.fail()) {
    throw std::runtime_error{"failed to parse time string"};
  }
  std::time_t time_stamp = mktime(&t);
  return static_cast<int64_t>(time_stamp);
}

#endif
