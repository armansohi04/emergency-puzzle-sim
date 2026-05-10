#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Each patient has a name and a flag to track if they were rescued
struct Patient {
    std::string name;
    bool saved;
};

// Main game class - handles gameplay logic and puzzle flow
class Game {
private:
    int patientsSaved;
    std::vector<Patient> patients;

    int getChoice(const std::vector<int>& validChoices);

public:
    Game();              // Set up initial game state
    void start();        // Begin the game
    void labPuzzle();    // Puzzle in the lab
    void erPuzzle();     // Puzzle in the emergency room
    void morguePuzzle(); // Final puzzle in the morgue
    void endGame();      // Show final result
};

#endif
