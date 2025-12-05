# Rock-Paper-Scissors Project

## Project Description

This project implements a classic Rock-Paper-Scissors game in C++ using an object-oriented approach. The codebase is modular, with separate classes for the player, computer opponent, and game engine. The project is designed for extensibility and maintainability, and includes a simple test suite for verifying core components.

## Game Rules

- The game is played between a human player and the computer.
- Each round, both the player and the computer choose one of: Rock, Paper, or Scissors.
- The winner is determined as follows:
  - Rock beats Scissors
  - Scissors beats Paper
  - Paper beats Rock
  - If both choose the same, the round is a draw.

## Project Dependencies

- **Development Environment:**  
  - Visual Studio 2022 (recommended) or any C++20-compatible IDE
  - CMake
- **Compiler:**  
  - Microsoft Visual C++ (MSVC) or any C++20-compliant compiler
- **Third-party Libraries:**  
  - No other third-party libraries are required for the core game

## Building the Application

### Using CMake or Ninja

1. **Install dependencies:**  
   - Ensure CMake is installed and available in your PATH.
   - (Optional) If using SFML, download and set up SFML as described in their documentation.

2. **Configure the project:**
   