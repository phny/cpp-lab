#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "utils/io_utils.hpp"

using namespace std;
/*
int main() {
  std::vector<int> nb_left;
  std::vector<std::vector<int>> body_cluster;
  std::vector<int> v = {-1, -1, -1, 1, 1, 2, 2, 2, 3, 3, 4, 5, 5, 5, 5};

  int i = 0;
  for (; i < v.size(); i++) {
    if (v[i] < 0) {
      // 记录 nb_left
      nb_left.push_back(v[i]);
      continue;
    }
    break;
  }

  int start = i;         // 起始探测点
  int end = start + 1;   // 结束探测点
  int target = v[start]; // 临时目标

  for (int index = end; index < v.size(); index++) {
    if (v[index] != target) {
      end = index;
      std::vector<int> tmp(v.begin() + start, v.begin() + end);
      body_cluster.push_back(tmp);

      start = end;
      end = index + 1;
      target = v[start];

      continue;
    }
    end++;
  }
  // 添加最后的数据
  std::vector<int> last(v.begin() + start, v.begin() + end);
  body_cluster.push_back(last);

  // 输出结果
  for (auto &v : body_cluster) {
    for (auto &i : v) {
      cout << i << " ";
    }
    cout << endl;
  }

  return 0;
}
*/

uint64_t GenerateDataId(int32_t region_id, int32_t camera_id, int64_t timestamp,
                        int32_t sequence) {
  if (region_id < 1 || region_id >= 16384) {
    cout << "region id invalid: " << region_id << endl;
    exit(-1);
  }
  if (camera_id < 0 || camera_id >= 128) {
    cout << "camera id invalid: " << camera_id << endl;
    exit(-1);
  }
  if (sequence < 0 || sequence >= 1024) {
    cout << "sequence invalid: " << sequence << endl;
    exit(-1);
  }

  return static_cast<int64_t>(region_id) << 49 |
         static_cast<int64_t>(camera_id) << 42 |
         static_cast<int64_t>(timestamp) << 10 | static_cast<int64_t>(sequence);
}

/// @brief 从 id 中获取 camera_id
int64_t GetCameraIdFrom(const int64_t entity_id) {
  int64_t tmp = entity_id >> 42;
  return tmp & 0x000000000000007F;
}

/// @brief 从文件中加载所有行
void LoadVectorFromFile(const std::string &file_path,
                        std::vector<std::string> &vec) {
  std::ifstream in_file(file_path);

  if (!in_file) {
    std::cout << "can not open file: " << file_path << std::endl;
    exit(-1);
  }

  vec.clear();
  // 一次读取一行数据
  if (in_file.is_open()) {
    std::string line;
    while (std::getline(in_file, line)) {
      vec.push_back(line);
    }
  }

  in_file.close();
}

/// @brief 读取文本文件到数组中
template <typename Dtype>
void ReadLinesToVec(const std::string camera_ids_path,
                    std::vector<Dtype> &output_vec) {
  // 读取所有行
  std::vector<std::string> v;
  LoadVectorFromFile(camera_ids_path, v);
  output_vec = [&v]() -> std::vector<Dtype> {
    // 将 camera_ids 转换成 int32_t
    std::vector<Dtype> ret;
    std::stringstream oss;
    for (auto &item : v) {
      Dtype dst;
      oss << item;
      oss >> dst;
      cout << item << dst << endl;
      oss.clear();
      ret.push_back(dst);
    }
    return ret;
  }();
}

void float_ptr_as_output(int32_t n, float *output) {
  float s = 0.23;
  for (int i = 0; i < n; i++) {
    *(output + i) = i + s;
  }
}

int main() {
  std::string file_path =
      "/home/SENSETIME/heyulin/dev/search_engine/unit_tests/test_data/"
      "CI-TESTING-FEATURE24802/targets_db/target_db_120_256d.bin";
  std::ifstream in_file(file_path, std::ios::binary);
  int64_t file_size = GetFileSize(file_path);
  char *con = new char[file_size];
  in_file.read(con, file_size);
  float *f = (float *)con;

  for (int i = 0; i < file_size / sizeof(float); i++) {
    std::cout << *(f + i) << std::endl;
  }

  return 0;
}
