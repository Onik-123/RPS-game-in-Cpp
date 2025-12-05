#include <iostream>
#include <memory>
#include "choice.hpp"
#include "player.hpp"
#include "computer.hpp" // If you have a ComputerPlayer or similar
#include "engine.hpp"   // If you have an Engine class

// Example: Dummy concrete Player for testing abstract interface
class DummyPlayer : public Player {
    Choice choice;
public:
    DummyPlayer(Choice c) : choice(c) {}
    void makeChoice() override { /* Simulate making a choice */ }
    Choice getChoice() const override { return choice; }
};

// Test Choice enum
bool testChoiceEnum() {
    if (static_cast<int>(Choice::Rock) != 0 ||
        static_cast<int>(Choice::Paper) != 1 ||
        static_cast<int>(Choice::Scissors) != 2) {
        std::cout << "FAILED: Choice enum values are incorrect.\n";
        return false;
    }
    return true;
}

// Test Player interface via DummyPlayer
bool testPlayerInterface() {
    DummyPlayer p(Choice::Paper);
    if (p.getChoice() != Choice::Paper) {
        std::cout << "FAILED: DummyPlayer::getChoice() did not return expected value.\n";
        return false;
    }
    return true;
}

// Test Computer class (example, adapt to your implementation)
bool testComputerClass() {
#ifdef HAS_COMPUTER_CLASS
    Computer c;
    c.makeChoice();
    Choice ch = c.getChoice();
    if (ch != Choice::Rock && ch != Choice::Paper && ch != Choice::Scissors) {
        std::cout << "FAILED: Computer::getChoice() returned invalid value.\n";
        return false;
    }
#endif
    return true;
}

// Test Engine class (example, adapt to your implementation)
bool testEngineClass() {
#ifdef HAS_ENGINE_CLASS
    DummyPlayer p(Choice::Rock);
    Computer c;
    Engine e(p, c);
    // You can test Engine's public methods here, but not the game logic
#endif
    return true;
}

int main() {
    bool allPassed = true;

    if (!testChoiceEnum()) allPassed = false;
    if (!testPlayerInterface()) allPassed = false;
    if (!testComputerClass()) allPassed = false;
    if (!testEngineClass()) allPassed = false;

    if (allPassed) {
        std::cout << "SUCCESS: All component tests passed. Project structure is OK.\n";
    }
    else {
        std::cout << "Some tests FAILED. See above for details.\n";
    }
    return allPassed ? 0 : 1;
}

/*
   add_executable(test test.cpp)
   target_link_libraries(test PRIVATE your_project_libs_if_any)
*/