#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"
#include "Game.h"

#include <vector>

using namespace std;

class Computer : public Player {
public:
    Computer(char mark, int number);

    void makeMove(Game &game) override;

private:
    int miniMax(Game &game,
                vector<int> choices,
                int choice,
                int depth,
                int alpha,
                int beta,
                bool maximizingPlayer);

    int evaluation(char outcome, int depth);

    void updateMatrix(int position,
                      vector<vector<char>> &matrix,
                      int value);
};

#endif