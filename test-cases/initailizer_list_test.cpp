/*************************************************************************
        > File Name: initailizer_list_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年04月01日 星期三 22时27分28秒
 ************************************************************************/

#include <initializer_list>
#include <iostream>
#include <vector>

using namespace std;

double sum(std::initializer_list<double> li);

int main(int argc, char *argv[]) {
  double s = sum({1.2, 3.0, 3.4, 4.5});
  std::cout << s << std::endl;
  return 0;
}

double sum(std::initializer_list<double> li) {

  double sum = 0;
  for (auto p = li.begin(); p != li.end(); p++) {
    sum += *p;
  }
  return sum;
}
