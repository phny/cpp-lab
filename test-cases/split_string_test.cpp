/*************************************************************************
        > File Name: split_string_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年04月02日 星期四 17时34分32秒
 ************************************************************************/

#include <iostream>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

void SplitString(const std::string &s, std::vector<uint32_t> &v,
                 const std::string &c) {
  std::string::size_type pos1, pos2;
  pos2 = s.find(c);
  pos1 = 0;
  while (std::string::npos != pos2) {
    v.push_back(std::stoi(s.substr(pos1, pos2 - pos1)));

    pos1 = pos2 + c.size();
    pos2 = s.find(c, pos1);
  }
  if (pos1 != s.length())
    v.push_back(std::stoi(s.substr(pos1)));
}

vector<string> split(const string &str, const string &delim) {
  vector<string> res;
  if ("" == str)
    return res;
  //先将要切割的字符串从string类型转换为char*类型
  char *strs = new char[str.length() + 1]; //不要忘了
  strcpy(strs, str.c_str());

  char *d = new char[delim.length() + 1];
  strcpy(d, delim.c_str());

  char *p = strtok(strs, d);
  while (p) {
    string s = p;     //分割得到的字符串转换为string型
    res.push_back(s); //存入结果数组
    p = strtok(NULL, d);
  }

  return res;
}

int main() {
  vector<string> v;
  v = split(" 7643775671002806397 ", " ");
  for (auto i : v) {
    cout << i << endl;
  }

  return 0;
}
