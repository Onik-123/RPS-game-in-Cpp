#pragma once

#include <string>

#include "choice.hpp"

class Player {
	private:
	Choice choice;

	public:
	void getChoice() {
		int input;
        std::cout << "Enter 0 (Rock), 1 (Paper), or 2 (Scissors): ";
        std::cin >> input;

		if !(input >= 1 && input <= 3) {
			std::cout << "Invalid input. Please try again." << std::endl;
			getChoice();
		} else {
			choice = static_cast<Choice>(input);
		}

		Choice getChoiceValue() const {
			return choice;
		}
	}
