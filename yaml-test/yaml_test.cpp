#include "yaml-cpp/yaml.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
  const string config_path = argv[1];

  YAML::Node config = YAML::LoadFile(config_path);

  // json格式配置解析
  // // 解析数字
  // cout <<
  // config["data_loader"]["load_entity_set_config"]["feature_dim"].as<int>() <<
  // endl;

  // // 解析bool
  // cout << config["save_internal_result"].as<std::string>() << endl;

  // // 解析数组
  // auto gpu_ids =
  // config["full_cluster"]["GCN"]["search_engine_config"]["gpu_ids"]; for
  // (size_t i = 0; i < gpu_ids.size(); i++) {
  //     std::cout << gpu_ids[i].as<int>() << std::endl;
  // }

  // // 判断某一项的真值
  // if (config["full_cluster"]["GCN"]) {
  //    cout << "use gcn mode" << endl;
  // }

  // yaml 格式配置解析
  const std::string path = config["face"]["faiss_index_path"].as<std::string>();
  const float sub_thre = config["face"]["sub_thre"].as<float>();
  std::cout << path << std::endl;
  std::cout << sub_thre << std::endl;

  return 0;
}
