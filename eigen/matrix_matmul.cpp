#include <fstream>
#include <iostream>
#include <string>

#include <Eigen/Dense>

#include "utils/io_utils.hpp"

using namespace std;

void Test1() {
  Eigen::MatrixXi a(2, 2);
  a << 1, 2, 3, 4;
  Eigen::MatrixXi b(2, 2);
  b << 4, 5, 6, 7;
  auto res = 2 * a * b;
  //

  auto c = 2 * a;
  cout << res << endl;

  cout << c << endl;
}

int main(int argc, char *argv[]) {
  Test1();

  return 0;
}