#include <google/profiler.h>
#include <iostream>
#include <malloc.h>

using namespace std;

void func1() {
  for (int i = 0; i < 10000; ++i) {
    ++i;
    char *p = (char *)malloc(1024);
    free(p);
  }
}
void func2() {
  for (int i = 0; i < 20000; ++i) {
    char *p = (char *)malloc(1024);
    free(p);
  }
}
void func3() {
  for (int i = 0; i < 10000; ++i) {
    func1();
    func2();
  }
}

int main() {
  ProfilerStart("test.prof"); //开启性能分析并指定所生成的profile文件名
  func3();
  ProfilerStop(); //停止性能分析并输出结果(如果这行代码不运行，将无法输出任何数据，只有一个空文件)
  return 0;
}