#include "engine.hpp"

#include "AsciiRenderer.hpp"

ImageType images[] = {
    FromFile("resources/rock.txt"),
    FromFile("resources/paper.txt"),
    FromFile("resources/scissors.txt")
};

Engine::Engine(std::unique_ptr<Player> p1, std::unique_ptr<Player> p2) : player1(std::move(p1)), player2(std::move(p2)) {}

void Engine::run() {
    Init();
    while (true) {
        CurrentResult();
        MakeChoices();
        DisplayChoices();
        DetermineResult();
    }
}

void Engine::Init() {
    std::cout << "Welcome to Rock-Paper-Scissors!\n";
    std::cout << "Make your choice by entering 0 (Rock), 1 (Paper), or 2 (Scissors).\n";
    std::cout << "Exit - Ctrl+C\n";
    std::cout << "-----------------------------\n";
}

void Engine::MakeChoices() {
    player1->makeChoice();
    player2->makeChoice();
}

void Engine::DisplayChoices() const {
    AsciiRenderer renderer;
    ImageType player1Image = images[static_cast<int>(player1->getChoice())];
    ImageType player2Image = FlipImage(images[static_cast<int>(player2->getChoice())]);
    ImageType mergedImage = MergeImages(player1Image, player2Image);
    renderer.DrawImage(mergedImage);
    std::cout << "You chose " << player1->getChoice() << ", Computer chose " << player2->getChoice() << " - ";
}

void Engine::DetermineResult() {
    ++roundsPlayed;
    Choice p1Choice = player1->getChoice();
    Choice p2Choice = player2->getChoice();

    if (p1Choice == p2Choice) {
        std::cout << "It's a tie!\n";
        ++ties;
    } else if ((p1Choice == Choice::Rock && p2Choice == Choice::Scissors) ||
               (p1Choice == Choice::Paper && p2Choice == Choice::Rock) ||
               (p1Choice == Choice::Scissors && p2Choice == Choice::Paper)) {
        std::cout << "You win!\n";
        ++player1Wins;
    } else {
        std::cout << "Computer wins!\n";
        ++player2Wins;
    }
}

void Engine::CurrentResult() const {
    std::cout << "\n--- Current Score ---\n";
    std::cout << "Rounds Played: " << roundsPlayed << "\n";
    std::cout << "Your Wins: " << player1Wins << "\n";
    std::cout << "Computer Wins: " << player2Wins << "\n";
    std::cout << "Ties: " << ties << "\n";
    std::cout << "---------------------\n";
}