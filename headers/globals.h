#ifndef GLOBALS_H
#define GLOBALS_H

#include <SDL.h>

namespace globals {
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    int WINNER = 0;

    SDL_Rect piecePosRect{15, 6, 70, 70};
}

#endif // GLOBALS_H
