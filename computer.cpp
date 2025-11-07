#include "choice.hpp"

#include "computer.hpp"
#include <cstdlib>
#include <ctime>

void Computer::makeChoice() {
    // rand() % 3 gives a value 0, 1, or 2
    choice = static_cast<Choice>(rand() % 3);
}

Choice Computer::getChoice() const {
    return choice;
}