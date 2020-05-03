/*************************************************************************
        > File Name: stack_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年03月21日 星期六 23时45分55秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

template <typename Dtype> class Stack {
private:
  std::vector<Dtype> arr;
  int count;
  int n;

public:
  Stack(const Dtype n);
  ~Stack();
  // Stack(const Dtype& other);
  Dtype &operator=(const Dtype &other);
  bool push(Dtype s);
  Dtype pop();
};

template <typename Dtype> Stack<Dtype>::Stack(const Dtype n) { arr.resize(n); }

template <typename Dtype> Stack<Dtype>::~Stack() { arr.clear(); }

template <typename Dtype> bool Stack<Dtype>::push(Dtype n) { arr.push_back(n); }

template <typename Dtype> Dtype Stack<Dtype>::pop() {
  Dtype ret = arr.back();
  arr.pop_back();
  return ret;
}

int main() {
  Stack<int> s(10);
  s.push(1);
  s.push(2);

  std::cout << s.pop() << s.pop() << std::endl;

  return 0;
}
