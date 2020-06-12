/*************************************************************************
	> File Name: file_app_mode.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月12日 星期五 16时39分29秒
 ************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    std::ofstream out("./test.txt", std::ios::app | std::ios::ate);
    out << 1 << ": " << 2 << endl;
    out.close();

    return 0;
}

