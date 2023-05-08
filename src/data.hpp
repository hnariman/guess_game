#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

namespace data {

struct Record {
  std::string username;
  int attempts;
  int score;
};

std::string capture_name();

void read_table();

void update_table(Record r);

}  // namespace data

#endif /* ifndef DATA_HPP */
