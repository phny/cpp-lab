/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月05日 星期二 10时07分33秒
 ************************************************************************/

#include <iostream>
#include "huge_data.hpp"

using namespace std;

huge_data prepare_data(unsigned sz) {
    huge_data h(sz);
    // 为h填充数据
    return h;

}

int main(int argc, char* argv[]) {
    huge_data a;
    a = prepare_data(1024);

    return 0;
}

