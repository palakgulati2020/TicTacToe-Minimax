#include <iostream>

#include "Game.h"
#include "Player.h"
#include "Computer.h"
#include "Display.h"

using namespace std;

int main() {

    int mode;
Display display;

do {
    mode = 0;
    display.start();
    
    do {
        cin >> mode;

        if (mode == 1) {

            display.startMode1();

            Player player1('X', 1);
            Computer player2('O', 2);

            Game game;

            int turn = 1;

            while (game.getWinStatus() == 'F') {

                int currentPlayer = (turn % 2 == 1) ? 1 : 2;

                display.nextMove(currentPlayer);
                display.optionsForMove(game.getOptions());

                if (currentPlayer == 1)
                    player1.makeMove(game);
                else
                    player2.makeMove(game);

                display.currentState(game.getMatrix());

                turn++;
            }

            display.winStatus(game.getWinStatus());
        }

        else if (mode == 2) {

            display.startMode2();

            Player player1('X', 1);
            Player player2('O', 2);

            Game game;

            int turn = 1;

            while (game.getWinStatus() == 'F') {

                int currentPlayer = (turn % 2 == 1) ? 1 : 2;

                display.nextMove(currentPlayer);
                display.optionsForMove(game.getOptions());

                if (currentPlayer == 1)
                    player1.makeMove(game);
                else
                    player2.makeMove(game);

                display.currentState(game.getMatrix());

                turn++;
            }

            display.winStatus(game.getWinStatus());
        }

        else {
            display.invalid();
        }

    } while (mode != 1 && mode != 2);

} while (true); // Infinite loop to keep playing

return 0;
}