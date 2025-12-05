#pragma once

#include <iostream>
#include <memory>
#include "player.hpp"
#include "computer.hpp"
#include "choice.hpp"

class Engine {
private:
    std::unique_ptr<Player> player1;
    std::unique_ptr<Player> player2;
    int roundsPlayed = 0;
    int player1Wins = 0;
    int player2Wins = 0;
    int ties = 0;

public:
    Engine(std::unique_ptr<Player> p1, std::unique_ptr<Player> p2);
    void run();

private:
    void Init();
    void MakeChoices();
    void DisplayChoices() const;
    void DetermineResult();
    void CurrentResult() const;
};