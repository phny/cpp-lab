#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  std::vector<int> v{5, 6, 4, 3, 2, 6, 7, 9, 3};

  std::nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
  std::cout << "The median is " << v[v.size() / 2] << '\n';
  for_each(v.begin(), v.end(), [](const int i) { cout << i << " "; });
  cout << endl;

  std::nth_element(v.begin(), v.begin() + 1, v.end(), std::greater<int>());
  std::cout << "The second largest element is " << v[1] << '\n';
  for_each(v.begin(), v.end(), [](const int i) { cout << i << " "; });
  cout << endl;
}