#include "hello.hpp"

#include "other.hpp"

int main() {
  Hello<char> hc;
  Hello<int> hi;

  hc.print_hello('a');
  hi.print_hello(1);

  other_func();

  return 0;
}
