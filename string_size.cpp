/*************************************************************************
	> File Name: int_size.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月16日 星期一 09时53分38秒
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int getTypeSize(const string object) {
    return object.size();
}

int main() {
    const string a = "this is a testing";
    int size = getTypeSize(a);
    std::cout << "size of a = " << size << std::endl;
    return 0;
}
