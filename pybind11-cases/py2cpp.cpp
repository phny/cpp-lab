#include <iostream>
#include <pybind11/pybind11.h>

using namespace std;
namespace py = pybind11;

int add(int i, int j) { return i + j; }

float add(float f1, float f2) { return f1 + f2; }

double add(double a, double b) { return a + b; }


class Hello {
public:
  Hello() {}
  void say(const std::string s) { std::cout << s << std::endl; }
};

PYBIND11_MODULE(py2cpp, m) {
  m.doc() = "pybind11 example";
  m.def("add", static_cast<int (*)(int, int)>(&add), "add two int number");
  m.def("add", static_cast<float (*)(float, float)>(&add),
        "add two float number");
  m.def("add", [](const double a, const double b) {});

  py::class_<Hello>(m, "Hello").def(py::init<>()).def("say", &Hello::say);
}
