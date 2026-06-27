#include "Computer.h"

#include <algorithm>
#include <climits>

using namespace std;

// Constructor
Computer::Computer(char mark, int number)
    : Player(mark, number) {}

// Computer makes the best move using Minimax
void Computer::makeMove(Game &game) {

    int choice = 0;
    int val;

    vector<int> choices = game.getOptions();

    if (mark == 'X') {

        val = INT_MIN;

        for (int i = 0; i < choices.size(); i++) {

            int minimax = miniMax(game,
                                  choices,
                                  i,
                                  0,
                                  INT_MIN,
                                  INT_MAX,
                                  true);

            if (minimax > val) {
                val = minimax;
                choice = choices[i];
            }
        }
    }
    else {

        val = INT_MAX;

        for (int i = 0; i < choices.size(); i++) {

            int minimax = miniMax(game,
                                  choices,
                                  i,
                                  0,
                                  INT_MIN,
                                  INT_MAX,
                                  false);

            if (minimax < val) {
                val = minimax;
                choice = choices[i];
            }
        }
    }

    game.makeMove(choice, mark);
}

// Minimax with Alpha-Beta Pruning
int Computer::miniMax(Game &game,
                      vector<int> choices,
                      int choice,
                      int depth,
                      int alpha,
                      int beta,
                      bool maximizingPlayer) {

    int temp = choices[choice];
    choices.erase(choices.begin() + choice);

    if (maximizingPlayer) {

    updateMatrix(temp, game.getMatrix(), 'X');

    char status = game.checkWinStatus();

    if (status != 'F') {
        updateMatrix(temp, game.getMatrix(), temp);
        return evaluation(status, depth);
    }

    if (choices.empty()) {
        updateMatrix(temp, game.getMatrix(), temp);
        return evaluation('D', depth);
    }

        int maxEval = INT_MIN;

        for (int i = 0; i < choices.size(); i++) {

            int eval = miniMax(game,
                               choices,
                               i,
                               depth + 1,
                               alpha,
                               beta,
                               false);

            maxEval = max(maxEval, eval);

            alpha = max(alpha, eval);

            if (beta <= alpha)
                break;
        }

        updateMatrix(temp, game.getMatrix(), temp);

        return maxEval;
    }
    else {

    updateMatrix(temp, game.getMatrix(), 'O');

    char status = game.checkWinStatus();

    if (status != 'F') {
        updateMatrix(temp, game.getMatrix(), temp);
        return evaluation(status, depth);
    }

    if (choices.empty()) {
        updateMatrix(temp, game.getMatrix(), temp);
        return evaluation('D', depth);
    }

        int minEval = INT_MAX;

        for (int i = 0; i < choices.size(); i++) {

            int eval = miniMax(game,
                               choices,
                               i,
                               depth + 1,
                               alpha,
                               beta,
                               true);

            minEval = min(minEval, eval);

            beta = min(beta, eval);

            if (beta <= alpha)
                break;
        }

        updateMatrix(temp, game.getMatrix(), temp);

        return minEval;
    }
}

// Evaluation function
int Computer::evaluation(char outcome, int depth) {

    if (outcome == 'D')
        return 0;

    if (outcome == 'X')
        return 10 - depth;

    return depth - 10;
}

// Updates board temporarily during Minimax
void Computer::updateMatrix(int position,
                            vector<vector<char>> &matrix,
                            int value) {

    char mark;

    if (value > 9)
        mark = static_cast<char>(value);
    else
        mark = static_cast<char>('0' + value);

    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    matrix[row][col] = mark;
}