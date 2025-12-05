#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory>
#include "choice.hpp"
#include "HumanPlayer.hpp"
#include "computer.hpp"
#include "engine.hpp"

int main() {
    std::srand(std::time(nullptr));
    std::unique_ptr<HumanPlayer> player = std::make_unique<HumanPlayer>();
    std::unique_ptr<Computer> computer = std::make_unique<Computer>();
    Engine engine(std::move(player), std::move(computer));
    engine.run();

    return 0;
}