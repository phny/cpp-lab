/*************************************************************************
        > File Name: quote_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年03月25日 星期三 11时06分00秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct A {
  int age;
  std::vector<int> v;
  std::string name;
};

// struct 继承
struct B : A {
  std::string sex;
};

class Father {
public:
  std::string name;
};

class Son : public Father {
public:
  int age;
};

void SetStruct(struct A &a) {
  a.age = 101;
  a.name = "testing";
  a.v.push_back(1000);
}

void Foo(int a) {
  a = a + 1;
  std::cout << a << std::endl;
}

int main(int argc, char *argv[]) {
  // 结构体的具名赋值方式
  // struct A a = {.v = {1, 2, 3}, .age = 10, .name = "tome"};

  // SetStruct(a);
  // std::cout << a.age << " " << a.name << std::endl;

  struct A *a_ptr = new B();
  struct B *c_ptr = static_cast<struct B *>(a_ptr);
  c_ptr->sex = "woman";
  c_ptr->name = "Tom";
  c_ptr->age = 220;
  std::cout << c_ptr->sex << std::endl;
  std::cout << c_ptr->name << std::endl;
  std::cout << c_ptr->age << std::endl;

  struct B *b_ptr = dynamic_cast<struct B *>(new B());

  b_ptr->sex = "man"; // 这里为什么会不行呢???
  b_ptr->age = 100;
  b_ptr->name = "Jack";
  b_ptr->v.push_back(100);

  std::cout << b_ptr->sex << std::endl;
  std::cout << b_ptr->age << std::endl;
  std::cout << b_ptr->name << std::endl;

  Father *f = NULL;
  Son *s = new Son();
  f = s;
  f->name = "Test";
  s->age = 200;

  std::cout << f->name << ": " << s->age << std::endl;

  Foo(100);

  return 0;
}
