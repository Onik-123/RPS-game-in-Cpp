#pragma once

class Computer {
private:
    int choice;

public:
    void generateChoice() {
        choice = rand() % 3;
    }

    int getChoiceValue() const {
        return choice;
    }
};