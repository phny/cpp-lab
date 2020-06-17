/*************************************************************************
        > File Name: sort_pointer_vector.cpp
        > Author:
        > Mail:
        > Created Time: 2020年06月14日 星期日 10时44分15秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct A {
  int age;
  string name;
  A(int age, string name) {
    this->age = age;
    this->name = name;
  }
};

int main() {
  vector<struct A *> v;
  for (int i = 10; i >= 0; i--) {
    struct A *p = new struct A(i, "name_" + std::to_string(i));
    v.push_back(p);
  }

  std::sort(v.begin(), v.end(), [](struct A *left, struct A *right) {
    return left->age < right->age;
  });

  for (int i = 0; i < 10; i++) {
    cout << v[i]->age << ": " << v[i]->name << endl;
  }

  return 0;
}
