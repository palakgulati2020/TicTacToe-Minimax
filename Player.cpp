#include "Player.h"
#include "Display.h"

#include <iostream>
#include <algorithm>

using namespace std;

// Constructor
Player::Player(char mark, int number) {
    this->mark = mark;
    this->number = number;
}

// Human player makes a move
void Player::makeMove(Game &game) {

    int choice;
    cin >> choice;

    Display dis;

    const vector<int> &options = game.getOptions();

    while (find(options.begin(), options.end(), choice) == options.end()) {
        dis.invalid();
        cin >> choice;
    }

    game.makeMove(choice, mark);
}

// Getter for mark
char Player::getMark() const {
    return mark;
}

// Getter for player number
int Player::getNumber() const {
    return number;
}