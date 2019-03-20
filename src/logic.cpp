#include "logic.h"
#include "globals.h"
#include <iostream>

bool Logic::FindPiecePos(int** board, int col, int color) {
    bool success = true;
    bool found = false;
    int row = 5;

    while (!found) {
        if (row >= 0) {
            if (board[row][col - 1] == 0) {
                board[row][col - 1] = color;
                found = true;
            }
            else  {
                row--;
            }
        }
        else {
            found = true;
            success = false;
        }
    }

    globals::WINNER = DetectWins(board, color);

    return success;
}

int Logic::DetectWins(int** board, int color) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (board[i][j] == color && board[i][j+1] == color && board[i][j+2] == color && board[i][j+3] == color) {
                return color;
            }
            if (board[i][j] == color && board[i+1][j] == color && board[i+2][j] == color && board[i+3][j] == color) {
                return color;
            }
            if (board[i][j] == color && board[i+1][j+1] == color && board[i+2][j+2] == color && board[i+3][j+3] == color) {
                return color;
            }
            if (i >= 3 && j >= 3) {
                if (board[i][j] == color && board[i-1][j-1] == color && board[i-2][j-2] == color && board[i-3][j-3] == color) {
                    return color;
                }
            }
            if (i >= 3) {
                if (board[i][j] == color && board[i-1][j+1] == color && board[i-2][j+2] == color && board[i-3][j+3] == color) {
                    return color;
                }
            }
            if (j >= 3) {
                if (board[i][j] == color && board[i+1][j-1] == color && board[i+2][j-2] == color && board[i+3][j-3] == color) {
                    return color;
                }
            }
        }
    }

    return 0;
}
