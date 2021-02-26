#include <torch/script.h> // One-stop header.

#include <iostream>
#include <memory>
#include <time.h>

int main(int argc, const char *argv[]) {
  if (argc == 1) {
    std::cerr << "usage: example-app <path-to-exported-script-module>\n";
    return -1;
  }
  clock_t startTime, endTime;
  torch::jit::script::Module module;
  torch::jit::script::Module test_data;
  // Deserialize the ScriptModule from a file using torch::jit::load().
  module = torch::jit::load(argv[1]);
  test_data = torch::jit::load(argv[2]);
  torch::Tensor data = test_data.attr("data").toTensor().toType(torch::kFloat);
  torch::Tensor label =
      test_data.attr("label").toTensor().toType(torch::kFloat);
  std::vector<torch::jit::IValue> inputs;
  inputs.push_back(data);
  at::Tensor output = module.forward(inputs).toTensor();
  output = (output > 0.5).toType(torch::kFloat);
  startTime = clock();
  at::Tensor acc =
      (output.flatten() == label.flatten()).toType(torch::kFloat).mean();
  endTime = clock();
  std::cout << "Totle Time : " << endTime - startTime << "/" << CLOCKS_PER_SEC
            << " (s) " << std::endl;
  std::cout << acc << '\n';

  std::cout << "ok\n";
}
