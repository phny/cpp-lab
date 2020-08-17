#include <iostream>
#include <math.h>

extern "C" {

/* Compute the greatest common divisor */
int gcd(int x, int y) {
  int g = y;
  while (x > 0) {
    g = x;
    x = y % x;
    y = g;
  }
  return g;
}

/* Test if (x0,y0) is in the Mandelbrot set or not */
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

/* Divide two numbers */
int divide(int a, int b, int *remainder) {
  int quot = a / b;
  *remainder = a % b;
  return quot;
}

/* Average values in an array */
double avg(double *a, int n) {
  int i;
  double total = 0.0;
  for (i = 0; i < n; i++) {
    total += a[i];
  }
  return total / n;
}

/* Sum values in an array */
int64_t sum(int64_t *a, int n) {
  int i;
  int64_t total = 0;
  for (i = 0; i < n; i++) {
    total += a[i];
  }
  return total;
}

/* A C data structure */
typedef struct Point {
  double x, y;
} Point;

/* Function involving a C data structure */
double distance(Point *p1, Point *p2) {
  return hypot(p1->x - p2->x, p1->y - p2->y);
}

/* pointer as output paramter */
void float_ptr_as_output(float *input, int len, float *output) {
  for (int i = 0; i < len; i++) {
    *(output + i) = *(input + i);
  }
}

/// @brief 枚举类型
typedef enum {
  ENGINE_UNKNOWN = -1, ///< 未知的Engine
  ENGINE_FLAT = 0,     ///< 暴力比对模式的SearchEngine
  ENGINE_PQ = 1,       ///< PQ模式的SearchEngine
  ENGINE_DC = 2        ///< Deepcode模式的SearchEngine
} se_engine_e;

} // extern "C"