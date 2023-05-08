#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

namespace utils {

struct Column {
  std::string input;
  const std::string &target;
  const std::string &result;
};

/// Shorthand for printing
void msg(const std::string &message);

/// Shorthand for random integer
int random_int(int min = 0, int max = 1000);

inline void horizontal_line(int len) { msg(std::string(len, '-')); }

} // namespace utils

#endif /* ifndef UTILS_HPP */
