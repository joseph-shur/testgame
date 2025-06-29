#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "Components.h"
#include "Vector2D.h"

Map* map;

SDL_Renderer* Game::renderer = nullptr;

SDL_Event Game::event;

Manager manager;
auto& player(manager.addEntity());

Game::Game() {}

Game::~Game() {}

void Game::init(const char* title, int width, int height, bool fullscreen) {
    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }

        isRunning = true;
    }

    map = new Map();

    player.addComponent<TransformComponent>(0, 0);
    player.addComponent<SpriteComponent>("assets/player.png");
    player.addComponent<KeyboardController>();
}

void Game::handleEvents() {

    SDL_PollEvent(&event);

    switch (event.type) {
    case SDL_QUIT :
        isRunning = false;
        break;
    default: 
        break;
    }
}

void Game::update() {

    manager.refresh();
    manager.update();

}

void Game::render() {
    SDL_RenderClear(renderer);
    map->DrawMap();

    manager.draw();
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    SDL_Quit();
    SDL_Log("Game cleaned up.");
}
