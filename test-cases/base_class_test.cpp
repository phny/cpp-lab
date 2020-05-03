/*************************************************************************
        > File Name: mylink.cpp
        > Author:
        > Mail:
        > Created Time: 2020年01月18日 星期六 12时55分27秒
 ************************************************************************/

#include <iostream>

using namespace std;

class MyLink {
public:
  // 构造函数
  MyLink();
  // 析构函数
  ~MyLink();
  // 拷贝构造函数
  MyLink(const MyLink &other);
  // 赋值构造函数
  MyLink &operator=(const MyLink &other);

private:
  char *m_data;
};

int main() { return 0; }
