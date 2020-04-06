/*************************************************************************
	> File Name: setprecision_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月04日 星期六 11时07分56秒
 ************************************************************************/

#include<iostream>

using namespace std;

int main() {
    // 设置浮点数显示精度
    cout.precision(8);
    // 打印末尾的0和小数点
    cout.setf(ios_base::showpoint);

    float price1 = 20.40;
    float price2 = 1.9 + 8.0 / 9.0;
    
    cout << price1 << endl << price2 << endl;

    uint64_t a = 10000880000;
    cout << a << endl;

    return 0;
}
