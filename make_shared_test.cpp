/*************************************************************************
	> File Name: make_shared_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月06日 星期一 20时51分49秒
 ************************************************************************/

// make_shared example
#include <iostream>
#include <memory>

using namespace std;


class Demo {
public:
    // 构造函数
    Demo();
    Demo(int n);
    // 析构函数
    virtual ~Demo();
    // 赋值运算符
    Demo& operator=(const Demo& other);
    // 复制构造函数
    Demo(const Demo& other);
private:
    char* m_data;
};


Demo::Demo() {
    cout << "Demo construct func" << endl;
}
Demo::Demo(int n) {
    cout << "Demo construct func with n: " << n << endl;
}

Demo::~Demo() {
    cout << "Demo deconstruct" << endl;
}

Demo& Demo::operator=(const Demo& other) {
    cout << "operator = func" << endl;
}

Demo::Demo(const Demo& other) {
    cout << "Demo copy construct func" << endl;
}

int main () {

  std::shared_ptr<int> foo = std::make_shared<int> (10);
  // same as:
  std::shared_ptr<int> foo2(new int(10));

  auto bar = std::make_shared<int>(20);

  auto baz = std::make_shared<std::pair<int,int>>(30,40);

  std::cout << "*foo: " << *foo << '\n';
  std::cout << "*bar: " << *bar << '\n';
  std::cout << "*baz: " << baz->first << ' ' << baz->second << '\n';
  
  std::shared_ptr<Demo> demo_ptr = std::make_shared<Demo>();
  std::shared_ptr<Demo> demo_ptr1 = std::make_shared<Demo>(100);
  

  return 0;
}

