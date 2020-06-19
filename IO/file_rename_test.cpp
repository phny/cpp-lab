/*************************************************************************
        > File Name: rename_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年06月16日 星期二 22时06分23秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

// 不能跨盘重命名！！！

int main() {
  string src_file = "/home/SENSETIME/heyulin/images/a_1.jpg";
  string dst_file = "/home/SENSETIME/heyulin/images/a.jpg";
  rename(src_file.c_str(), dst_file.c_str());
}
