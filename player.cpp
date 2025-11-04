#include "player.hpp"
#include <iostream>
#include <limits>

Player::Player() : name(""), choice(Choice::Rock) {}

Player::Player(const std::string& name, Choice choice) : name(name), choice(choice) {}

Player::Player(const Player& other) : name(other.name), choice(other.choice) {}

Player& Player::operator=(const Player& other) {
    if (this != &other) {
        name = other.name;
        choice = other.choice;
    }
    return *this;
}

bool Player::operator==(const Player& other) const {
    return name == other.name && choice == other.choice;
}
bool Player::operator!=(const Player& other) const {
    return !(*this == other);
}
bool Player::operator<(const Player& other) const {
    return name < other.name || (name == other.name && static_cast<int>(choice) < static_cast<int>(other.choice));
}
bool Player::operator>(const Player& other) const {
    return other < *this;
}

std::istream& operator>>(std::istream& is, Player& player) {
    std::cout << "Enter player name: ";
    is >> player.name;
    int input;
    do {
        std::cout << "Enter 0 (Rock), 1 (Paper), or 2 (Scissors): ";
        is >> input;
        if (is.fail() || !(input >= 0 && input <= 2)) {
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
        } else {
            player.choice = static_cast<Choice>(input);
            break;
        }
    } while (true);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << "Player: " << player.name << ", Choice: ";
    switch (player.choice) {
        case Choice::Rock: os << "Rock"; break;
        case Choice::Paper: os << "Paper"; break;
        case Choice::Scissors: os << "Scissors"; break;
    }
    return os;
}

void Player::makeChoice() {
    int input;
    do {
        std::cout << "Enter 0 (Rock), 1 (Paper), or 2 (Scissors): ";
        std::cin >> input;
        if (std::cin.fail() || !(input >= 0 && input <= 2)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
        } else {
            choice = static_cast<Choice>(input);
            break;
        }
    } while (true);
}

void Player::demoSTLContainerAndAlgorithms() {
    std::vector<Player> players = {
        Player("Alice", Choice::Rock),
        Player("Bob", Choice::Paper),
        Player("Charlie", Choice::Scissors)
    };

    std::sort(players.begin(), players.end());

    std::cout << "Sorted players:\n";
    for (const auto& p : players) {
        std::cout << p << std::endl;
    }

    auto it = std::find_if(players.begin(), players.end(),
        [](const Player& p) { return p.name == "Bob"; });
    if (it != players.end()) {
        std::cout << "Found player: " << *it << std::endl;
    }
}

void Player::demoSmartPointers() {
    std::shared_ptr<Player> p1 = std::make_shared<Player>("Diana", Choice::Paper);
    std::shared_ptr<Player> p2 = std::make_shared<Player>("Eve", Choice::Scissors);

    std::vector<std::shared_ptr<Player>> playerPtrs = { p1, p2 };

    std::cout << "Players managed by smart pointers:\n";
    for (const auto& ptr : playerPtrs) {
        std::cout << *ptr << std::endl;
    }
}

Choice Player::getChoice() const {
    return choice;
}
