/*************************************************************************
        > File Name: variadic_template_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年04月18日 星期六 22时39分20秒
 ************************************************************************/

#include <iostream>

using namespace std;

template <typename T> void show_list0(T value) {
  cout << value << ", " << endl;
}

void show_list1() {}

template <typename T, typename... Args> void show_list1(T value, Args... args) {
  cout << value << endl;
  show_list1(args...);
}

int main(int argc, char *argv[]) {
  // show_list0(29.399);

  show_list1(1, 2, 3, 'a', "this is a test", 4.3444);
  return 0;
}
