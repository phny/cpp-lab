/*************************************************************************
        > File Name: vector_substring_sort_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年04月14日 星期二 19时54分27秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  vector<string> v1{"/home/SENSETIME/heyulin/learn/cpu-gpu-mem-info/test3.txt",
                    "/home/SENSETIME/heyulin/learn/cpu-gpu-mem-info/test2.txt",
                    "/home/SENSETIME/heyulin/learn/cpu-gpu-mem-info/test1.txt"};
  vector<string> v2{"/home/SENSETIME/heyulin/learn/cpu-gpu-mem-info/test3.txt",
                    "/home/SENSETIME/heyulin/learn/cpu-gpu-mem-info/test2.txt",
                    "/home/SENSETIME/heyulin/learn/cpu-gpu-mem-info/test1.txt"};

  std::sort(std::begin(v1), std::end(v1),
            [](std::string const &a, std::string const &b) {
              return std::lexicographical_compare(
                  a.begin() + a.find_last_of('/'), a.end(),
                  b.begin() + b.find_last_of('/'), b.end());
            });
  std::sort(std::begin(v2), std::end(v2),
            [](std::string const &a, std::string const &b) {
              return std::lexicographical_compare(
                  a.begin() + a.find_last_of('/'), a.end(),
                  b.begin() + b.find_last_of('/'), b.end());
            });

  for (int i = 0; i < v1.size(); i++) {
    cout << v1[i] << endl;
  }
  for (int i = 0; i < v2.size(); i++) {
    cout << v2[i] << endl;
  }

  cout << "create mapping relation ship" << endl;
  std::map<std::string, std::string> v1_to_v2_map;
  std::transform(v1.begin(), v1.end(), v2.begin(),
                 std::inserter(v1_to_v2_map, v1_to_v2_map.end()),
                 [](string a, string b) { return std::make_pair(a, b); });

  for (auto &item : v1_to_v2_map) {
    cout << item.first << ":" << item.second << endl;
  }

  return 0;
}
