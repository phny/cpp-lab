/*************************************************************************
        > File Name: mytemplate.cpp
        > Author:
        > Mail:
        > Created Time: 2020年05月03日 星期日 08时48分16秒
 ************************************************************************/

#include <iostream>

using namespace std;

// 普通模板类
template <typename T0> struct MyClassTemplate {
  T0 value;

  // 模板类的成员函数在类内实现方法
  template <typename T1> void set(T1 const &v) { value = T0(v); }

  template <typename T1> T1 get();
};

// 模板类的成员函数在类外实现方法
template <typename T0> template <typename T1> T1 MyClassTemplate<T0>::get() {
  return T1(value);
}

// 带友元函数的类
class citizen {
private:
  int id;
  double money;
  template <typename T> friend class FBI_agent;

  template <typename T> friend T duty(citizen &c);

public:
  citizen(int id) : id(id) {}
};

int main(int argc, char *argv[]) {
  MyClassTemplate<int> m1;
  m1.set<int>(100);
  ;
  int ret = m1.get<int>();
  cout << ret << endl;

  return 0;
}
