/*************************************************************************
	> File Name: max_element_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月06日 星期三 11时22分52秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
   vector<int> v = {10000,2,3,4,5,6};
   int max = *std::max_element(v.begin(), v.end());
    std::cout << max << std::endl;
    
    return 0;
}
