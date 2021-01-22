#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  std::vector<int64_t> v = {};
  if (std::find(v.begin(), v.end(), 10) != v.end()) {
    cout << "found it" << endl;
  } else {
    cout << "not found" << endl;
  }

  return 0;
}