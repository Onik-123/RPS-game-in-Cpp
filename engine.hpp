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
        computer.generateChoice();

        // Display player's choice
        std::cout << "You chose ";
        switch (player.getChoice()) {
            case ROCK:
                std::cout << "Rock";
                break;
            case PAPER:
                std::cout << "Paper";
                break;
            case SCISSORS:
                std::cout << "Scissors";
                break;
        }

        // Display computer's choice
        std::cout << ", Computer chose ";
        switch (computer.getChoice()) {
            case ROCK:
                std::cout << "Rock";
                break;
            case PAPER:
                std::cout << "Paper";
                break;
            case SCISSORS:
                std::cout << "Scissors";
                break;
        }

        std::cout << " - ";

        // Determine and display the result
        if (player.getChoice() == computer.getChoice()) {
            std::cout << "Tie!\n";
        } else if (
            (player.getChoice() == ROCK && computer.getChoice() == SCISSORS) ||
            (player.getChoice() == PAPER && computer.getChoice() == ROCK) ||
            (player.getChoice() == SCISSORS && computer.getChoice() == PAPER)
        ) {
            std::cout << "You win!\n";
        } else {
            std::cout << "Computer wins!\n";
        }
    }
};