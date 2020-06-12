/*************************************************************************
        > File Name: copy_if_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年04月07日 星期二 22时34分12秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

static bool has_ending(std::string const &fullString,
                       std::string const &ending) {
  if (fullString.length() >= ending.length()) {
    return (0 == fullString.compare(fullString.length() - ending.length(),
                                    ending.length(), ending));
  } else {
    return false;
  }
}

/// @brief 判断是否以指定字符结尾
static bool HavePrefix(std::string const &fullString,
                       std::string const &prefix) {
  if (fullString.rfind(prefix, 0) == 0) {
    // s starts with prefix
    return true;
  }
  return false;
}

struct A {
  int age;
  std::string name;
};

int main() {

  vector<string> v1 = {"java", "hello java", "this is a test"};
  vector<string> v2;
  std::copy_if(v1.begin(), v1.end(), std::back_inserter(v2),
               [](string i) { return has_ending(i, "java"); });

  for (auto s : v2) {
    cout << s << endl;
  }

  string s = "abc+dkkdks";
  string prefix = "abc";
  if (HavePrefix(s, prefix)) {
    cout << s << " have prefix: " << prefix << endl;
  }

  return 0;
}
