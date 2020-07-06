#include <iostream>
#include <string>

#include <pybind11/pybind11.h>

using namespace std;
namespace py = pybind11;

// 普通函数重载
int add(int i, int j) { return i + j; }

float add(float f1, float f2) { return f1 + f2; }

double add(double a, double b) { return a + b; }

// 类
class Hello {
public:
  Hello() {}
  Hello(std::string name) {
    this->name = name;
  }
  Hello(std::string name, int age) {
    this->name = name;
    this->age = age;
  }
  void say(const std::string s) { 
    std::cout << s << std::endl; 
  }
  void good() {
    std::cout << "this is a test" << std::endl;
  }

private:
  std::string name;
  int32_t age;
};


PYBIND11_MODULE(py2cpp, m) {
  m.doc() = "pybind11 example";
  m.def("add", static_cast<int (*)(int, int)>(&add), "add two int number");
  m.def("add", static_cast<float (*)(float, float)>(&add),
        "add two float number");
  m.def("add", [](const double a, const double b) {
    return a + b;
  });

  py::class_<Hello>(m, "Hello")
      .def(py::init<>())
      .def(py::init<std::string>())
      .def(py::init<std::string, int32_t>())
      .def("say", static_cast<void(Hello::*)(const std::string)>(&Hello::say))
      // or
      // .def("good", static_cast<void (Hello::*)()>(&Hello::good));
      .def("good", &Hello::good);
}
