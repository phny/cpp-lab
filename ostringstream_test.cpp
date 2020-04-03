/*************************************************************************
	> File Name: ostringstream_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月03日 星期五 17时27分45秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]) {
    std::ostringstream oss;
    
    oss << "dhhdhhd";
    oss << 'd';
    oss << 2333;

    oss.put('a');

    std::cout << oss.str() << std::endl;

    std::string s1;

    s1 = oss.str();

    std::cout << s1 << std::endl;

    return 0;
}
