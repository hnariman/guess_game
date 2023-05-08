#include "data.hpp"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

#include "utils.hpp"

using utils::msg;

// imitating boost::replace_all()
std::string replace_all(utils::Column c) {
  std::string ret = c.input;

  while ((ret.find(c.target)) != std::string::npos) {
    ret = ret.replace(ret.find(c.target), c.result.length(), c.result);
  }

  return ret;
}

std::string data::capture_name() {
  std::string username = "";

  msg("Hi! Enter your name please:");
  std::cin >> username;
  msg("\n");

  return username;
}

void data::read_table() {
  std::string data = "";
  std::ifstream file("records.csv");

  utils::horizontal_line(30);

  while (getline(file, data)) {
    std::string updated = replace_all({data, ",", "|"});
    msg(updated);
  }

  utils::horizontal_line(30);
}

void data::update_table(data::Record record) {
  std::string data = "";
  std::ofstream file("records.csv", std::ios_base::app);

  try {
    // clang-format off
    file 
      << std::setw(10) << record.username << "," 
      << std::setw(10) << record.attempts << "," 
      << std::setw(10) << record.score << std::endl;
    // clang-format on
  } catch (int code) {
    throw "Unable to update scores table file";
  }
}
