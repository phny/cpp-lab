/*************************************************************************
	> File Name: quote_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月25日 星期三 11时06分00秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct A {
    std::vector<int> v;
    int age;
    std::string name;
};

void TestFunc(struct A& a) {
    a.age = 101;
    a.name = "testing";
    a.v.push_back(1000);
}


int main(int argc, char* argv[]) {
    struct A a = {
        .v = {1,2,3},
        .age = 10,
        .name = "tome"
    };

    TestFunc(a);
    std::cout << a.age << " " << a.name << std::endl;

    return 0;
}
