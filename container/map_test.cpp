/*************************************************************************
        > File Name: map_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年04月23日 星期四 10时43分35秒
 ************************************************************************/

#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>


using namespace std;

void MapTest() {
  std::map<std::tuple<int32_t, int32_t>, float> m;
  m.insert({std::make_tuple(1, 2), 100});
  m.insert({std::make_tuple(2, 3), 200});
  m.insert({std::make_tuple(3, 4), 300});
  m.insert({std::make_tuple(4, 5), 400});
  m.insert({std::make_tuple(5, 6), 500});
  
  if (m.find(std::make_tuple(1, 2)) != m.end()) {
    std::cout << m[std::make_tuple(1, 2)] << std::endl;
  }

  std::vector<std::tuple<int32_t, int32_t, float>> t = {
            std::make_tuple(1, 2, 1.2),
            std::make_tuple(2, 2, 2.2),
            std::make_tuple(3, 2, 3.2)
            };

}

int main() {
  for (int i = 1; i <= 3; i++ ) {
    for (int j = 1; j <=3; j++) {
      int32_t a = (i << 7) | j;
      std::cout << a << std::endl;
    }
  }
}
