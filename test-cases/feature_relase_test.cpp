#include <iostream>
#include <vector>

using namespace std;

struct Feature {
  int64_t id = -1;      ///< feature id
  int32_t length = 0;   ///< feature length
  void *data = nullptr; ///< raw feature data

  ~Feature();
};

Feature::~Feature() {}

int main(int argc, char *argv[]) { return 0; }