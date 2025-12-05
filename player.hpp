#pragma once

#include "choice.hpp"

class Player {
public:
    virtual void makeChoice() = 0;
    virtual Choice getChoice() const = 0;
};