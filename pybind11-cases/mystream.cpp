#include <exception>
#include <iostream>
#include <ostream>
#include <string>

#include "pybind11/complex.h"
#include "pybind11/functional.h"
#include "pybind11/iostream.h"
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

using namespace std;

namespace py = pybind11;

void test_istream(std::istream &is) {
  std::string s;
  is >> s;
  std::cout << s << std::endl;
}

void test_ostream(std::ostream &os) {
  std::string s = "test string";
  os << s;
}

void test_func() { std::cout << "test func" << std::endl; }

class SearchEngineException : public std::runtime_error {
public:
  explicit SearchEngineException(const std::string &msg)
      : std::runtime_error(msg) {}
};

class Person {
public:
  Person() = default;
  void GetName(int a);

private:
  std::string name;
};

void Person::GetName(int a) {
  std::cout << a << std::endl;
  throw SearchEngineException("se exception");
  cout << "after throw exception" << endl;
}

PYBIND11_MODULE(mystream, m) {
  m.doc() = "stream test";

  m.def("test_func", &test_func);
  m.def("test_istream", &test_istream);
  m.def("test_ostream", &test_ostream);

  // 用lambda表达式封装类的成员函数
  py::class_<Person>(m, "Person")
      .def(py::init<>())
      .def("GetName", [](Person &self, std::string name, int age) {
        std::cout << "Name: " << name << std::endl;
        self.GetName(age);
      });
}