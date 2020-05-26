/*************************************************************************
        > File Name: iftream_read_txt_file.cpp
        > Author:
        > Mail:
        > Created Time: 2020年05月25日 星期一 11时05分05秒
 ************************************************************************/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {
  std::ifstream in_file("./test.txt");

//   vector<string> v;

//  string line;
  // while (in_file >> line) {
  //    // 这样子读取会有默认的分隔符,每次不是读取一行文件
  //    v.push_back(line);
  //}
  // in_file.close();

  std::ifstream in_file2("./test.txt");
  string line;
  map<int64_t, int64_t> m; 

  if (in_file2.is_open()) {
    while (getline(in_file2, line)) {
      int64_t id1 = 0;
      int64_t id2 = 0;
      int32_t split_ind = line.find_last_of(':');
      id1 = std::stoi(line.substr(0, split_ind));
      id2 = std::stoi(line.substr(split_ind + 1, line.length()));
      m.insert({id1, id2});
    }
  }
  for (auto it = m.begin(); it != m.end(); it++) {
    cout << it->first << ": " << it->second << endl;
  }

  return 0;
}
