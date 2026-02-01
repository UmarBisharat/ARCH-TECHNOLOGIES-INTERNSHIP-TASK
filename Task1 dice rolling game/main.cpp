/*
 * ARCH TECHNOLOGIES
 * Task 1: Dice Rolling Game
 * 
 * Simulates rolling a pair of dice. Randomly generates two numbers
 * between 1 and 6 (inclusive), displays the results, and asks the
 * user if they would like to roll again.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

// Returns a random number between 1 and 6
int rollDie() {
    return (rand() % 6) + 1;
}

// Draws a simple ASCII die face
void drawDie(int value) {
    switch (value) {
        case 1:
            cout << " --------- ";
            cout << "|         |";
            cout << "|         |";
            cout << "|    *    |";
            cout << "|         |";
            cout << "|         |";
            cout << " --------- ";
            break;
        case 2:
            cout << " --------- ";
            cout << "|         |";
            cout << "|      *  |";
            cout << "|         |";
            cout << "|  *      |";
            cout << "|         |";
            cout << " --------- ";
            break;
        case 3:
            cout << " --------- ";
            cout << "|         |";
            cout << "|      *  |";
            cout << "|    *    |";
            cout << "|  *      |";
            cout << "|         |";
            cout << " --------- ";
            break;
        case 4:
            cout << " --------- ";
            cout << "|         |";
            cout << "|  *    * |";
            cout << "|         |";
            cout << "|  *    * |";
            cout << "|         |";
            cout << " --------- ";
            break;
        case 5:
            cout << " --------- ";
            cout << "|         |";
            cout << "|  *    * |";
            cout << "|    *    |";
            cout << "|  *    * |";
            cout << "|         |";
            cout << " --------- ";
            break;
        case 6:
            cout << " --------- ";
            cout << "|         |";
            cout << "|  *    * |";
            cout << "|  *    * |";
            cout << "|  *    * |";
            cout << "|         |";
            cout << " --------- ";
            break;
    }
}

// Draws two dice side by side using a row-based approach
void drawDicePair(int die1, int die2) {
    // Each die face has 7 rows
    string faces[2][7];

    // Helper lambda to fill face rows
    auto fillFace = [&](int idx, int value) {
        switch (value) {
            case 1:
                faces[idx][0] = " +-------+ ";
                faces[idx][1] = " |       | ";
                faces[idx][2] = " |       | ";
                faces[idx][3] = " |   *   | ";
                faces[idx][4] = " |       | ";
                faces[idx][5] = " |       | ";
                faces[idx][6] = " +-------+ ";
                break;
            case 2:
                faces[idx][0] = " +-------+ ";
                faces[idx][1] = " |       | ";
                faces[idx][2] = " |     * | ";
                faces[idx][3] = " |       | ";
                faces[idx][4] = " | *     | ";
                faces[idx][5] = " |       | ";
                faces[idx][6] = " +-------+ ";
                break;
            case 3:
                faces[idx][0] = " +-------+ ";
                faces[idx][1] = " |       | ";
                faces[idx][2] = " |     * | ";
                faces[idx][3] = " |   *   | ";
                faces[idx][4] = " | *     | ";
                faces[idx][5] = " |       | ";
                faces[idx][6] = " +-------+ ";
                break;
            case 4:
                faces[idx][0] = " +-------+ ";
                faces[idx][1] = " |       | ";
                faces[idx][2] = " | *   * | ";
                faces[idx][3] = " |       | ";
                faces[idx][4] = " | *   * | ";
                faces[idx][5] = " |       | ";
                faces[idx][6] = " +-------+ ";
                break;
            case 5:
                faces[idx][0] = " +-------+ ";
                faces[idx][1] = " |       | ";
                faces[idx][2] = " | *   * | ";
                faces[idx][3] = " |   *   | ";
                faces[idx][4] = " | *   * | ";
                faces[idx][5] = " |       | ";
                faces[idx][6] = " +-------+ ";
                break;
            case 6:
                faces[idx][0] = " +-------+ ";
                faces[idx][1] = " |       | ";
                faces[idx][2] = " | *   * | ";
                faces[idx][3] = " | *   * | ";
                faces[idx][4] = " | *   * | ";
                faces[idx][5] = " |       | ";
                faces[idx][6] = " +-------+ ";
                break;
        }
    };

    fillFace(0, die1);
    fillFace(1, die2);

    // Print row by row, side by side
    for (int row = 0; row < 7; row++) {
        cout << "   " << faces[0][row] << "  " << faces[1][row] << endl;
    }
}

int main() {
    // Seed the random number generator with current time
    srand(time(NULL));

    cout << "=============================================" << endl;
    cout << "     ARCH TECHNOLOGIES - DICE ROLLING GAME  " << endl;
    cout << "=============================================" << endl;
    cout << endl;

    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        cout << "   Rolling the dice..." << endl;
        cout << endl;

        int die1 = rollDie();
        int die2 = rollDie();
        int total = die1 + die2;

        // Display the two dice side by side
        drawDicePair(die1, die2);

        cout << endl;
        cout << "   Die 1: " << die1 << "    Die 2: " << die2 << endl;
        cout << "   Total: " << total << endl;
        cout << endl;

        // Fun messages based on the total
        if (total == 2) {
            cout << "   Snake eyes! That's the lowest possible roll!" << endl;
        } else if (total == 7) {
            cout << "   Lucky 7! A classic winning number!" << endl;
        } else if (total == 12) {
            cout << "   Boxcars! The highest possible roll!" << endl;
        } else if (die1 == die2) {
            cout << "   Doubles! You rolled a matching pair!" << endl;
        }

        cout << endl;
        cout << "   Would you like to roll again? (y/n): ";
        cin >> playAgain;
        cout << endl;
        cout << "---------------------------------------------" << endl;
        cout << endl;
    }

    cout << "   Thanks for playing! Goodbye." << endl;
    cout << "=============================================" << endl;

    return 0;
}
