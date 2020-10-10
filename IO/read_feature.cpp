#include <fstream>
#include <iostream>
#include <string>

#include "utils/io_utils.hpp"

using namespace std;

/// @brief 对特征数据进行归一化
static void normalize_feature(float *data, int len) {
  float sum = .0f;
  for (int i = 0; i < len; i++) {
    sum += data[i] * data[i];
  }
  sum = std::sqrt(sum);
  for (int i = 0; i < len; i++) {
    data[i] /= sum;
  }
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " <file_path>" << std::endl;
    exit(-1);
  }

  string file_path = argv[1];
  int64_t file_size = GetFileSize(file_path);

  std::ifstream in(file_path, std::ios::binary);
  char *feature_buff = new char[file_size];
  in.read(feature_buff, file_size);

  float *tmp = reinterpret_cast<float *>(feature_buff);

  // 归一化特征
  for (int i = 0; i < file_size / 4 / 256; i++) {
    normalize_feature(tmp + i * 256, 256);
  }

  in.close();

  // save to txt file
  float *f = reinterpret_cast<float *>(feature_buff);
  std::ofstream out("./cpp_feature.txt");
  for (int i = 0; i < file_size / 4; i++) {
    if (i != 0 && i % 256 == 0) {
      out << std::endl;
    }
    out << f[i] << " ";
  }
  out.close();

  return 0;
}
