#include "Game.h"
#include "TextureManager.h"
#include <iostream>

SDL_Texture* playerTex;
SDL_Rect srcR, destR;
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

    playerTex = TextureManager::LoadTexture("assets/Player01Sprite.png", renderer);

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
    cnt++;
    destR.h = 64;
    destR.w = 64;

    destR.x = cnt;

    // Your update logic here
    std::cout << cnt << std::endl;
}

void Game::render() {
    SDL_RenderClear(renderer);
    //tilemap/background
    //player
    //enemy

    SDL_RenderCopy(renderer, playerTex, NULL, &destR);


    SDL_RenderPresent(renderer);
}

void Game::clean() {
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    SDL_Quit();
    SDL_Log("Game cleaned up.");
}
