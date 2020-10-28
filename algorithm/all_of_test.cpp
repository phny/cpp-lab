#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  std::vector<bool> v;
  v.resize(10);
  std::fill(v.begin(), v.end(), true);

  if (std::all_of(v.begin(), v.end(), [](bool i) { return i; })) {
    std::cout << "all is true" << std::endl;
  } else {
    std::cout << "some is not true" << std::endl;
  }

  return 0;
}