#include <iomanip>
#include <iostream>
#include <string>

#include "pybind11/numpy.h"
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

using namespace std;
namespace py = pybind11;

/// @brief float* 作为函数的输出参数
/// @note 外面需要提前申请好output指针的内存空间: 修改结果不能返回到python端
void float_ptr_as_output(int32_t n, float *output) {
  float s = 0.23;
  for (int i = 0; i < n; i++) {
    *(output + i) = i + s;
  }
}

/// @brief py::array_t 测试: 修改结果可以返回python端
void test_py_array(py::array_t<int64_t> &arr, int n) {
  // arr.resize({1, n}, true);
  auto r = arr.mutable_unchecked();
  // for (int i = 0; i < n; i++) {
  //     r(0, i) = i * i;
  // }
  int64_t *p = (int64_t *)arr.data();
  for (int i = 0; i < n; i++) {
    // std::cout << *(p + i) << std::endl;
    *(p + i) = i * i;
  }
}

/// @brief py::array_t 测试: 修改结果可以返回python端
void test_py_array2(py::array_t<float> &arr, int n) {
  arr.resize({1, n}, true);
  auto r = arr.mutable_unchecked();
  for (int i = 0; i < n; i++) {
    r(0, i) = i * i;
  }
  float *p = (float *)arr.data();
  for (int i = 0; i < n; i++) {
    std::cout << *(p + i) << std::endl;
  }
}

/// @brief py::list 修改测试: 修改结果可以返回python端
void test_py_list(py::list &my_list, int n) {
  std::cout << my_list.size() << std::endl;
  for (int i = 0; i < my_list.size(); i++) {
    my_list[i] = i * i;
  }
}

/// @brief py::list append测试:  修改结果不能返回到python端
void test_py_list2(py::list &my_list, int n) {
  for (int i = 0; i < my_list.size(); i++) {
    my_list.append(i);
  }
}

/// --------------------------------------------------------

PYBIND11_MODULE(pyarray, m) {
  m.doc() = "demo sample";

  /// @brief float* 作为函数输出参数: 暂时发现会 core dumped
  m.def("float_ptr_as_output", [](int n, py::bytes &b) {
    float *f_ptr = (float *)(&b);
    float_ptr_as_output(n, f_ptr);
    std::cout << "finished float_ptr_as_output" << std::endl;
    for (int i = 0; i < n; i++) {
      std::cout << *(f_ptr + i) << std::endl;
    }
  });

  /// @brief test py::array_t
  m.def("test_py_array", &test_py_array);

  /// @brief test py::array_t
  m.def("test_py_array2", &test_py_array2);

  /// @brief test py::list
  m.def("test_py_list", &test_py_list);

  /// @brief test py::list
  m.def("test_py_list2", &test_py_list2);
}