/*************************************************************************
        > File Name: data_id_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年06月16日 星期二 20时59分01秒
 ************************************************************************/

#include <iostream>

using namespace std;

int64_t GenDataIdFrom(int32_t region_id, int32_t camera_id, int64_t timestamp,
                      int32_t sequence) {
  if (region_id < 1 || region_id >= 16384) {
    cout << "region id invalid" << endl;
    exit(-1);
  }
  if (camera_id < 1 || camera_id >= 128) {
    cout << "camera id invalid" << endl;
    exit(-1);
  }
  if (sequence < 0 || sequence >= 1024) {
    cout << "sequence invalid " << endl;
    exit(-1);
  }

  return static_cast<uint64_t>(region_id) << 49 |
         static_cast<uint64_t>(camera_id) << 42 |
         static_cast<uint64_t>(timestamp) << 10 |
         static_cast<uint64_t>(sequence);
}

int main() {
  cout << GenDataIdFrom(12322, 127, 1592358905, 34) << endl;
  return 0;
}
