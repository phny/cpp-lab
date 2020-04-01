/*************************************************************************
	> File Name: ../vector_method_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月27日 星期五 14时23分15秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    vector<int> v1;
    vector<int> v2 = {1,2,3,4,5};
    v1.insert(v1.end(), v2.begin(), v2.begin() + 3);

    cout << "v1 = " << endl;
    for (auto i : v1) {
        cout << i << endl;
    }
    v1[1] = 1000;

    cout << "v2 = " << endl;
    for (auto i : v2) {
        cout << i << endl;
    }

    return 0;
}
