#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  std::queue<std::pair<std::string, std::vector<int>>> q;
  std::vector<int> v{1, 2, 3, 4};
  q.push(std::make_pair("search", v));
  std::cout << q.size() << std::endl;

  std::pair<std::string, std::vector<int>> ret = q.front();
  std::cout << ret.first << std::endl;
  q.pop();
  std::cout << q.size() << std::endl;
  return 0;
}