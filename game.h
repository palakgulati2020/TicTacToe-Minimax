#ifndef GAME_H
#define GAME_H

#include <vector>

using namespace std;

class Game {
private:
    vector<vector<char>> matrix;
    vector<int> options;
    char winStatus;

public:
    Game();

    vector<vector<char>>& getMatrix();
    const vector<int>& getOptions() const;
    char getWinStatus() const;

    void makeMove(int position, char mark);
    char checkWinStatus();
};

#endif