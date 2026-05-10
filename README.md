# Operation Escape

Operation Escape is a terminal-based C++ puzzle game set in a hospital. The player moves through different rooms, solves medical-themed logic puzzles, and tries to rescue patients by making the correct choices.

## How It Works

The game has three main challenge rooms:

- Lab Puzzle — blood type compatibility
- ER Puzzle — triage prioritization
- Morgue Puzzle — deduction from conflicting clues

Each room presents a different question. The game checks the player’s answer, tracks how many patients were saved, and shows a final result at the end.

## Features

- Room-based puzzle flow
- Patient rescue tracking
- Input validation for player choices
- Final score based on patients saved

## Files

- `main.cpp` — starts the game
- `Game.h` — class and struct declarations
- `Game.cpp` — game logic, puzzle flow, and input validation
- `hospital_game` — compiled Mac executable

## Compile and Run

```bash
g++ main.cpp Game.cpp -o hospital_game
./hospital_game
```
