#include "board.h"

void Board::Init() {
    board_ = new int*[7];
    for (int i = 0; i < 7; i++) {
        board_[i] = new int[7];
    }

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            board_[i][j] = 0;
        }
    }
}

void Board::Insert(int x, int y, int color) {
    board_[x][y] = color;
}

int Board::Search(int x, int y) {
    return board_[x][y];
}

int** Board::GetBoard() {
    return board_;
}

void Board::Clean() {
    for (int i = 0; i < 7; i++) {
        delete board_[i];
    }
    delete board_;
}
