#pragma once

#include <iostream>
#include <limits>
#include "choice.hpp"

class Player {
private:
    Choice choice;

public:
    void makeChoice();
    Choice getChoice() const;
    void displayChoice() const;
};