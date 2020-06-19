/*************************************************************************
        > File Name: template_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年03月14日 星期六 22时57分20秒
 ************************************************************************/

#include <iostream>

using namespace std;

// 模板函数声明1
template <typename Dtype> void Print(Dtype t);

// 函数模板声明2
template <typename Dtype> void Print2(Dtype a, Dtype b);

// 函数模板声明3
template <typename Dtype1, typename Dtype2> void Print3(Dtype1 a, Dtype2 b);

// 显式实例化
template void Print<int>(int a);

// 显式具体化1
template <> void Print(double a);

int main() {
  std::cout << "template test" << std::endl;

  int a = 10;
  // 调用显式实例化的函数
  Print(a);

  double b = 20.213;
  Print(b);

  Print3(a, b);

  Print2(b, b);
  std::cout << "end template test" << std::endl;

  return 0;
}

// 模板函数定义1
template <typename Dtype> void Print(Dtype t) {
  std::cout << "one type test" << std::endl;
  std::cout << t << std::endl;
}
// 模板函数定义2
template <typename Dtype> void Print2(Dtype a, Dtype b) {
  std::cout << "two same type test" << std::endl;
  std::cout << a << b << std::endl;
}
// 模板函数定义3
template <typename Dtype1, typename Dtype2> void Print3(Dtype1 a, Dtype2 b) {
  std::cout << "two differrent type test" << std::endl;
  std::cout << a << b << std::endl;
}

// 显式具体化定义1
template <> void Print(double a) {
  std::cout << "this is double " << a << std::endl;
}
