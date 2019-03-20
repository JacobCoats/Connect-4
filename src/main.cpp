#include <SDL.h>
#include <iostream>
#include "graphics.h"
#include "input.h"
#include "board.h"
#include "logic.cpp"

using std::cout;
using std::cerr;
using std::endl;

int main (int argc, char **argv) {
    Graphics graphics;
    Input input;
    Board board;
    board.Init();
    Logic logic;
    if (!graphics.Init()) {
        cerr << "Could not initialize graphics." << endl;
    }
    else {
        int inputOption;
        bool running = true;
        bool turnCompleted;
        int turn = 1;
        while (running) {
            while (turn == 1 && running) {
                turnCompleted = false;
                inputOption = input.GetInput();
                if (inputOption < 0) {
                    running = false;
                }
                else if (inputOption) {
                    turnCompleted = logic.FindPiecePos(board.GetBoard(), inputOption, 1);
                }

                graphics.RenderFrame(board.GetBoard());

                if (globals::WINNER) {
                    running = false;
                    cout << "WINNER DETECTED" << endl;
                }
                if (turnCompleted) {
                    turn = 2;
                }
            }
            while (turn == 2 && running) {
                turnCompleted = false;
                inputOption = input.GetInput();
                if (inputOption < 0) {
                    running = false;
                }
                else if (inputOption) {
                    turnCompleted = logic.FindPiecePos(board.GetBoard(), inputOption, 2);
                }

                graphics.RenderFrame(board.GetBoard());

                if (globals::WINNER) {
                    running = false;
                    cout << "WINNER DETECTED" << endl;
                }
                if (turnCompleted) {
                    turn = 1;
                }
            }
        }
        if (globals::WINNER == 1) {
            cout << "Red wins!" << endl;
        }
        else if (globals::WINNER == 2) {
            cout << "Yellow wins!" << endl;
        }
        else {
            cout << "It's a draw." << endl;
        }

        graphics.Clean();
    }

    return 0;
}
