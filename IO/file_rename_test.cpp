/*************************************************************************
        > File Name: rename_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年06月16日 星期二 22时06分23秒
 ************************************************************************/

#include <cerrno>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

// 不能跨盘重命名！！！

int main() {
  string src_file = "/data/tmp/feature_0.bin";
  string dst_file = "/data/data/feature_0.bin";
  // 不能跨盘移动文件
  if (std::rename(src_file.c_str(), dst_file.c_str()) < 0) {
    cout << " move file error" << strerror(errno) << endl;
  } else {
    cout << "move file success" << endl;
  }
}
