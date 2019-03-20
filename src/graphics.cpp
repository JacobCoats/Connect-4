#include "graphics.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

using std::cerr;
using std::endl;
using std::string;

bool Graphics::Init() {
    bool success = true;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        cerr << "Could not initialize SDL. SDL Error: " << SDL_GetError() << endl;
        success = false;
    }
    else {
        string title = "Connect 4";
        gWindow_ = SDL_CreateWindow(title.c_str(),
                                  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                  SCREEN_WIDTH, SCREEN_HEIGHT,
                                  SDL_WINDOW_SHOWN);
        if (gWindow_ == NULL) {
            cerr << "Could not create window. SDL Error: " << SDL_GetError() << endl;
            success = false;
        }
        else {
            int imgFlags = IMG_INIT_PNG;
            if(!(IMG_Init(imgFlags) & imgFlags)) {
                cerr << "Could not initialize SDL_image. SDL_image Error: " << IMG_GetError() << endl;
                success = false;
            }
            else {
                gRenderer_ = SDL_CreateRenderer(gWindow_, -1, SDL_RENDERER_ACCELERATED);

                if (gRenderer_ == NULL) {
                    cerr << "Could not create the renderer. SDL Error: " << SDL_GetError() << endl;
                    success = false;
                }
                else {
                    // ADD ERROR CHECKING
                    gBoardTexture_ = LoadTexture("board.png");
                    gRedPieceTexture_ = LoadTexture("redpiece.png");
                    gYellowPieceTexture_ = LoadTexture("yellowpiece.png");
                }
            }
        }
    }

    return success;
}

SDL_Texture* Graphics::LoadTexture(string path) {
    SDL_Texture* newTexture;
    SDL_Surface* textureSurface = IMG_Load(path.c_str());

    newTexture = SDL_CreateTextureFromSurface(gRenderer_, textureSurface);
    if (newTexture == NULL) {
        cerr << "Could not create texture. SDL Error: " << SDL_GetError() << endl;
    }

    SDL_FreeSurface(textureSurface);
    return newTexture;
}

void Graphics::DrawPieces(int** board) {
    SDL_Rect redRect;
    SDL_Rect yellowRect;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (board[i][j] == 1) {
                redRect = {15, 6, 70, 70};
                redRect.x += (90 * j);
                redRect.y += (80 * i);
                SDL_RenderCopy(gRenderer_, gRedPieceTexture_, NULL, &redRect);
            }
            if (board[i][j] == 2) {
                yellowRect = {15, 6, 70, 70};
                yellowRect.x += (90 * j);
                yellowRect.y += (80 * i);
                SDL_RenderCopy(gRenderer_, gYellowPieceTexture_, NULL, &yellowRect);
            }
        }
    }
}

void Graphics::DrawBoard() {
    SDL_RenderCopy(gRenderer_, gBoardTexture_, NULL, NULL);
}

void Graphics::RenderFrame(int** board) {
    SDL_RenderClear(gRenderer_);
    DrawBoard();
    DrawPieces(board);
    SDL_RenderPresent(gRenderer_);
}

void Graphics::Clean() {
    SDL_DestroyWindow(gWindow_);
    SDL_DestroyRenderer(gRenderer_);

    SDL_DestroyTexture(gBoardTexture_);
    SDL_DestroyTexture(gRedPieceTexture_);
    SDL_DestroyTexture(gYellowPieceTexture_);
}

SDL_Renderer* Graphics::GetRenderer() {
    return gRenderer_;
}

SDL_Window* Graphics::GetWindow() {
    return gWindow_;
}
