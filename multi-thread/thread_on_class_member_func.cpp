#include <iostream>
#include <string>
#include <thread>
#include <vector>

using namespace std;

class Person {
public:
  Person() = default;
  Person(std::string name, int age);
  void read(std::vector<int> &v, std::string name);

private:
  std::string name;
  int age;
};

Person::Person(std::string name, int age) {
  this->name = name;
  this->age = age;
}

void Person::read(std::vector<int> &v, std::string name) {
  for (auto i : v) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  std::cout << "name: " << name << std::endl;
}

int main(int argc, char *argv[]) {
  std::vector<int> v{1, 2, 3, 4};
  Person p("Tom", 23);

  // 重要：作用与成员函数，在外面，需要一个实例，在类里面，第二个参数设置为 this
  // 即可
  std::thread t(&Person::read, p, std::ref(v), "Tom");
  t.join();

  return 0;
}