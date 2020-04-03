/*************************************************************************
	> File Name: split_string_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月02日 星期四 17时34分32秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


void SplitString(const std::string& s, std::vector<uint32_t>& v, const std::string& c){
  std::string::size_type pos1, pos2;
  pos2 = s.find(c);
  pos1 = 0;
  while(std::string::npos != pos2)
  {
    v.push_back(std::stoi(s.substr(pos1, pos2-pos1)));
 
    pos1 = pos2 + c.size();
    pos2 = s.find(c, pos1);
  }
  if(pos1 != s.length())
    v.push_back(std::stoi(s.substr(pos1)));
}

int main() {
    return 0;
}
