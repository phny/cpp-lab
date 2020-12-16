#include <iostream>

using namespace std;

// clang-format off
/*
const后边的内容为“常量”。

指向对象的类型 +　指针类型 + 指针名
      double      *         ptr    // 普通指针指向普通变量，指针跟指针指向的内容都可以修改
const double      *         ptr    // 普通指针指向常量对象，指针指向的内容不可以修改，指针的指向可以修改
      double      *const    ptr    // 常量指针指向普通对象，指针指向不可以修改，指针指向的内容可以修改
const double      *const    ptr    // 常量指针指向常量对象，指针指向，指针指向内容均不可以修改
*/
// clang-format on

void TestFunc1() { 
    double d = 3.14159;
    double a = 2.0;

    double* ptr0 = &d;
    *ptr0 = 3.15;

    const double * ptr1 = &d;
    // *ptr1 = 3.15; // error

    double *const ptr2 = &d;
    // ptr2 = &a; // error

    const double *const ptr3 = &d;
    // *ptr3 = 9.0; // error
    // ptr3 = &a; // error
}

int main(int argc, char* argv[]) {
    TestFunc1();

    return 0;
}