#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> vv;

  std::vector<int> v1 = {1};
  std::vector<int> v2 = {1, 2};
  std::vector<int> v3 = {1, 2, 3};
  std::vector<int> v4 = {1, 2, 3, 4};

  vv.push_back(v1);
  vv.push_back(v2);
  vv.push_back(v3);
  vv.push_back(v4);

  // 通过索引来访问数据
  for (auto v : vv) {
    for (auto i : v) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }

  std::cout << "************************" << std::endl;

  // 通过数据指针的起始地址来访问数据: 这样子是错误的，因为各个sub
  // vector的内存地址不是连续的 int* i_ptr = vv[0].data(); for (int i = 0; i <
  // 10; i++) {
  //     std::cout << *(i_ptr + i) << std::endl;
  // }

  for (auto v : vv) {
    int *p = v.data();
    for (int i = 0; i < v.size(); i++) {
      std::cout << *(p + i) << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
