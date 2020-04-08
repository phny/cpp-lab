/*************************************************************************
	> File Name: hello.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月08日 星期三 15时16分57秒
	> Created Time: 2020年01月20日 星期一 22时40分24秒
 ************************************************************************/

#include<iostream>
#include <vector>

using namespace std;

int main() {
    cout << "hello world" << endl;
    
    vector<int> v(1000000);
    cout << v.size() << endl;
    cout << std::to_string(static_cast<double>(v.size()) / 34326.67 * 1000) << endl;
    return 0;
}
