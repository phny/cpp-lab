#include <iostream>
#include <string>
#include <tuple>

using namespace std;

int main(int argc, char *argv[]) {
  // 构造 tuple
  // std::tuple<int, string> t = std::make_tuple(100, "Tome")
  std::tuple<int, std::string> t;

  // 设置值
  std::get<0>(t) = 100;
  std::get<1>(t) = "hyl";

  // 获取值
  std::cout << std::get<0>(t) << ":" << std::get<1>(t) << std::endl;

  return 0;
}