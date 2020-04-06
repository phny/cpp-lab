/*************************************************************************
	> File Name: ../ostream_iterator_write_file_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月04日 星期六 06时29分07秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>

int main() {
    std::vector<int> data = { 1, 21, 31, 41, 51, 61, 71, 81 };

    std::ofstream dataFile("data_output.txt");
    std::ostream_iterator<int> dataIter(dataFile, "\t");

    std::copy(data.begin(), data.end(), dataIter);

    return 0;
}
