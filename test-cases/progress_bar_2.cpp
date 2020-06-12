/*************************************************************************
        > File Name: ../../test-cases/progress_bar_2.cpp
        > Author:
        > Mail:
        > Created Time: 2020年06月01日 星期一 20时11分53秒
 ************************************************************************/

#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
  int all_block_num = 1000;

  for (int i = 0; i < all_block_num; i++) {
    if (i < all_block_num - 1) {
      printf("\rreading[%.2lf%%]:", i * 100.0 / (all_block_num - 1));
    } else {
      printf("\rread finished[%.2lf%%]:", i * 100.0 / (all_block_num - 1));
    }
    int show_num = i * 20 / all_block_num;
    for (int j = 1; j <= show_num; j++) {
      std::cout << "|";
      sleep(1);
    }
  }
  std::cout << std::endl;
  return 1;
}
