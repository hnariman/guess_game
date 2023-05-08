#include <cstring>
#include <iomanip>
#include <iostream>

#include "data.hpp"
#include "game.hpp"
#include "utils.hpp"

/* void print_args(int argc, char* argv[]) { */
/*   for (int i = 1; i < argc; i++) { */
/*     std::cout << argv[i]; */
/*   } */
/* } */

/* void handle_input(int argc, char** argv) { */
/*   if (argc < 1) { */
/*     std::cout << "No Arguments provided :(\n"; */
/*   } else { */
/*     print_args(argc, argv); */
/*     for (int i = 0; i < argc; i++) { */
/*       if (std::find()) { */
/*         print_table(capture_name()); */
/*       } */
/*     } */
/*   } */
/* } */

struct Config {
  int max = 100;
  void set_max(int num) {
    std::cout << "setting max value: " << num << std::endl;
    this->max = num;
  }
};

void handle_input(int argc, char** argv, Config& config) {
  while (*++argv) {
    bool has_max_value = (strcmp(&argv[0][2], "max") == 0);
    bool has_level_value = (strcmp(&argv[0][2], "level") == 0);
    bool help_flag = (strcmp(&argv[0][2], "help") == 0);

    if (has_max_value) {
      config.set_max(atoi(*++argv));
      std::cout << "HAS MAX VALUE" << std::endl;
    }
    if (has_level_value) {
      std::cout << "HAS LEVEL VALUE" << std::endl;
    }
    if(help_flag){
      std::cout 
       << std::setw(30) << " --help " << std::setw(30) << "help menu\n"
       << std::setw(30) << " --max VAL " << std::setw(30) << "set MAX value for random\n"
       << std::setw(30) << " --level VAL " << std::setw(30) << "select level \n"
       << std::endl;
    }
  }
}

int main(int argc, char** argv) {
  Config config;
  handle_input(argc, argv, config);
  std::cout << "MAX:" << config.max << std::endl;
  std::string player = data::capture_name();
  game::play(player, config.max);
  data::read_table();
}
