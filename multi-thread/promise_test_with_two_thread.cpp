#include <algorithm>
#include <chrono>
#include <future>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

using namespace std;

void my_accumulate(std::vector<int>::iterator first,
                   std::vector<int>::iterator last,
                   std::promise<int> &accumulate_promise) {
  int sum = std::accumulate(first, last, 0);
  accumulate_promise.set_value(sum); // Notify future
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << "continue work" << std::endl;
}

int test_future_promise() {
  try {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
    std::promise<int> accumulate_promise;
    std::future<int> accumulate_future = accumulate_promise.get_future();

    // 开启工作线程
    std::thread work_thread(my_accumulate, numbers.begin(), numbers.end(),
                            std::ref(accumulate_promise));

    // accumulate_future.wait();  // wait for result

    std::cout << "result=" << accumulate_future.get() << '\n';
    std::cout << "work in main thread" << std::endl;

    work_thread.join(); // wait for thread completion

  } catch (std::exception &e) {
    std::cerr << e.what();
  }

  return 0;
}

int main(int argc, char *argv[]) {
  test_future_promise();

  return 0;
}