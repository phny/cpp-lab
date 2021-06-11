#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  std::vector<int64_t> v{1, 2, 3, 4, 5};

  std::stringstream ss;
  for (auto i : v) {
    ss.write((char *)&i, sizeof(i));
  }
  cout << ss.tellg() << endl;
  cout << ss.tellp() << endl;

  std::ostringstream oss;
  for (auto i : v) {
    oss.write((char *)&i, sizeof(i));
  }
  std::cout << "oss size:" << oss.tellp() << endl;

  return 0;
}