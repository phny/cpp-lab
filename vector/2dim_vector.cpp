#include <iostream>
#include <vector>

using namespace std;

typedef struct a *b;

int main(int argc, char *argv[]) {
  // 二维数组初始化
  std::vector<std::vector<int64_t>> v(10, std::vector<int64_t>(10));

  v[1][9] = 100;
  std::cout << v[1][9] << std::endl;

  return 0;
}