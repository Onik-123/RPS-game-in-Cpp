#include <iostream>
#include <cstdlib>
#include <ctime>
#include "choice.hpp"
#include "player.hpp"
#include "computer.hpp"
#include "engine.hpp"

//comment

int main() {
    std::srand(std::time(nullptr));
    Player player;
    Computer computer;
    Engine engine(player, computer);
    engine.run();
    Player::demoSTLContainerAndAlgorithms();
    Player::demoSmartPointers();
    return 0;
}