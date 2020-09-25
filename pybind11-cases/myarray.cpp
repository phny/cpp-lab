#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include <pybind11/functional.h>
#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

using namespace std;
namespace py = pybind11;

PYBIND11_MAKE_OPAQUE(py::array_t<int64_t>);
PYBIND11_MAKE_OPAQUE(const py::array_t<int64_t>);
PYBIND11_MAKE_OPAQUE(std::vector<int64_t>);

void ArrayTest(const py::array_t<int64_t> &in_arr,
               py::array_t<int64_t> &out_arr) {
  for (int i = 0; i < in_arr.size(); i++) {
    out_arr.mutable_at(i) = in_arr.at(i);
  }
}

void ArrayTest2(const py::array_t<int64_t> &in_arr) {
  for (int i = 0; i < in_arr.size(); i++) {
    std::cout << in_arr.at(i) << std::endl;
  }
}

void ArrayTest3(py::array_t<int64_t> &in_arr) {
  for (int i = 0; i < in_arr.size(); i++) {
    std::cout << in_arr.at(i) << std::endl;
  }
}

PYBIND11_MODULE(myarray, m) {
  /// @brief 简单的说明文档
  m.doc() = "pybind11 example";

  m.def("ArrayTest", &ArrayTest);
  m.def("ArrayTest2", &ArrayTest2);
  m.def("ArrayTest3", &ArrayTest3);
}