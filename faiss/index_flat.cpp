#include <fstream>
#include <iostream>
#include <string>

#include <faiss/AutoTune.h>
#include <faiss/AuxIndexStructures.h>
#include <faiss/Index.h>
#include <faiss/MetaIndexes.h>

#include "utils/io_utils.hpp"
#include "utils/timer.hpp"

using namespace std;

/// @brief 读取特征
/// @param[in] feature_path 特征路径
/// @param[in] only_feature 是否带id
/// @param[out] ids_ptr 特征id
/// @param[out] feature_ptr 特征
/// @return feature_num
int64_t ReadFeatures(const string feature_path, bool only_feature,
                     long *&ids_ptr, float *&features_ptr);

void SaveResultToFile(const string file_path, const int64_t feature_num,
                      const int64_t topk, const long *labels,
                      const float *distance);

int main(int argc, char *argv[]) {
  // parse args
  if (argc < 3) {
    cout << "uasge: <feature_path> [only_feature] <save_dir>" << endl;
    exit(-1);
  }
  string feature_path = argv[1];
  bool only_feature = argc > 2 ? std::stoi(argv[2]) : false;
  string save_dir = argv[3];
  if (save_dir.back() != '/') {
    save_dir += "/";
  }
  CreateDirectoryIfNotExists(save_dir);

  // read data from file
  long *ids_ptr = nullptr;
  float *features_ptr = nullptr;
  int64_t feature_num =
      ReadFeatures(feature_path, only_feature, ids_ptr, features_ptr);
  cout << "feature_num: " << feature_num << endl;

  // create index
  int64_t feature_dim = 256;
  string index_type = "Flat";
  // double nprobe = 32;
  faiss::Index *faiss_index =
      faiss::index_factory(feature_dim, index_type.c_str(), faiss::METRIC_L2);
  // faiss::ParameterSpace().set_index_parameter(index, "nprobe", nprobe); //
  // Flat index not support
  faiss::IndexIDMap *index = new faiss::IndexIDMap(faiss_index);

  // train index
  cout << "train index.." << endl;
  // index->train(feature_num, features_ptr);
  cout << "finish train index.." << endl;

  // add features
  cout << "add features.." << endl;
  // index->add(feature_num, features_ptr);
  index->add_with_ids(feature_num, features_ptr, ids_ptr);
  cout << "finish add features.." << endl;
  cout << index->ntotal << endl;

  // search
  float *distance = new float[feature_num * 64];
  long *labels = new long[feature_num * 64];
  cout << "search.." << endl;
  int64_t topk = 64;
  {
    TimeAccumulator timer("time of search");
    index->search(1, features_ptr, topk, distance, labels);
  }
  cout << "finish search.." << endl;

  // save result
  {
    TimeAccumulator timer("time of save result");
    SaveResultToFile(save_dir + "result.txt", feature_num, topk, labels,
                     distance);
  }

  long *removed_ids = new long[6];
  removed_ids[0] = 1;
  removed_ids[1] = 196033;
  removed_ids[2] = 55948;
  removed_ids[3] = 105925;
  removed_ids[4] = 78278;
  removed_ids[5] = 22833;
  faiss::IDSelectorBatch sel(6, removed_ids);
  cout << "remove ids.." << endl;
  {
    TimeAccumulator timer("time of remove ids");
    index->remove_ids(sel);
  }
  cout << "finish remove ids.." << endl;
  cout << index->ntotal << endl;

  {
    // search after remove
    TimeAccumulator timer("time of search");
    index->search(1, features_ptr, topk, distance, labels);
  }
  // save remove search result
  {
    TimeAccumulator timer("time of save result");
    SaveResultToFile(save_dir + "result1.txt", feature_num, topk, labels,
                     distance);
  }

  delete index;
  delete ids_ptr;
  delete features_ptr;

  return 0;
}

int64_t ReadFeatures(const string feature_path, bool only_feature,
                     long *&ids_ptr, float *&features_ptr) {
  int64_t feature_size = only_feature ? 1024 : 1032;
  int64_t feature_num = GetFileSize(feature_path) / feature_size;
  // 分配空间
  ids_ptr = new long[feature_num];
  features_ptr = new float[feature_num * 256];
  std::ifstream in(feature_path, std::ios::binary);
  if (only_feature) {
    for (size_t i = 0; i < feature_num; i++) {
      ids_ptr[i] = i;
      in.read(reinterpret_cast<char *>(&features_ptr[i * 256]),
              sizeof(float) * 256);
    }
  } else {
    for (size_t i = 0; i < feature_num; i++) {
      in.read(reinterpret_cast<char *>(&ids_ptr[i]), sizeof(int64_t));
      in.read(reinterpret_cast<char *>(&features_ptr[i * 256]),
              sizeof(float) * 256);
    }
  }
  in.close();

  return feature_num;
}

void SaveResultToFile(const string file_path, const int64_t feature_num,
                      const int64_t topk, const long *labels,
                      const float *distance) {
  std::ofstream out(file_path);
  for (size_t i = 0; i < feature_num; i++) {
    for (size_t j = 0; j < topk; j++) {
      out << labels[i * topk + j] << ":" << distance[i * topk + j] << " ";
    }
    out << endl;
  }

  out.close();
}