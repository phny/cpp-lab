/*************************************************************************
        > File Name: heap_sort.cpp
        > Author:
        > Mail:
        > Created Time: 2021年03月11日 星期四 23时16分09秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

void Swap(std::vector<int> &v, int p1, int p2) { std::swap(v[p1], v[p2]); }

void Heapify(std::vector<int> &v, size_t i) {
  int n = v.size();
  while (true) {
    size_t max_pos = i;
    if (i * 2 < n && v[i] < v[i * 2])
      max_pos = i;
    if (i * 2 + 1 < n && v[max_pos] < v[i * 2 + 1])
      max_pos = 2 * i + 1;
    if (max_pos == i)
      break;
    Swap(v, i, max_pos);
    i = max_pos;
  }
}

void BuildHeap(std::vector<int> &v) {
  for (size_t i = v.size() / 2; i >= 1; i--) {
    Heapify(v, i);
  }
}

int main() { return 0; }
