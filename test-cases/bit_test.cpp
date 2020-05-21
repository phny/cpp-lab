/*************************************************************************
	> File Name: bit_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月20日 星期三 17时18分54秒
 ************************************************************************/

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int64_t a = 128;
    int64_t b = a & 0x00000000000000FF;

    std::cout << b << std::endl;

    return 0;
}

