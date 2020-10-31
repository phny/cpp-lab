#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  // declaring vector of pairs
  vector<pair<int, std::vector<int>>> vect;

  // Initialising 1st and 2nd element of pairs
  // with array values
  int arr[] = {10, 20, 5, 40};
  std::vector<std::vector<int>> arr1 = {{30, 20}, {60, 39}, {20, 30}, {50, 39}};
  int n = sizeof(arr) / sizeof(arr[0]);

  // Entering values in vector of pairs
  for (int i = 0; i < n; i++)
    vect.push_back(make_pair(arr[i], arr1[i]));

  // Using sort() function to sort by 2nd element
  // of pair
  std::sort(vect.begin(), vect.end());

  // Printing the sorted vector(after using sort())
  cout << "The vector after sort operation is:\n";
  for (int i = 0; i < n; i++) {
    // "first" and "second" are used to access
    // 1st and 2nd element of pair respectively
    cout << vect[i].first << " ";
    for (auto t : vect[i].second) {
      cout << t << " ";
    }
    cout << endl;
  }
  return 0;
}