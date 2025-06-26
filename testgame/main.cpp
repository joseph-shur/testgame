#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "Game.h"
#include <iostream>

Game* game = nullptr;

int main(int argc, char* argv[]) {
    game = new Game();

    game->init("My SDL2 Game", 800, 600, false);

    if (!game->running()) {
        std::cerr << "Game failed to start." << std::endl;
        game->clean();
        delete game;
        return 1;
    }

    while (game->running()) {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();
    delete game;
    return 0;
}
