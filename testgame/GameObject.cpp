#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, int x, int y) {
	objTexture = TextureManager::LoadTexture(textureSheet);

	xpos = x;
	ypos = y;
}

void GameObject::update() {
	xpos++;
	ypos++;

	srcRect.h = 64; 
	srcRect.w = 64;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
}

void GameObject::render() {
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}