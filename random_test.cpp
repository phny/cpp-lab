/*************************************************************************
	> File Name: ../random_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月26日 星期四 15时45分26秒
 ************************************************************************/

#include<iostream>
using namespace std;

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
 
int main()
{
       cout <<"RAND_MAX:"<< RAND_MAX << endl;
       srand((unsigned)time(NULL));
       for (int i = 0; i < 5; i++)
              cout <<  (rand() % (1 - 100 + 1)) + 1 << endl;; //生成[3,7]范围内的随机数
       cout << endl;
}
