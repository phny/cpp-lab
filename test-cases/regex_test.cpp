/*************************************************************************
        > File Name: regex_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年04月02日 星期四 15时55分05秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

#include <regex>

using namespace std;

int main() {

  std::string text = "Quick,brown,fox.";
  std::regex ws_re(","); // whitespace
  std::vector<std::string> v(
      std::sregex_token_iterator(text.begin(), text.end(), ws_re, -1),
      std::sregex_token_iterator());

  for (auto &i : v) {
    std::cout << i << std::endl;
  }
  return 0;
}
