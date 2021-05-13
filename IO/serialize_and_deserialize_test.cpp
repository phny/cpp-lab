#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {

  vector<int64_t> v = {1, 2, 3, 400000, 5, 6, 7};

  std::ofstream out("v.bin", std::ios::binary);
  for (size_t i = 0; i < v.size(); i++) {
    out.write((char *)&(v[i]), sizeof(v[i]));
  }
  out.close();

  std::ifstream in("v.bin", std::ios::binary);
  for (size_t i = 0; i < v.size(); i++) {
    int64_t buffer;
    in.read((char *)&buffer, sizeof(buffer));
    std::cout << buffer << std::endl;
  }
  // in.close();

  std::string s = "12345678";
  std::ofstream out2("v1.bin", std::ios::binary);
  int64_t len = s.size();
  out2.write((char *)&len, sizeof(len));
  out2.write(s.c_str(), len);
  out2.close();

  std::cout << "--------------test2---------------" << std::endl;

  std::ifstream in2("v1.bin", std::ios::binary);
  int64_t ll;
  in2.read((char *)&ll, sizeof(ll));
  std::cout << ll << std::endl;
  char *sbuffer = new char[len];
  in2.read(sbuffer, ll);
  std::string ss(sbuffer, ll);
  std::cout << ss << std::endl;
  in2.close();
  delete[] sbuffer;

  return 0;
}