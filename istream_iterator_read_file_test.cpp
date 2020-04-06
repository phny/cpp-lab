/*************************************************************************
	> File Name: ../istream_iterator_read_file_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月04日 星期六 06时30分43秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>

int main()
{
    std::ifstream dataFile("data.txt");
    std::istream_iterator<int> dataBegin(dataFile);
    std::istream_iterator<int> dataEnd;
    std::vector<int> data(dataBegin, dataEnd);

    for (int i : data) {
        std::cout << i << "\t";
    }
    std::cout << std::endl;

    return 0;
}

