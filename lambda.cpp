/*************************************************************************
	> File Name: lambda.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月11日 星期三 16时22分45秒
    > lambda表达式的测试
 ************************************************************************/

#include<iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int a = 10;
    int b = 20;

    auto func = [](){std::cout << "lambda test, basic lambda" << std::endl;};
    auto func1 = [](int p){std::cout << "lambda test, with parameter" << p << std::endl;};
    auto func2 = [](int p) -> int {std::cout << "lambda test, with parameter" << p << std::endl; return p;};
    auto func3 = [=](int p) -> int {std::cout << "lambda test, with parameter" << p << std::endl; return p;};
    auto func4 = [&](int p) -> int {
        b = 200; 
        std::cout << "lambda test, with parameter" << p << std::endl;  
        return p;
    };

    func();
    func1(a);
    int ret = func2(a);
    func3(a);
    func4(a);

    std::cout << "func2 ret = " << ret << std::endl;
    std::cout << b << std::endl;


    return 0;
}
