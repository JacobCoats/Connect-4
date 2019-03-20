#include "input.h"
#include <SDL.h>

int Input::GetInput() {
    SDL_Event event;
    int x;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return -1;
        }

        if (event.type == SDL_MOUSEBUTTONDOWN) {
            if (event.button.button == SDL_BUTTON_LEFT && SDL_GetMouseState(&x, NULL)) {
                if (x < 95) {
                    return 1;
                }
                if (x >= 95 && x < 185) {
                    return 2;
                }
                if (x >= 185 && x < 275) {
                    return 3;
                }
                if (x >= 275 && x < 365) {
                    return 4;
                }
                if (x >= 365 && x < 455) {
                    return 5;
                }
                if (x >= 455 && x < 545) {
                    return 6;
                }
                if (x >= 545) {
                    return 7;
                }
            }
        }
    }

    return 0;
}
