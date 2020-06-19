#ifndef STRING_UTILS_H_
#define STRING_UTILS_H_

#include <iostream>
#include <string.h>
#include <vector>

/// @brief 是否以指定的字符串结尾
static bool HaveEnding(std::string const &fullString,
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

/// @brief 按照指定的字符切割字符串
std::vector<std::string> StringSplit(const std::string &str,
                                     const std::string &delim) {
  std::vector<std::string> res;
  if ("" == str)
    return res;
  //先将要切割的字符串从string类型转换为char*类型
  char *strs = new char[str.length() + 1]; //不要忘了
  strcpy(strs, str.c_str());

  char *d = new char[delim.length() + 1];
  strcpy(d, delim.c_str());

  char *p = strtok(strs, d);
  while (p) {
    //分割得到的字符串转换为string类型
    std::string s = p;
    res.push_back(s);
    p = strtok(NULL, d);
  }

  return res;
}

#endif