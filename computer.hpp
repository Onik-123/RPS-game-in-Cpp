#pragma once

/*
@file computer.hpp
@brief Declaration of Computer class derived from Player.
@author Onisim
@date 2025-12-05
*/

#include "choice.hpp"
#include "player.hpp"

class Computer : public Player {
private:
	Choice choice; // The computer's choice

public:
	void makeChoice(); // Randomly selects a choice for the computer
	Choice getChoice() const; // Returns the computer's choice
};