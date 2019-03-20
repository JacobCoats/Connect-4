#ifndef BOARD_H
#define BOARD_H

class Board {
public:
    void Init();
    void Insert(int x, int y, int color);
    int Search(int x, int y);
    int** GetBoard();
    void Clean();
private:
    int** board_;

};

#endif

