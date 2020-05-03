/*************************************************************************
	> File Name: call.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月03日 星期日 12时01分46秒
 ************************************************************************/

#include <iostream>

#include "the_class.hpp"

using namespace std;

void call() {
    the_class<int> c;
    std::cout << c.id << std::endl;
}
