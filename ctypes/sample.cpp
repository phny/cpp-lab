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

/// @brief 指针作为输出: 输出内存外面申请好
void float_ptr_as_output(int n, float *output) {
  float init_value = 1.23;
  for (int i = 0; i < n; i++) {
    *(output + i) = i + init_value;
  }
}

/// @brief 指针作为输出: 输出内存外面申请好
void int64_ptr_as_output(int n, int64_t *output) {
  int64_t init_value = 10;
  for (int i = 0; i < n; i++) {
    *(output + i) = i + init_value;
  }
}

} // extern "C"
