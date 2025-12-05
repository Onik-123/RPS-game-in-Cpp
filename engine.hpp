#pragma once

/*
@file engine.hpp
@brief Declaration of Engine class that manages the Rock-Paper-Scissors game.
@author Onisim
@date 2025-12-05
*/

#include <iostream>
#include <memory>
#include "player.hpp"
#include "computer.hpp"
#include "choice.hpp"

class Engine {
private:
	std::unique_ptr<Player> player1; // Human player
	std::unique_ptr<Player> player2; // Computer player
	int roundsPlayed = 0; // Total rounds played
	int player1Wins = 0; // Total wins for player 1
	int player2Wins = 0; // Total wins for player 2
	int ties = 0; // Total ties

public:
	Engine(std::unique_ptr<Player> p1, std::unique_ptr<Player> p2); // Constructor initializing players
	void run(); // Main game loop

private:
	void Init(); // Initializes the game
	void MakeChoices(); // Players make their choices
	void DisplayChoices() const; // Displays the choices made by players
	void DetermineResult(); // Determines and displays the result of the round
	void CurrentResult() const; // Displays the current game statistics
};