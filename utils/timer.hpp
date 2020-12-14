#ifndef TIMEER_H__
#define TIMEER_H__

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/time.h>

double GetTime() {
  timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec * 1000. + tv.tv_usec / 1000.;
}

class TimeAccumulator {
public:
  /// @brief 构造 TimeAccumulator
  TimeAccumulator(const std::string &message = "")
      : message_(message), total_time_(0), stop_(true) {
    Start();
  }
  ~TimeAccumulator() {
    if (!stop_) {
      total_time_ += GetTime() - start_time_;
    }

    std::ostringstream stream;
    stream << message_ << ": " << std::fixed << std::setprecision(2)
           << total_time_ << " ms." << std::setprecision(6);
    std::cout << stream.str() << std::endl;
    ;
  }

  /// @brief 开始计时
  void Start() {
    if (stop_) {
      stop_ = false;
      start_time_ = GetTime();
    }
  }

  /// @brief 停止计时
  void Stop() {
    if (!stop_) {
      total_time_ += GetTime() - start_time_;
      stop_ = true;
    }
  }

  /// @brief 重置计时器
  void Reset() {
    stop_ = true;
    total_time_ = 0;
    Start();
  }

  /// @brief 获取总时间
  double GetTotalTime() const { return total_time_; }

private:
  double start_time_; ///< 上一次开始计数的时间
  double total_time_; ///< 总时间
  bool stop_;         ///< 是否已经停止计时

  std::string message_; ///< 要输出的信息
};

#endif