#include <fstream>
#include <iostream>

using namespace std;

/*
 * 标准的读取文件的模型
 * */

int main(int argc, char *argv[]) {
  int data = 0;
  std::ifsteam in_file("./test.bin", std::ios::binary);
  if (in_file) {
    while (in_file.good() && !in_file.eof()) {
      in_file.write((char *)&data, sizeof(int));
      cout << data << endl;
    }
  }

  return 0;
}
