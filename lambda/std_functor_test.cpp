#include <iostream>
using namespace std;

/*
https://blog.csdn.net/K346K346/article/details/82818801
*/

class IsGreaterThanThresholdFunctor {
public:
  explicit IsGreaterThanThresholdFunctor(int t) : threshold(t) {}
  bool operator()(int num) const { return num > threshold ? true : false; }

private:
  const int threshold;
};

int RecallFunc(int *start, int *end, IsGreaterThanThresholdFunctor myFunctor) {
  int count = 0;
  for (int *i = start; i != end + 1; i++) {
    count = myFunctor(*i) ? count + 1 : count;
  }
  return count;
}

int main() {
  int a[5] = {10, 100, 11, 5, 19};
  int result = RecallFunc(a, a + 4, IsGreaterThanThresholdFunctor(10));
  cout << result << endl;
}
