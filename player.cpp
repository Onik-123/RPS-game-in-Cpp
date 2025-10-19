#include "player.hpp"
#include <iostream>
#include <limits>

void Player::makeChoice() {
    int input;
    do {
        std::cout << "Enter 0 (Rock), 1 (Paper), or 2 (Scissors): ";
        std::cin >> input;
        if (std::cin.fail() || !(input >= 0 && input <= 2)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
        } else {
            choice = static_cast<Choice>(input);
            break;
        }
    } while (true);
}

Choice Player::getChoice() const {
    return choice;
}