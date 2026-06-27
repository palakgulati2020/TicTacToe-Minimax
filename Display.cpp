#include "Display.h"

#include <iostream>

using namespace std;

// Ask user for mode
void Display::start() {
    cout << "Enter '1' for Player vs Computer or '2' for Player vs Player: ";
}

// Information for Mode 1
void Display::startMode1() {
    cout << "\nYou are Player 1 and Computer is Player 2\n";
    cout << "Player 1 uses 'X'\n";
    cout << "Computer uses 'O'\n";
    cout << "Player 1 moves first.\n\n";

    positions();
}

// Information for Mode 2
void Display::startMode2() {
    cout << "\nPlayer 1 uses 'X'\n";
    cout << "Player 2 uses 'O'\n";
    cout << "Player 1 moves first.\n\n";

    positions();
}

// Invalid input
void Display::invalid() {
    cout << "Invalid move. Please try again: ";
}

// Display board positions
void Display::positions() {
    cout << " 1 | 2 | 3\n";
    cout << "-----------\n";
    cout << " 4 | 5 | 6\n";
    cout << "-----------\n";
    cout << " 7 | 8 | 9\n\n";
}

// Display current board
void Display::currentState(const vector<vector<char>> &matrix) {
    cout << " " << matrix[0][0] << " | " << matrix[0][1] << " | " << matrix[0][2] << '\n';
    cout << "-----------\n";
    cout << " " << matrix[1][0] << " | " << matrix[1][1] << " | " << matrix[1][2] << '\n';
    cout << "-----------\n";
    cout << " " << matrix[2][0] << " | " << matrix[2][1] << " | " << matrix[2][2] << "\n\n";
}

// Display available moves
void Display::optionsForMove(const vector<int> &options) {

    cout << "Available moves: ";

    for (int move : options)
        cout << move << " ";

    cout << "\n";
}

// Display winner
void Display::winStatus(char w) {

    if (w == 'X')
        cout << "Player 1 wins!\n";

    else if (w == 'O')
        cout << "Player 2 wins!\n";

    else
        cout << "It's a draw!\n";
}

// Display whose turn it is
void Display::nextMove(int p) {
    cout << "\nPlayer " << p << "'s turn: ";
}