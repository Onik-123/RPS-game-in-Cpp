#pragma once

#include <iostream>
#include "player.hpp"
#include "computer.hpp"
#include "choice.hpp"

class Engine {
private:
    Player& player;
    Computer& computer;

public:
    Engine(Player& p, Computer& c) : player(p), computer(c) {}

    void run() {
        player.makeChoice();
        computer.makeChoice();

        // Display player's choice
		std::cout << "You chose " << player.getChoice();

        // Display computer's choice
		std::cout << ", Computer chose " << computer.getChoice();

        std::cout << " - ";

        // Determine and display the result
        if (player.getChoice() == computer.getChoice()) {
            std::cout << "Tie!\n";
        } else if (
            (player.getChoice() == Choice::Rock && computer.getChoice() == Choice::Scissors) ||
            (player.getChoice() == Choice::Paper && computer.getChoice() == Choice::Rock) ||
            (player.getChoice() == Choice::Scissors && computer.getChoice() == Choice::Paper)
        ) {
            std::cout << "You win!\n";
        } else {
            std::cout << "Computer wins!\n";
        }
    }
};