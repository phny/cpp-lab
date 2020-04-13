/*************************************************************************
        > File Name: ostream_iterator_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年04月04日 星期六 05时49分55秒
 ************************************************************************/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
  int a[] = {1, 2, 3, 4, 5};
  ofstream out("hello.txt", std::ios_base::out);
  ostream_iterator<int, char> iter_out(out, "\n");
  // 将数组通过ostream_iterator保存到文件中
  std::copy(a, a + 4, iter_out);
  out.flush();
  out.close();
  std::cout << "write finished" << std::endl;

  // 通过istream_iterator将文件内容读取到数据中
  ifstream in("hello.txt");
  std::vector<int> v;
  std::copy(istream_iterator<int>(in), istream_iterator<int>(),
            back_inserter(v));

  for (auto &i : v) {
    std::cout << i << std::endl;
  }
  std::cout << "read finished" << std::endl;

  return 0;
}
