#include "game.hpp"

#include "data.hpp"
#include "utils.hpp"

/* #define msg(x) std::cout << x << std::endl; */

void game::play(const std::string& player, const int max) {
  int input = 0;
  int attempts = 0;
  const int secret = utils::random_int(0, max);

  if (std::getenv("GAME_DEBUG")) printf("%d\n", secret);

  while (input != secret) {
    std::cout << "Enter your guess: ";
    std::cin >> input;
    attempts++;
    std::cout << (input < secret ? "Greater" : "Lesser") << " than " << input
              << std::endl;
  }
  if (input == secret) {
    std::cout << "You win!\n"
              << "attempts: " << attempts << std::endl;
    data::update_table({player, attempts, 10000 / attempts});
  }
}
