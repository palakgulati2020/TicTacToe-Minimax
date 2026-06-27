#include "Game.h"
#include <algorithm>

using namespace std;

// Constructor
Game::Game() {
    winStatus = 'F';

    matrix = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    for (int i = 1; i <= 9; i++) {
        options.push_back(i);
    }
}

// Returns the game board
vector<vector<char>>& Game::getMatrix() {
    return matrix;
}

// Returns available positions
const vector<int>& Game::getOptions() const {
    return options;
}

// Returns current game status
char Game::getWinStatus() const {
    return winStatus;
}

// Makes a move on the board
void Game::makeMove(int position, char mark) {

    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    matrix[row][col] = mark;

    options.erase(remove(options.begin(), options.end(), position), options.end());

    winStatus = checkWinStatus();
}

// Checks if someone has won or if the game is still ongoing
char Game::checkWinStatus() {

    if (options.empty())
        return 'D';

    // Check rows
    for (int i = 0; i < 3; i++) {
        if (matrix[i][0] == matrix[i][1] &&
            matrix[i][1] == matrix[i][2])
            return matrix[i][0];
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (matrix[0][j] == matrix[1][j] &&
            matrix[1][j] == matrix[2][j])
            return matrix[0][j];
    }

    // Main diagonal
    if (matrix[0][0] == matrix[1][1] &&
        matrix[1][1] == matrix[2][2])
        return matrix[0][0];

    // Secondary diagonal
    if (matrix[0][2] == matrix[1][1] &&
        matrix[1][1] == matrix[2][0])
        return matrix[0][2];

    return 'F';
}