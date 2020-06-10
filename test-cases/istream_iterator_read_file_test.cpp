/*************************************************************************
        > File Name: ../istream_iterator_read_file_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年04月04日 星期六 06时30分43秒
 ************************************************************************/

#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>

using namespace std;

int main() {
  std::ifstream dataFile("data.txt");
  std::istream_iterator<string> dataBegin(dataFile);
  std::istream_iterator<string> dataEnd;
  std::vector<string> data(dataBegin, dataEnd);

  for (auto& i : data) {
      std::cout << i << std::endl;
  }
  std::cout << std::endl;

  return 0;
}
