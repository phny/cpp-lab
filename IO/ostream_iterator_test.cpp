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
  std::ostream_iterator<int> iter_out(out, "\n");
  // 通过 std::ostream_iterator 保存到文件中
  std::copy(a, a + 4, iter_out);
  out.close();
  std::cout << "write finished" << std::endl;

  // 通过 std::istream_iterator 将文件内容读取到数组
  std::ifstream in("hello.txt");
  std::vector<int> v;
  std::copy(std::istream_iterator<int>(in), std::istream_iterator<int>(),
            back_inserter(v));

  // 输出读取到的元素
  for_each(v.begin(), v.end(), [](const int i) { cout << i << endl; });
  std::cout << "read finished" << std::endl;

  return 0;
}
