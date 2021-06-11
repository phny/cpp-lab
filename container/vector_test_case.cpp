#include <cstring>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class A {
public:
  A() = default;
  A(int x) : a(x) {
    cout << "construct func2" << endl;
    data = new float[a];
  }
  void Show() {
    for (size_t i = 0; i < a; i++) {
      cout << data[i] << " ";
    }
    cout << endl;
  }
  float *MutableData() { return data; }

private:
  int a;
  float *data = nullptr;
};

void test1() {
  float *data = new float[10];
  for (size_t i = 0; i < 10; i++) {
    data[i] = i + 0.23;
  }
  for (size_t i = 0; i < 10; i++) {
    cout << data[i] << " ";
  }
  cout << endl;

  cout << "--------------------------------" << endl;

  std::vector<float> v(data, data + 10);
  // v.assign(data, data + 10);
  for (auto i : v) {
    cout << i << " ";
  }
  cout << endl;

  delete[] data;
}

void test2() {
  float *d = new float[10];
  for (size_t i = 0; i < 10; i++) {
    d[i] = i;
  }

  std::vector<A> v(10, A(10));
  for (auto i : v) {
    i.Show();
  }

  for (auto i : v) {
    memcpy((char *)i.MutableData(), d, sizeof(float) * 10);
  }

  for (auto i : v) {
    i.Show();
  }
}

int main(int argc, char *argv[]) {
  test2();

  return 0;
}