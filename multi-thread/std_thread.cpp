#include <chrono>
#include <iostream>
#include <thread>
#include <utility>
#include <vector>

void f1(int n) {
  std::thread::id tid = std::this_thread::get_id();
  std::cout << "f id=" << tid << std::endl;
  for (int i = 0; i < 5; ++i) {
    std::cout << "Thread 1 executing\n";
    ++n;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
}

void f2(int &n) {
  std::thread::id tid = std::this_thread::get_id();
  std::cout << "f id=" << tid << std::endl;
  for (int i = 0; i < 5; ++i) {
    std::cout << "Thread 2 executing\n";
    ++n;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
}

class foo {
public:
  void bar() {
    std::thread::id tid = std::this_thread::get_id();
    std::cout << "f id=" << tid << std::endl;
    for (int i = 0; i < 5; ++i) {
      std::cout << "Thread 3 executing\n";
      ++n;
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
  }
  int n = 0;
};

class baz {
public:
  void operator()() {
    std::thread::id tid = std::this_thread::get_id();
    std::cout << "f id=" << tid << std::endl;
    for (int i = 0; i < 5; ++i) {
      std::cout << "Thread 4 executing\n";
      ++n;
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
  }
  int n = 0;
};

int main() {
  int n = 0;
  foo f;
  baz b;
  std::thread t1;                  // t1 is not a thread
  std::thread t2(f1, n + 1);       // pass by value
  std::thread t3(f2, std::ref(n)); // pass by reference
  std::thread t4(
      std::move(t3)); // t4 is now running f2(). t3 is no longer a thread
  std::thread t5(&foo::bar, &f); // t5 runs foo::bar() on object f
  std::thread t6(b);             // t6 runs baz::operator() on object b
  t2.join();
  t4.join();
  t5.join();
  t6.join();
  std::cout << "Final value of n is " << n << '\n';
  std::cout << "Final value of foo::n is " << f.n << '\n';

  std::vector<int> v;
  auto t = std::thread(
      [&v](int n) {
        std::cout << "thread use lambda" << std::endl;
        for (int i = 0; i < n; i++) {
          v.push_back(i);
        }
      },
      10);
  t.join();

  for (auto i : v) {
    std::cout << i << std::endl;
  }
}
