#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int myints[] = {1, 2, 3, 1, 1, 2, 3, 4, 4, 5, 1, 1, 1};
  int len = sizeof(myints) / sizeof(int);
  vector<int> vec(myints, myints + len);
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  for (int x : vec)
    cout << x << ",";

  cout << endl;

  return 0;
}
