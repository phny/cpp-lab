/*************************************************************************
	> File Name: sort_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月05日 星期五 13时56分30秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct A {
  int a;
  string name;
};



int main(int argc, char* argv[]) {
    vector<struct A> v = { {100, "a"}, {9, "b"}, {9, "c"}, {2, "d"}};
    std::sort(v.begin(), v.end(), [](struct A a, struct A b) {return a.a <= b.a;});

    for (auto& i : v) {
        cout << i.a << ": " << i.name << endl;
    }

    cout << endl;
    
    return 0;
}

