#pragma once

#include "choice.hpp"

class Computer {
private:
    Choice choice;

public:
    void makeChoice();
    Choice getChoice() const;
};