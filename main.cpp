#include <iostream>
#include <cstdlib>
#include <ctime>
#include "choice.hpp"
#include "player.hpp"
#include "computer.hpp"
#include "engine.hpp"

int main() {
    std::srand(std::time(nullptr)); // Seed random
    Player player;
    Computer computer;
    Engine engine(player, computer);
    engine.run();
    return 0;
}