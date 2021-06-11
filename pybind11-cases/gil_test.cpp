#include <pybind11/pybind11.h>

namespace py = pybind11;

void loop(int num) {
  for (int i = 0; i < num; ++i) {
    for (int j = 0; j < num; ++j) {
      for (int k = 0; k < num; ++k) {
        double x = 1.0 * i * j * k;
      }
    }
  }
}

PYBIND11_MODULE(gil_test, m) {
  m.def("loop", &loop)
      .def("loop_without_gil", &loop, py::call_guard<py::gil_scoped_release>());
}
