#pragma once
#include "Game.h"
#include "ECS.h"
#include "Components.h"

class KeyboardController : public Component {
public:
	TransformComponent* transform;

	void init() override {
		transform = &entity->getComponent<TransformComponent>();
	}

	void update() override {
		int directions = 0;
		bool isMoving;

		if (Game::event.type == SDL_KEYDOWN) {
			switch (Game::event.key.keysym.sym) {
			case SDLK_w: 
				transform->velocity.y = -1;
				directions++;
				isMoving = true;
				break;
			case SDLK_a:
				transform->velocity.x = -1;
				directions++;
				isMoving = true;
				break;
			case SDLK_s:
				transform->velocity.y = +1;
				directions++;
				isMoving = true;
				break;
			case SDLK_d:
				transform->velocity.x = +1;
				directions++;
				isMoving = true;
				break;
			default: 
				break;
			}
		}

		if (Game::event.type == SDL_KEYUP && directions < 2 && isMoving) {
			switch (Game::event.key.keysym.sym) {
			case SDLK_w:
				transform->velocity.y = 0;
				directions--;
				isMoving = false;
				break;
			case SDLK_a:
				transform->velocity.x = 0;
				directions--;
				isMoving = false;
				break;
			case SDLK_s:
				transform->velocity.y = 0;
				directions--;
				isMoving = false;
				break;
			case SDLK_d:
				transform->velocity.x = 0;
				directions--;
				isMoving = false;
				break;
			default:
				break;
			}
		}
	}
};