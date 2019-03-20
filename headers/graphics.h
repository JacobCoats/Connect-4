#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class SDL_Window;
class SDL_Surface;
class SDL_Renderer;
class SDL_Texture;

class Graphics {
public:
    bool Init();
    SDL_Texture* LoadTexture(std::string path);
    void DrawPieces(int** board);
    void DrawBoard();
    void RenderFrame(int** board);
    void Clean();
    SDL_Renderer* GetRenderer();
    SDL_Window* GetWindow();
private:
    SDL_Window* gWindow_;
    SDL_Renderer* gRenderer_;
    SDL_Texture* gBoardTexture_;
    SDL_Texture* gRedPieceTexture_;
    SDL_Texture* gYellowPieceTexture_;
};

#endif
