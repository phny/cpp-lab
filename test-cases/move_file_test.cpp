#include <cerrno>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void MoveFile(const string src_path, const string dst_path) {
  std::ifstream in(src_path, std::ios::in | std::ios::binary);
  std::ofstream out(dst_path, std::ios::out | std::ios::binary);
  out << in.rdbuf();
  std::remove(src_path.c_str());
  out.close();
  in.close();
}

int main() {
  string src = "/data/tmp/feature_0.bin";
  string dst = "/home/SENSETIME/heyulin/feature_0.bin";
  // 不能跨盘移动文件
  // if(std::rename(src.c_str(), dst.c_str()) < 0) {
  //  std::cout << strerror(errno) << '\n';
  //}

  MoveFile(src, dst);

  return 0;
}
