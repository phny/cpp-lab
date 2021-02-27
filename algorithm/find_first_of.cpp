#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  std::vector<int> input = {4, 5, 6, 7, 8, 9, 10};
  std::vector<int> target = {60, 7, 8, 9};
  auto it = std::find_first_of(input.begin(), input.end(), target.begin(),
                               target.end());
  if (it != input.end()) {
    std::cout << *it << std::endl;
  }

  return 0;
}
