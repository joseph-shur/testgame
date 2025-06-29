#ifndef GAME_H
#define GAME_H

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Game {
public:
    Game();
    ~Game();

    void init(const char* title, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() { return isRunning; }

    static SDL_Renderer* renderer;
    static SDL_Event event;

private:
    bool isRunning = false;

    SDL_Window* window = nullptr;
};

#endif
