/*************************************************************************
        > File Name: test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年06月07日 星期日 08时25分56秒
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main() {
  string p =
      "/component/heyulin/all_days_images/tmp/day22/2305906203000840500.jpg";
  int start_ind = p.find_last_of('/');
  int end_ind = p.find_last_of('.');

  cout << p.substr(start_ind + 1, end_ind - start_ind - 1) << endl;

  return 0;
}
