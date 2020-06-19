#include <algorithm> //std::sort
#include <iostream>  //std::cout
#include <string>    //std::string
#include <vector>    //std::vector

std::vector<std::string> intersection(std::vector<std::string> &v1,
                                      std::vector<std::string> &v2) {
  std::vector<std::string> v3;

  std::sort(v1.begin(), v1.end());
  std::sort(v2.begin(), v2.end());

  std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(),
                        back_inserter(v3));
  return v3;
}

int main() {
  std::vector<std::string> v1{"a", "b", "c", "s"};
  std::vector<std::string> v2{"b", "c", "q", "a"};

  auto v3 = intersection(v1, v2);

  for (std::string n : v3)
    std::cout << n << ' ';
  std::cout << std::endl;
}
