#include "input.h"
#include <SDL.h>
// REMOVE IOSTREAM, DEBUG ONLY
#include <iostream>

using std::cout;
using std::endl;

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
                    cout << "1" << endl;
                    return 1;
                }
                if (x >= 95 && x < 185) {
                    cout << "2" << endl;
                    return 2;
                }
                if (x >= 185 && x < 275) {
                    cout << "3" << endl;
                    return 3;
                }
                if (x >= 275 && x < 365) {
                    cout << "4" << endl;
                    return 4;
                }
                if (x >= 365 && x < 455) {
                    cout << "5" << endl;
                    return 5;
                }
                if (x >= 455 && x < 545) {
                    cout << "6" << endl;
                    return 6;
                }
                if (x >= 545) {
                    cout << "7" << endl;
                    return 7;
                }
            }
        }
    }

    return 0;
}
