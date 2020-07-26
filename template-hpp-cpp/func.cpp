#include <iostream>

template <typename T> T const &func(T const &v) { return v; }

// 显式生成模板实例
// template int const& func(int const& v);

// 或者有其他的函数调用了该模板也行
int foo(int v) {
  ;
  func(v);
  std::cout << "foo" << std::endl;
}