#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> A;
bool face_cmp(const A *x, const A *y) { return x != y; }

int main(int argc, char *argv[]) {

  vector<A *> vec;
  for (int i = 0; i < 100; i++) {
    vec.push_back(new vector<int>(i % 100, i * i));
  }

  vector<A *>::iterator it;
  sort(vec.begin(), vec.end(), face_cmp);

  return EXIT_SUCCESS;
}
