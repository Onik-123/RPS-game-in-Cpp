#pragma once
#include <iostream>
#include <string>
#include "choice.hpp"
#include "player.hpp"

class HumanPlayer : public Player {
public:
    std::string name;
    Choice choice;

    HumanPlayer();
    HumanPlayer(const std::string& name, Choice choice);
    HumanPlayer(const HumanPlayer& other);
    HumanPlayer& operator=(const HumanPlayer& other);

    bool operator==(const HumanPlayer& other) const;
    bool operator!=(const HumanPlayer& other) const;
    bool operator<(const HumanPlayer& other) const;
    bool operator>(const HumanPlayer& other) const;

    friend std::istream& operator>>(std::istream& is, HumanPlayer& player);
    friend std::ostream& operator<<(std::ostream& os, const HumanPlayer& player);

    void makeChoice();
    Choice getChoice() const;
};
