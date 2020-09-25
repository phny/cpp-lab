#include <iomanip>
#include <iostream>
#include <string>

#include <pybind11/functional.h>
#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>

using namespace std;
namespace py = pybind11;

/// @note 参考链接:
/// https://pybind11.readthedocs.io/en/stable/advanced/cast/stl.html#opaque
PYBIND11_MAKE_OPAQUE(std::vector<int>);
PYBIND11_MAKE_OPAQUE(std::vector<std::string>);
PYBIND11_MAKE_OPAQUE(char *);

/// @brief 枚举类型
enum QuantizeMode : uint8_t { FP32 = 0, INT8 };

/// @brief 普通结构体
struct MyStruct {
  uint64_t a = -1;
  uint32_t b = -1;
  int64_t c = -1;
  int32_t d = -1;
  float f;
  char *path = nullptr;
  ~MyStruct() {
    if (path) {
      delete path;
    }
  }
};

struct MyType {
  const char *a = nullptr;
  ~MyType() {
    if (a)
      delete a;
  }
};

/// @brief C++ 普通的结构体
struct SearchEngineConfig {
  std::string search_engine_type =
      ""; ///< SearchEngine 的类型，目前支持以下几种:
  ///  SearchEngine, ShardSearchEngine
  std::vector<int> gpu_ids = {0}; ///< gpu 设备号，支持多卡
  std::string shard_mode = "DB"; ///< 分卡模式，DB为分底库，Query为分查询库
  std::string index_type = "auto"; ///< 索引类型，与 faiss 的类型字符串一致
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

// C++ 普通的类
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

/// @brief 结构体中的纯C数组
struct a_t {
  int b[10];
};

/// @brief void* 作为函数的参数
void foo_null(void *p) { std::cout << p << std::endl; }

/// @brief char* 作为函数的参数
void print_char_str(const char *c) {
  string s(c);
  std::cout << s << std::endl;
}

/// @brief char* 作为返回值
char *return_char_ptr() { return (char *)"1234567890"; }

/// @brief float* 作为函数的参数
void float_ptr_func(const float *f_ptr, int n) {
  std::cout << std::setiosflags(ios::fixed) << std::endl;
  for (int i = 0; i < n; i++) {
    std::cout << *(f_ptr + i) << std::endl;
  }
}

/// @brief int64_t* 作为函数的参数
void int_ptr_func(const int64_t *i_ptr, int n) {
  std::cout << std::setiosflags(ios::fixed) << std::endl;
  for (int i = 0; i < n; i++) {
    std::cout << *(i_ptr + i) << std::endl;
  }
}

/// @brief float* 作为函数的输出参数
/// @note 外面需要提前申请好output指针的内存空间
void float_ptr_as_output(int32_t n, float *output) {
  float s = 0.23;
  for (int i = 0; i < n; i++) {
    *(output + i) = i + s;
  }
}

/// @brief int64_t* 作为函数的输出参数
/// @note 外面需要提前申请好output指针的内存空间
void int_ptr_as_output(int32_t n, int64_t *output) {
  int64_t s = 100;
  for (int i = 0; i < n; i++) {
    *(output + i) = i + s;
  }
}

/// @brief 自定义的类型
typedef float *ScoresPtr;
typedef int64_t *IndexesPtr;

/// @brief 结构体指针作为函数的参数
void struct_pointer_as_input_param(MyStruct *my_struct) {
  std::cout << "a:" << my_struct->a << std::endl;
  std::cout << "b:" << my_struct->b << std::endl;
  std::cout << "c:" << my_struct->c << std::endl;
  std::cout << "d:" << my_struct->d << std::endl;
  std::cout << "f:" << my_struct->f << std::endl;
}

/// ---------------------------------

PYBIND11_MODULE(py2cpp, m) {
  /// @brief 简单的说明文档
  m.doc() = "pybind11 example";

  /// @brief 暴露枚举类型
  py::enum_<QuantizeMode>(m, "QuantizeMode")
      .value("FP32", QuantizeMode::FP32)
      .value("INT8", QuantizeMode::INT8)
      .export_values();

  py::class_<MyStruct>(m, "MyStruct")
      .def(py::init())
      .def_readwrite("a", &MyStruct::a)
      .def_readwrite("b", &MyStruct::b)
      .def_readwrite("c", &MyStruct::c)
      .def_readwrite("d", &MyStruct::d)
      .def_readwrite("f", &MyStruct::f)
      .def_property(
          "path", [](const MyStruct &self) { return self.path; },
          [](MyStruct &self, const char *new_a) { self.path = strdup(new_a); });

  /// @brief 暴露C++结构体中的字段
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

  /// @brief 暴露普通的函数
  m.def("add", static_cast<int (*)(int, int)>(&add), "add two int number");
  m.def("add", static_cast<float (*)(float, float)>(&add),
        "add two float number");

  /// @brief 使用 lambda 表达式
  m.def("add", [](const double a, const double b) { return a + b; });

  /// @brief 使用关键字参数
  m.def("sum", static_cast<int (*)(int, int)>(&sum), py::arg("a"),
        py::arg("b") = 100);

  /// @brief 暴露简单的C++类
  py::class_<Hello>(m, "Hello")
      .def(py::init<>())
      .def(py::init<std::string>())
      .def(py::init<std::string, int32_t>())
      .def("say", static_cast<void (Hello::*)(const std::string)>(&Hello::say))
      .def("good", &Hello::good);

  /// @brief 暴露结构体中的纯C数组
  py::class_<a_t>(m, "a_t")
      .def(py::init<>())
      .def_property_readonly("b", [](py::object &obj) {
        a_t &o = obj.cast<a_t &>();
        return py::array_t<int>{10, o.b, obj};
      });

  /// @brief char* 作为函数的参数
  m.def("print_char_str", &print_char_str);

  /// @brief char* 作为返回值
  m.def("return_char_ptr", &return_char_ptr);

  /// @brief float * 作为函数参数
  m.def("float_ptr_func", [](char *ptr, int n) {
    float *f_ptr = (float *)ptr;
    float_ptr_func(f_ptr, n);
  });

  /// @brief int * 作为函数参数
  m.def("int_ptr_func", [](char *ptr, int n) {
    int64_t *i_ptr = (int64_t *)ptr;
    int_ptr_func(i_ptr, n);
  });

  /// @brief 将内置类型绑定为自定义的类型
  py::class_<float *>(m, "ScoresPtr").def(py::init());

  /// @brief 将内置类型绑定为自定义的类型
  py::class_<int64_t *>(m, "IndexesPtr").def(py::init());

  /// @brief float * 作为函数输出参数
  m.def("float_ptr_as_output", [](int n, ScoresPtr ptr) {
    float *f_ptr = (float *)(ptr);
    float_ptr_as_output(n, f_ptr);
    for (int i = 0; i < n; i++) {
      std::cout << *((float *)ptr + i) << std::endl;
    }
  });

  /// @brief 制作不透明类型
  py::class_<std::vector<std::string>>(m, "StringList")
      .def(py::init<>())
      .def("__getitem__",
           [](std::vector<std::string> &v, int i) {
             if (i >= v.size() || i < 0)
               throw py::index_error();
             return v[i];
           },
           py::return_value_policy::reference)
      .def("__setitem__",
           [](std::vector<std::string> &s, py::slice slice,
              const std::string &value) {
             size_t start, stop, step, slicelength;
             if (!slice.compute(s.size(), &start, &stop, &step, &slicelength))
               throw py::error_already_set();
             if (slicelength != value.size())
               throw std::runtime_error("Left and right hand size of slice "
                                        "assignment have different sizes!");
             for (size_t i = 0; i < slicelength; ++i) {
               s[start] = value[i];
               start += step;
             }
           })
      .def("pop_back", &std::vector<std::string>::pop_back)
      /* There are multiple versions of push_back(), etc. Select the right ones.
       */
      .def("push_back",
           (void (std::vector<std::string>::*)(const std::string &)) &
               std::vector<std::string>::push_back)
      .def("back", (std::string & (std::vector<std::string>::*)()) &
                       std::vector<std::string>::back)
      .def("__len__",
           [](const std::vector<std::string> &v) { return v.size(); })
      .def("__iter__",
           [](std::vector<std::string> &v) {
             return py::make_iterator(v.begin(), v.end());
           },
           py::keep_alive<0, 1>());

  /// @brief 暴露自定义类型1
  py::class_<void *>(m, "VoidPtr").def(py::init());

  /// @brief 暴露自定义类型2
  py::class_<MyType>(m, "MyType")
      .def(py::init<>())
      .def_property(
          "a", [](const MyType &self) { return self.a; },
          [](MyType &self, const char *new_a) { self.a = strdup(new_a); });

  /// @brief 结构体指针作为函数的输入参数
  m.def("struct_pointer_as_input_param", &struct_pointer_as_input_param);
}
