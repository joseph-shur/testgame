#include "Game.h"
#include <iostream>

Game::Game() {}

Game::~Game() {}

void Game::init(const char* title, int width, int height, bool fullscreen) {
    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        SDL_Log("Subsystems initialized!");

        // SDL3: xpos, ypos removed
        window = SDL_CreateWindow(title, 100, 100, width, height, flags);
        if (window) {
            SDL_Log("Window created!");
        }
        else {
            SDL_Log("Failed to create window: %s", SDL_GetError());
        }

        renderer = SDL_CreateRenderer(window, NULL, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_Log("Renderer created!");
        }
        else {
            SDL_Log("Failed to create renderer: %s", SDL_GetError());
        }

        isRunning = (window != nullptr && renderer != nullptr);
    }
    else {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        isRunning = false;
    }
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
    // Your update logic here
}

void Game::render() {
    SDL_RenderClear(renderer);
    // Your rendering code here
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    SDL_Quit();
    SDL_Log("Game cleaned up.");
}
