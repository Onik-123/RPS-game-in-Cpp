#include "player.hpp"

void Player::makeChoice() {
    int input;
    do {
        std::cout << "Enter 0 (Rock), 1 (Paper), or 2 (Scissors): ";
        std::cin >> input;
        if (std::cin.fail() || !(input >= 0 && input <= 2)) {
            std::cin.clear(); // Clear error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore bad input
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

void Player::displayChoice() const {
    if (choice == ROCK) std::cout << "Player chose Rock\n";
    else if (choice == PAPER) std::cout << "Player chose Paper\n";
    else std::cout << "Player chose Scissors\n";
}