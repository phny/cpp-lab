#include <fstream>
#include <iostream>
#include <string>

#include <Eigen/Dense>

#include "utils/io_utils.hpp"

using namespace std;
using namespace Eigen;

typedef Matrix<float, 256, 1> Vector256f;

/// @brief 使用寄存器方式来加速计算向量点积，注意 n 必须是 4 的倍数
static float Avx2DotProduct(const float *a, const float *b, int n) {
  float v[8];
  float prod = 0;
  int step = 8; // avx2 __m256 can hold 8 floats
  int epoch = n / step;
  for (int i = 0; i < epoch; i++) {
    __m256 vec1 = _mm256_loadu_ps(a + i * step);      // from memory to ymm1
    __m256 vec2 = _mm256_loadu_ps(b + i * step);      // from memory to ymm2
    __m256 prod_sum = _mm256_dp_ps(vec1, vec2, 0xFF); // dot product
    _mm256_storeu_ps(v, prod_sum);                    // form ymm3 to memory
    prod += (v[0] + v[4]);                            // get the result
  }
  return prod;
}

///@brief 对特征数据进行归一化
void Normalize(float *src, int dim, float *dst) {
  float *src_pointer = src;
  float *dst_pointer = dst;
  const float norm = sqrt(Avx2DotProduct(src_pointer, src_pointer, dim));
  float scale = 1.0 / norm;
  for (uint32_t ind = 0; ind < dim; ind++) {
    *dst_pointer = *src_pointer++ * scale;
    dst_pointer++;
  }
}

/// @brief 读取特征
/// @param[in] path 文件路径
/// @param[out] features 特征首地址,函数内部分配内存
static void LoadFeature(const std::string path, float *&features) {
  std::ifstream in(path, std::ios::binary);
  int64_t file_size = GetFileSize(path);
  features = new float[file_size / sizeof(float)];
  in.read((char *)features, file_size);
  in.close();
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cerr << "Usage: <feature_path>" << endl;
    exit(-1);
  }
  std::string path = argv[1];

  float *features = nullptr;
  LoadFeature(path, features);
  Vector256f v1(features);
  Vector256f v2(features + 256);
  v1.normalize();
  v2.normalize();
  float *p1 = v1.data();
  float *p2 = v2.data();

  cout << Avx2DotProduct(p1, p2, 256) << endl;
  cout << Avx2DotProduct(features, features, 256) << endl;

  cout << v1.dot(v1) << endl;

  return 0;
}