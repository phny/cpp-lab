#include <iostream>
using namespace std;

class StupidClass {
  int flag;

public:
  StupidClass(int flag) : flag(flag) { cout << "Constructor " << flag << endl; }
  ~StupidClass() { cout << "Destructor " << flag << endl; }
  StupidClass(const StupidClass &rhs) {
    cout << "Copy Constructor *this=" << flag << " rhs=" << rhs.flag << endl;
  }
  StupidClass &operator=(const StupidClass &rhs) {
    cout << "Operator = *this=" << flag << " rhs=" << rhs.flag << endl;
    return *this;
  }
  StupidClass &operator+=(const StupidClass &rhs) {
    cout << "Operator += *this=" << flag << " rhs=" << rhs.flag << endl;
    flag += rhs.flag;
    return *this;
  }
};

int main() {
  StupidClass var1(1), var2(2);
  StupidClass var3 = var1 += var2;

  return 0;
}
