/*************************************************************************
> File Name: ../istream_iterator_read_file_test.cpp
> Author:
> Mail:
> Created Time: 2020年04月04日 星期六 06时30分43秒
************************************************************************/

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

namespace detail {
class Line : std::string {
  friend std::istream &operator>>(std::istream &is, Line &line) {
    return std::getline(is, line);
  }
};
} // namespace detail

int main() {
  // 读取文件的所有行到vector（默认分隔符是空格、tab）
  std::ifstream dataFile("data.txt");
  std::istream_iterator<string> dataBegin(dataFile);
  std::istream_iterator<string> dataEnd;
  std::vector<string> data(dataBegin, dataEnd);

  for (auto &i : data) {
    std::cout << i << std::endl;
  }
  std::cout << std::endl;

  // 读取文件的所有行到数组(默认分割符是换行符), 待修复，还有编译问题
  // std::ifstream in_file("./test.txt");
  // std::istream_iterator<detail::Line> begin(in_file);
  // std::istream_iterator<detail::Line> end;
  // std::vector<string> v(begin, end);
  // for (auto& line : v) {
  //   cout << line << endl;
  // }
  //

  int64_t a = 7973800683988995994;
  uint32_t b;
  b = a;
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;

  int32_t c = a >> 32;
  cout << "c: " << c << endl;

  return 0;
}
