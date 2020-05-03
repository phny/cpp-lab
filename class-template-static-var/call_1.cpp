/*************************************************************************
        > File Name: call_1.cpp
        > Author:
        > Mail:
        > Created Time: 2020年05月03日 星期日 12时03分03秒
 ************************************************************************/

#include <iostream>

#include "the_class.hpp"

using namespace std;

void call_1() {
  the_class<int> c;
  std::cout << c.id << std::endl;
}
