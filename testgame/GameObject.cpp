#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, SDL_Renderer* ren, int x, int y) {
	renderer = ren;
	objTexture = TextureManager::LoadTexture(textureSheet, ren);

	xpos = x;
	ypos = y;
}

void GameObject::update() {
	xpos++;
	ypos++;

	srcRect.h = 256; 
	srcRect.w = 256;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
}

void GameObject::render() {
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}