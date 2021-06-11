#include <cstring>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

void test1() {
  float *data1 = new float[10];
  for (size_t i = 0; i < 10; i++) {
    data1[i] = i + 0.23;
  }
  float *data2 = new float[10];
  for (size_t i = 0; i < 10; i++) {
    data2[i] = i + 0.33;
  }

  std::shared_ptr<float> sp(data1);
  for (size_t i = 0; i < 10; i++) {
    cout << sp.get()[i] << " ";
  }

  cout << endl;

  float *p = sp.get();
  memcpy((char *)p, data2, sizeof(float) * 10);
  for (size_t i = 0; i < 10; i++) {
    cout << sp.get()[i] << " ";
  }
  cout << endl;

  delete[] data2;
}

void test2(float *src, float *dst, int n) {
  memcpy((char *)dst, src, sizeof(float) * n);
}

int main(int argc, char *argv[]) {
  // test1();
  float *data1 = new float[10];
  for (size_t i = 0; i < 10; i++) {
    data1[i] = i + 0.23;
  }
  std::shared_ptr<float> sp1(data1);
  cout << "sp1 data: " << endl;
  for (size_t i = 0; i < 10; i++) {
    cout << sp1.get()[i] << " ";
  }
  cout << endl;

  float *data2 = new float[10];
  for (size_t i = 0; i < 10; i++) {
    data2[i] = i + 0.33;
  }
  std::shared_ptr<float> sp2(data2);
  cout << "sp2 data: " << endl;
  for (size_t i = 0; i < 10; i++) {
    cout << sp2.get()[i] << " ";
  }
  cout << endl;

  test2(sp1.get(), sp2.get(), 10);

  cout << "after call test2, sp2 data: " << endl;
  for (size_t i = 0; i < 10; i++) {
    cout << sp2.get()[i] << " ";
  }
  cout << endl;

  return 0;
}