#include <iostream>
#include <string>

#include <pybind11/pybind11.h>

using namespace std;
namespace py = pybind11;

/// @brief CSTK 的模式
enum QuantizeMode : uint8_t { FP32 = 0, INT8 };

struct SearchEngineConfig {
  std::string search_engine_type =
      ""; ///< SearchEngine 的类型，目前支持以下几种:
  ///  SearchEngine, ShardSearchEngine
  std::vector<int> gpu_ids = {0}; ///< gpu 设备号，支持多卡
  std::string shard_mode = "DB"; ///< 分卡模式，DB为分底库，Query为分查询库
  std::string index_type = "auto"; ///< 索引类型，与 faiss 的类型字符串一致
  ///<   比如 "IVF2048, PQ32"
  ///< auto 则会自动推导索引类型
  uint32_t search_batch_size = 1024000; ///< 搜索的 batch size
  uint32_t feature_dim = 256;           ///< 特征的维度
  short nprobe = 32;                    ///< 检索时探测点的数量
  QuantizeMode quantize_mode = FP32;    ///< 计算使用的特征模式
  std::vector<std::string> index_datas; ///< 离线索引数据，可以有多份
};

// 普通函数重载
int add(int i, int j) { return i + j; }

float add(float f1, float f2) { return f1 + f2; }

double add(double a, double b) { return a + b; }

// default arguments
int sum(int a, int b = 100) { return a + b; }

// 类
class Hello {
public:
  Hello() {}
  Hello(std::string name) { this->name = name; }
  Hello(std::string name, int age) {
    this->name = name;
    this->age = age;
  }
  void say(const std::string s) { std::cout << s << std::endl; }
  void good() { std::cout << "this is a test" << std::endl; }

private:
  std::string name;
  int32_t age;
};

PYBIND11_MODULE(py2cpp, m) {
  py::enum_<QuantizeMode>(m, "QuantizeMode")
      .value("FP32", QuantizeMode::FP32)
      .value("INT8", QuantizeMode::INT8)
      .export_values();

  py::class_<SearchEngineConfig>(m, "SearchEngineConfig")
      .def(py::init())
      .def_readwrite("search_engine_type",
                     &SearchEngineConfig::search_engine_type)
      .def_readwrite("gpu_ids", &SearchEngineConfig::gpu_ids)
      .def_readwrite("shard_mode", &SearchEngineConfig::shard_mode)
      .def_readwrite("index_type", &SearchEngineConfig::index_type)
      .def_readwrite("search_batch_size",
                     &SearchEngineConfig::search_batch_size)
      .def_readwrite("feature_dim", &SearchEngineConfig::feature_dim)
      .def_readwrite("nprobe", &SearchEngineConfig::nprobe)
      .def_readwrite("quantize_mode", &SearchEngineConfig::quantize_mode)
      .def_readwrite("index_datas", &SearchEngineConfig::index_datas);

  m.doc() = "pybind11 example";
  // 绑定普通函数
  m.def("add", static_cast<int (*)(int, int)>(&add), "add two int number");
  m.def("add", static_cast<float (*)(float, float)>(&add),
        "add two float number");
  m.def("add", [](const double a, const double b) { return a + b; });
  m.def("sum", static_cast<int (*)(int, int)>(&sum), py::arg("a"),
        py::arg("b") = 100);

  py::class_<Hello>(m, "Hello")
      .def(py::init<>())
      .def(py::init<std::string>())
      .def(py::init<std::string, int32_t>())
      .def("say", static_cast<void (Hello::*)(const std::string)>(&Hello::say))
      .def("good", &Hello::good);
}
