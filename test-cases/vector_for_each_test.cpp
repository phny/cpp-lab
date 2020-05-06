/*************************************************************************
        > File Name: vector_for_each_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年04月22日 星期三 21时59分21秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  std::vector<string> myvector;
  myvector.push_back("a.txt");
  myvector.push_back("b.txt");
  myvector.push_back("c.txt");

  std::for_each(myvector.begin(), myvector.end(),
                [](string a) { cout << a << endl; });

  // std::replace_if(myvector.begin(), myvector.end(), [](string a) {

  // });

  return 0;
}
