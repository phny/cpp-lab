/*************************************************************************
        > File Name: virtual_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年03月16日 星期一 23时11分57秒
 ************************************************************************/

#include <iostream>

using namespace std;

class Base {
public:
  virtual void func() { std::cout << "hellp world" << std::endl; }
};

class Interface {
public:
  virtual void func1() = 0;
  int a = 100;
};

int main() {
  Base b;
  b.func();
  return 0;
}
