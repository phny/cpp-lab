/*************************************************************************
	> File Name: vector_initailize_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月26日 星期四 16时27分06秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int>::iterator it = v1.begin();

    vector<int> v2(it, it+3);

    for (auto i : v2) {
        cout << i << endl;
    }

    cout << "v2.szie = " << v2.size() << endl;
    v1[1] = 100;

    for (auto i : v2) {
        cout << i << endl;
    }
    for (auto i : v1) {
        cout << i << endl;
    }

    // vector swap test
    vector<int> v3 = {1,2,3};
    vector<int> v4 = {4,5,6};

    v3.swap(v4);

    // 释放v4的内存空间
    v4.clear();
    vector<int>().swap(v4);
     
    cout << "v3 = " << endl;
    for (auto i: v3) {
        cout << i << endl;
    }

    return 0;
}
