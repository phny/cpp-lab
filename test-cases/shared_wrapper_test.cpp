/*************************************************************************
        > File Name: shared_wrapper.cpp
        > Author:
        > Mail:
        > Created Time: 2020年01月08日 星期三 15时38分33秒
 ************************************************************************/

#include <iostream>

using namespace std;

template <typename T> class smart_ptr {
public:
  explicit smart_ptr(T *ptr = nullptr) : ptr_(ptr) {}
  ~smart_ptr() { delete ptr_; }

  T &operator*() const { return *ptr_; }
  T *operator->() const { return ptr_; }
  operator bool() const { return ptr_; }

  T *get() const { return ptr_; }

private:
  T *ptr_;
};

int main() {
  cout << "hello world" << endl;
  return 0;
}
