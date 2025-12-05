#pragma once

/*
@file player.hpp
@brief Declaration of Player abstract class.
@author Onisim
@date 2025-12-05
*/

#include "choice.hpp"

class Player {
public:
	virtual void makeChoice() = 0; // Prompts the player to make a choice
	virtual Choice getChoice() const = 0; // Returns the player's choice
};