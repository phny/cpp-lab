#include <iostream>
#include <math.h>

extern "C" {

/// @brief 两数相加
int gcd(int x, int y) {
  int g = y;
  while (x > 0) {
    g = x;
    x = y % x;
    y = g;
  }
  return g;
}

/// @brief 曼德布罗特集合判断
int in_mandel(double x0, double y0, int n) {
  double x = 0, y = 0, xtemp;
  while (n > 0) {
    xtemp = x * x - y * y + x0;
    y = 2 * x * y + y0;
    x = xtemp;
    n -= 1;
    if (x * x + y * y > 4)
      return 0;
  }
  return 1;
}

/// @brief 两数相除
int divide(int a, int b, int *remainder) {
  int quot = a / b;
  *remainder = a % b;
  return quot;
}

/// @brief 平均值
double avg(double *a, int n) {
  int i;
  double total = 0.0;
  for (i = 0; i < n; i++) {
    total += a[i];
  }
  return total / n;
}

/// @brief 普通结构
typedef struct Point {
  double x, y;
} Point;

/// @brief 结构体中函数char*指针
struct MyConfig {
  int a;
  double d;
  char *data;
};

/// @brief 结构体指针作为参数
double distance(Point *p1, Point *p2) {
  return hypot(p1->x - p2->x, p1->y - p2->y);
}

/// @brief float 指针作为输出: 输出内存外面申请好
void float_ptr_as_output(int n, float *output) {
  float init_value = 1.23;
  for (int i = 0; i < n; i++) {
    *(output + i) = i + init_value;
  }
}

/// @brief int64 指针作为输出: 输出内存外面申请好
void int64_ptr_as_output(int n, int64_t *output) {
  int64_t init_value = 10;
  for (int i = 0; i < n; i++) {
    *(output + i) = i + init_value;
  }
}

/// @brief 枚举类型
typedef enum {
  ENGINE_UNKNOWN = -1, ///< 未知的Engine
  ENGINE_FLAT = 0,     ///< 暴力比对模式的SearchEngine
  ENGINE_PQ = 1,       ///< PQ模式的SearchEngine
  ENGINE_DC = 2        ///< Deepcode模式的SearchEngine
} se_engine_e;

/// @brief 枚举类型2
typedef enum {
  CACHE_ON_NONE = 0, ///< 不缓存
  CACHE_ON_MEM = 1,  ///< 缓存在内存中
  CACHE_ON_DISK = 2  ///< 缓存在本地磁盘中，内部使用临时路径
} se_feature_cache_storage_e;

/// @brief se config
typedef struct SearchEngineConfig {
  uint64_t max_db_size; ///< 最大支持的底库的大小，内部用于做存储预分配
                        ///< 如果设置为小于或等于零，则内部分自动扩容
  int32_t feature_dim; ///< 特征维度
  se_engine_e engine;  ///< SearchEngine底层的检索引擎的类型
  const char *dc_model =
      nullptr; ///< 长特征转化为短特征依赖的模型的路径，仅在Engine为DC时需要配置
  se_feature_cache_storage_e cache_storage; ///< 长特征缓存的存储类型
  // ~SearchEngineConfig() {if (dc_model != nullptr) { delete dc_model; dc_model
  // = nullptr; }}
} se_search_engine_config_t;

} // extern "C"
