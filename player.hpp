#pragma once

#include <iostream>
#include "choice.hpp"

class Player {
private:
    Choice choice;

public:
    void makeChoice() {
        int input;
        do {
            std::cout << "Enter 0 (Rock), 1 (Paper), or 2 (Scissors): ";
            std::cin >> input;
            if (!(input >= 0 && input <= 2)) {
                std::cout << "Invalid input. Please try again." << std::endl;
            } else {
                choice = static_cast<Choice>(input);
                break;
            }
        } while (true);
    }

    Choice getChoice() const {
        return choice;
    }
};