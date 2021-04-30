#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int *arr = (int *)malloc(sizeof(int));
  if (arr[0] == 1) {
    printf("arr[0] == 1");
  }

  return 0;
}
