/*************************************************************************
	> File Name: ../multi_set.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月01日 星期三 10时47分58秒
 ************************************************************************/

#include <iostream>
#include <set>
#include <algorithm>


int main ()
{
    std::vector<int> myints = {10, 20, 30, 20, 20};
    std::vector<int> myints2 = {10, 10, 20, 20, 30, 40};
    std::multiset<int> first(myints.begin(), myints.end());
    std::multiset<int> second(myints2.begin(), myints2.end());
    // 求交集
    std::multiset<int> result;
    set_intersection(first.begin(), first.end(), second.begin(), second.end(), inserter(result, result.begin()));
    // 输出结果
    for (auto& item : result) {
        std::cout << item << std::endl;
    }

    return 0;
}
