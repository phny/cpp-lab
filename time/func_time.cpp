#include <chrono>
#include <iostream>
#include <thread>

int main(int argc, char *argv[]) {
  auto beginTime = std::chrono::high_resolution_clock::now();
  std::this_thread::sleep_for(std::chrono::seconds(1));
  auto endTime = std::chrono::high_resolution_clock::now();
  auto elapsedTime = std::chrono::duration_cast<std::chrono::microseconds>(
      endTime - beginTime);
  std::cout << "consume time is " << elapsedTime.count() << " microsecond"
            << std::endl;
  return 0;
}