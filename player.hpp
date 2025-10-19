#pragma once

#pragma once
#include <iostream>

enum class Choice { Rock = 0, Paper = 1, Scissors = 2 };

class Player {
public:
    std::string name;
    Choice choice;

    Player();

    Player(const std::string& name, Choice choice);

    Player(const Player& other);

    Player& operator=(const Player& other);

    bool operator==(const Player& other) const;
    bool operator!=(const Player& other) const;
    bool operator<(const Player& other) const;
    bool operator>(const Player& other) const;

    friend std::istream& operator>>(std::istream& is, Player& player);
    friend std::ostream& operator<<(std::ostream& os, const Player& player);

    void makeChoice();
    Choice getChoice() const;
};