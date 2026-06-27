#ifndef PLAYER_H
#define PLAYER_H

#include "Game.h"

using namespace std;

class Player {
protected:
    char mark;
    int number;

public:
    Player(char mark, int number);
    virtual ~Player() = default;

    virtual void makeMove(Game &game);

    char getMark() const;
    int getNumber() const;
};

#endif