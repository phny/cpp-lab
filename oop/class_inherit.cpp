#include <iostream>
using namespace std;
class A {
public:
  virtual void foo() {
    cout << "A's foo()" << endl;
    bar();
  }
  virtual void bar() { cout << "A's bar()" << endl; }
};

class B : public A {
public:
  void foo() {
    cout << "B's foo()" << endl;
    A::foo();
  }
  void bar() { cout << "B's bar()" << endl; }
};

class Base {
private:
  int x;

public:
  virtual void mf1() = 0;
  virtual void mf1(int i);
  virtual void mf2();
  void mf3();
  void mf3(double d);
};

void Base::mf1() { cout << "Base::mf1" << endl; }
void Base::mf1(int i) { cout << "Base::mf1(int)" << endl; }
void Base::mf2() { cout << "Base::mf2" << endl; }
void Base::mf3() { cout << "Base::mf3" << endl; }
void Base::mf3(double d) { cout << "Base::mf3" << endl; }

class Derived : public Base {
public:
  using Base::mf1;
  using Base::mf3;
  virtual void mf1();
  void mf3();
  void mf4();
};

void Derived::mf1() { cout << "Derived::mf1" << endl; }
void Derived::mf3() { cout << "Derived::mf3" << endl; }
void Derived::mf4() { cout << "Derived::mf4" << endl; }

int main() {
  B bobj;
  A *aptr = &bobj;
  aptr->foo();    /*输出: B's foo(), A's foo()*/
  A aobj = *aptr; //转化为A类对象
  aobj.foo();
}