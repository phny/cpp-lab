#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  std::vector<std::pair<int, int>> vp;
  for (size_t i = 0; i < 10; i++) {
    vp.push_back(std::make_pair(i, i));
  }
  for (auto i : vp) {
    cout << i.first << " " << i.second << endl;
  }

  cout << "------------------------" << endl;

  std::sort(vp.begin(), vp.end(),
            [](std::pair<int, int> &lhs, std::pair<int, int> &rhs) {
              return lhs.first > rhs.first;
            });

  for (auto i : vp) {
    cout << i.first << " " << i.second << endl;
  }

  return 0;
}