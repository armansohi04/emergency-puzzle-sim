# Operation Escape

Operation Escape is a terminal-based C++ puzzle game set in a hospital taken over by a killer doctor. The player moves through different rooms, solves logic-based challenges, and tries to rescue the hostages before time runs out.

## How It Works

The game is built around three main hospital-themed puzzles:

- Lab Puzzle — blood type compatibility
- ER Puzzle — triage prioritization
- Morgue Puzzle — deduction using conflicting clues

Each room gives the player a different challenge. The game checks the player’s answers and moves the story forward based on the outcome.

## Files

- `main.cpp` — starts the game
- `Game.h` — class and struct declarations
- `Game.cpp` — game logic and puzzle code
- `hospital_game` — compiled Mac executable

## Compile and Run

```bash
g++ main.cpp Game.cpp -o hospital_game
./hospital_game
