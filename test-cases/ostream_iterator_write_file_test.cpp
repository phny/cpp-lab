/*************************************************************************
        > File Name: ../ostream_iterator_write_file_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年04月04日 星期六 06时29分07秒
 ************************************************************************/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::vector<int> data = {1, 21, 31, 41, 51, 61, 71, 81};

  std::ofstream dataFile("data_output.txt");
  std::ostream_iterator<int> dataIter(dataFile, "\n");

  std::copy(data.begin(), data.end(), dataIter);

  return 0;
}
