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
    std::istream_iterator<int> dataBegin(dataFile);
    std::istream_iterator<int> dataEnd;
    std::vector<int> data(dataBegin, dataEnd);

    for (int i : data) {
        std::cout << i << "\t";
    }
    std::cout << std::endl;

    std::ifstream in_file("./test.txt");
    std::istream_iterator<string> iter_begin(in_file);
    std::istream_iterator<string> iter_end;
    std::vector<string> v(iter_begin, iter_end);
    for (auto& s : v) {
        cout << s << endl;
    }


    return 0;
}
