/*************************************************************************
	> File Name: other.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月03日 星期日 20时29分02秒
 ************************************************************************/

#include "other.hpp"

#include "hello.hpp"

void other_func()
{
    Hello<char> hc;
    Hello<int> hi;

    hc.print_hello('a');
    hi.print_hello(1);
}

