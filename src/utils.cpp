#include "utils.hpp"

#include <iostream>

int utils::random_int(int min, int max) {
  std::srand(time(nullptr));
  return std::rand() % max + min;
}

void utils::msg(const std::string& message) { std::cout << message << std::endl; }
