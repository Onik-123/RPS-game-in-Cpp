#pragma once

/*
@file choice.hpp
@brief Declaration of Choice enum and its output stream operator.
@author Onisim
@date 2025-12-05
*/

#include <iostream>

enum class Choice { Rock = 0, Paper = 1, Scissors = 2 }; // Enum representing the possible choices in the game

std::ostream& operator <<(std::ostream& os, const Choice& choice); // Overloaded output stream operator for Choice enum