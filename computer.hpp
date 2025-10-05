#pragma once

#include <cstdlib> // for rand()
#include "choice.hpp"

class Computer {
private:
    Choice choice;

public:
    void generateChoice() {
        choice = static_cast<Choice>(rand() % 3);
    }

    Choice getChoice() const {
        return choice;
    }

    int getChoiceValue() const {
        return static_cast<int>(choice);
    }
};