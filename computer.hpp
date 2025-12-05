#pragma once

#include "choice.hpp"
#include "player.hpp"

class Computer : public Player {
private:
    Choice choice;

public:
    void makeChoice();
    Choice getChoice() const;
};