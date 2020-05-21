/*************************************************************************
        > File Name: seekg_seekp_tellp_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年05月21日 星期四 09时39分06秒
 ************************************************************************/

#include <assert.h>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
  ifstream in("test.txt");
  assert(in);
  in.seekg(
      0, ios::end);  //基地址为文件结束处，偏移地址为0，于是指针定位在文件结束处
  streampos sp =
      in.tellg();  // sp为定位指针，因为它在文件结束处，所以也就是文件的大小
  cout << "filesize:" << endl << sp << endl;

  in.seekg(-sp / 3,
           ios::end);  //基地址为文件末，偏移地址为负，于是向前移动sp/3个字节
  streampos sp2 = in.tellg();
  cout << "from file topoint:" << endl << sp2 << endl;

  in.seekg(0, ios::beg);  //基地址为文件头，偏移量为0，于是定位在文件头
  cout << in.rdbuf();  //从头读出文件内容
  in.seekg(sp2);

  cout << in.rdbuf() << endl;  //从sp2开始读出文件内容

  return 0;
}
