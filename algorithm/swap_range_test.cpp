
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  std::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

  std::swap_ranges(v1.begin(), v1.begin() + 3, v2.begin() + 2);

  for_each(v1.begin(), v1.end(),
           [](const int i) { std::cout << i << std::endl; });
  // for_each(v2.begin(), v2.end(), [] (const int i) { std::cout << i <<
  // std::endl; });

  return 0;
}
