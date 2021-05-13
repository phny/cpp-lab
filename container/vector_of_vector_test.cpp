#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  std::vector<std::vector<float>> vv = {{1.23, 3.45}, {3.21, 4.64, 6.94}};
  float *data = vv[0].data();
  int32_t item_num = 5;
  for (size_t i = 0; i < 5; i++) {
    std::cout << *(data + i) << std::endl;
  }

  return 0;
}