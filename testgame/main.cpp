#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "Game.h"
#include <iostream>

Game* game = nullptr;

int main(int argc, char* argv[]) {

    const int FPS = 60;
    const int frameDelay = 1000 / FPS; //delay based on fps

    Uint32 frameStart; //giant integer
    int frameTime;

    game = new Game();

    game->init("My SDL2 Game", 800, 600, false);

    if (!game->running()) {
        std::cerr << "Game failed to start." << std::endl;
        game->clean();
        delete game;
        return 1;
    }

    while (game->running()) {

        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();
    delete game;
    return 0;
}
