#include <chrono>
#include <iostream>
#include <thread>

void work(int i) {
  std::cout << "worker: " << i << " start work" << std::endl;
  while (true) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "worker " << i << " working" << std::endl;
  }
  std::cout << "worker: " << i << " end work" << std::endl;
}

int main(int argc, char *argv[]) {
  std::thread t1(work, 1);
  std::thread t2(work, 2);
  std::thread t3(work, 3);

  t1.detach();
  t2.detach();
  t3.detach();

  std::this_thread::sleep_for(std::chrono::seconds(10));

  return 0;
}