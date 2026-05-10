#include "Game.h"
#include <limits>

// Constructor sets the number of patients and their initial state
Game::Game() {
    patientsSaved = 0;
    patients.push_back(Patient{"Patient A", false});
    patients.push_back(Patient{"Patient B", false});
    patients.push_back(Patient{"Patient C", false});
}

int Game::getChoice(const vector<int>& validChoices) {
    int choice;

    while (true) {
        if (cin >> choice) {
            for (int option : validChoices) {
                if (choice == option) {
                    return choice;
                }
            }
        } else {
            cin.clear();
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid choice. Try again: ";
    }
}

// Introduces the game and begins each puzzle in order
void Game::start() {
    cout << "\n--- CODE RED: The Doctor's Game ---\n";
    cout << "You have arrived at the hospital. A killer doctor has hidden patients in rooms across the building...\n";
    cout << "Solve each puzzle to rescue them. Fail, and they may not survive.\n\n";
    labPuzzle();
    erPuzzle();
    morguePuzzle();
    endGame();
}

// First puzzle: select the correct organ for a blood type
void Game::labPuzzle() {
    cout << "\n--- Laboratory ---\n";
    cout << "Doctor: 'This patient's blood type is O-. Choose the compatible organ to save them.'\n";
    cout << "1. Kidney from AB+\n2. Liver from O-\n3. Heart from B+\n";
    cout << "Your choice (1-3): ";

    int choice;
    choice = getChoice({1, 2, 3});

    if (choice == 2) {
        patients[0].saved = true;
        patientsSaved++;
        cout << "Correct. The patient stabilizes.\n";
    } else {
        cout << "Wrong. The patient flatlines...\n";
    }
}

// Second puzzle: choose who to treat first based on triage
void Game::erPuzzle() {
    cout << "\n--- ER Room ---\n";
    cout << "Doctor: 'Three patients arrive. One is bleeding out, one has a broken leg, one is unconscious. Who do you treat first?'\n\n";
    cout << "1. Broken leg\n2. Unconscious\n3. Bleeding\n";
    cout << "Your choice (1-3): ";

    int choice;
    choice = getChoice({1, 2, 3});

    if (choice == 3) {
        patients[1].saved = true;
        patientsSaved++;
        cout << "Good choice. You bought them time.\n";
    } else {
        cout << "Wrong priority. The bleeding patient didn't make it.\n";
    }
}

// Final puzzle: use logic to pick the correct ID tag
void Game::morguePuzzle() {
    cout << "\n--- Morgue ---\n";
    cout << "Doctor: 'One of these bodies holds the key to the last room. The ID tags are: 107, 202, 313.\nOnly the truthful one holds the code. The others lie.'\n";
    cout << "Clue: 107 says 'I'm the one.'\n202 says 'It's not 107.'\n313 says '202 is lying.'\n";
    cout << "Which tag holds the key? (107/202/313): ";

    int tag;
    tag = getChoice({107, 202, 313});

    if (tag == 202) {
        patients[2].saved = true;
        patientsSaved++;
        cout << "Correct deduction. You unlock the freezer and rescue the last patient.\n";
    } else {
        cout << "Wrong tag. The door seals permanently.\n";
    }
}

// After all puzzles, print summary of results
void Game::endGame() {
    cout << "\n--- Mission Complete ---\n";
    cout << "You rescued " << patientsSaved << " out of 3 patients.\n";
    if (patientsSaved == 3) cout << "You won. Everyone survived... this time.\n";
    else if (patientsSaved == 0) cout << "You failed them all. The doctor wins.\n";
    else cout << "You saved some, but not all. You'll carry that with you.\n";
}
