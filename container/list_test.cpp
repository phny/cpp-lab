#include <iostream>
#include <list>

using namespace std;

int main() {
  std::list<int> c = {1, 2, 3};
  std::cout << "The list holds: ";
  for (auto &el : c)
    std::cout << el << ' ';
  std::cout << '\n';
  c.resize(5);
  std::cout << "After resize up to 5: ";
  for (auto &el : c)
    std::cout << el << ' ';
  std::cout << '\n';
  c.resize(2);
  std::cout << "After resize down to 2: ";
  for (auto &el : c)
    std::cout << el << ' ';
  std::cout << '\n';
  std::cout << "size: " << c.size() << std::endl;

  std::list<int> ll;
  ll.resize(10);
  for (auto i : ll) {
    cout << i << ' ';
  }
  cout << endl;

  ll.resize(3);
  ll.push_back(1);
  for (auto i : ll) {
    cout << i << ' ';
  }
  cout << endl;

  return 0;
}