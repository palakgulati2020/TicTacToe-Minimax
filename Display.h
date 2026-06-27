#ifndef DISPLAY_H
#define DISPLAY_H

#include <vector>

using namespace std;

class Display {
public:
    void start();
    void startMode1();
    void startMode2();
    void invalid();
    void positions();
    void currentState(const vector<vector<char>> &matrix);
    void optionsForMove(const vector<int> &options);
    void winStatus(char w);
    void nextMove(int p);
};

#endif