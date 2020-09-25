#include <iostream>

using namespace std;

/// @brief 基本的可变参数模板定义方式
template <class... T> void f(T... args) {
  cout << sizeof...(args) << endl; //打印变参的个数
}

/// @brief 展开可变模板的参数（递归的方式）
// 递归终止函数
template <class T> void print(T t) { cout << "parameter: " << t << endl; }
// 展开函数
template <class T, class... Args> void print(T head, Args... rest) {
  cout << "parameter: " << head << endl;
  print(rest...);
}

/// @brief 可变参数模板求和例子
template <typename T> T sum(T t) { return t; }
template <typename T, typename... Types> T sum(T first, Types... rest) {
  return first + sum<T>(rest...);
}

/// @brief 逗号表达式方式展开参数
template <class T> void printarg(T t) { cout << t << endl; }

template <class... Args> void expand(Args... args) {
  int arr[] = {(printarg(args), 0)...};
}

int main(int argc, char *argv[]) {
  // 输出可变参数的个数
  f(1, 2, 3, 4);

  // 展开参数
  print(1, 2, 3, 4);

  // 求和
  cout << sum(1, 2, 3, 4, 5) << endl;

  // 逗号表达式方式展开参数
  expand(1, 2, 3, 4);

  return 0;
}