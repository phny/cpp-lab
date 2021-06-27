#include <Eigen/Dense>
#include <iostream>

using namespace std;

int main() {
  Eigen::MatrixXf m(4, 4);
  m << 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16;
  cout << "Block in the middle" << endl;
  int row = 2;
  int col = 2;
  // fixed
  Eigen::MatrixXf b = m.block<2, 2>(2, 1);
  // dynamic
  Eigen::MatrixXf d = m.block(2, 1, row, col);
  cout << b << endl;
  cout << d << endl;

  // 求矩阵的最大值
  cout << b.maxCoeff() << endl;

  // 求矩阵的最小值
  cout << b.minCoeff() << endl;

  //   for (int i = 1; i <= 3; ++i)
  //   {
  //     cout << "Block of size " << i << "x" << i << endl;
  //     cout << m.block(0,0,i,i) << endl << endl;
  //   }
}