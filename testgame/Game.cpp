#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include <iostream>

GameObject* player;
GameObject* enemy;

int cnt = 0;

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

    player = new GameObject("assets/Player01Sprite.png", renderer, 0, 0);
    enemy = new GameObject("assets/Player02Sprite.png", renderer, 50, 50);
}

void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
    }
}

void Game::update() {


    player->update();
    enemy->update();

    // Your update logic here
}

void Game::render() {
    SDL_RenderClear(renderer);

    player->render();
    enemy->render();

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    SDL_Quit();
    SDL_Log("Game cleaned up.");
}
