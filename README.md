# RPS-game-in-Cpp
A simple Rock, Paper, Scissors game implemented in C++. Play against the computer, make your choice, and see if you can beat the odds! Features include input validation, score tracking, and replay options.


## How to Build
- Manual: g++ -c *.cpp -o *.o then g++ *.o -o rps
- Automated: Run build.cmd (Windows) or make (Makefile).

## How to Play
- Run rps (or rps.exe).
- Enter 0, 1, or 2.
- See result.

## Files
- choice.hpp: Defines choices.
- player.hpp / player.cpp: Handles input.
- computer.hpp / computer.cpp: Generates computer choice.
- engine.hpp / engine.cpp: Manages logic.
- main.cpp: Runs the game.
