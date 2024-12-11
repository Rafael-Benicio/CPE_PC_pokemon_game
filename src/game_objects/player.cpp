#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_render.h>

#include "../game.hpp"
#include "player.hpp"

#define PLAYER_IMAGE_FRAME_SIZE 64

Player::Player() {
    this->speed         = ((double)BLOCK_SIZE * 4) / FRAME_HATE;
    this->speedModifier = 1;

    this->imageSquare.w = PLAYER_IMAGE_FRAME_SIZE;
    this->imageSquare.h = PLAYER_IMAGE_FRAME_SIZE;
    this->imageSquare.x = 0;
    this->imageSquare.y = 0;

    this->mainSquare.w = BLOCK_SIZE;
    this->mainSquare.h = BLOCK_SIZE;
    this->mainSquare.x = SCREEN_WIDTH / 2 - mainSquare.w / 2;
    this->mainSquare.y = SCREEN_HEIGHT / 2 - mainSquare.h / 2;
}

void Player::update() {
    // to implement
}

void Player::render(SDL_Renderer* window, SDL_Texture* texture) {
    SDL_RenderCopy(window, texture, &this->imageSquare, &this->mainSquare);
}

void Player::control(SDL_Event event) {
    if(SDLK_LCTRL == event.key.keysym.sym) {
        this->speedModifier = (event.type == SDL_KEYDOWN) ? 1.5 : 1;
    }

    switch(event.key.keysym.sym) {
    case SDLK_UP:
        this->mainSquare.y -= this->speed * this->speedModifier;
        break;
    case SDLK_DOWN:
        this->mainSquare.y += this->speed * this->speedModifier;
        break;
    case SDLK_LEFT:
        this->mainSquare.x -= this->speed * this->speedModifier;
        break;
    case SDLK_RIGHT:
        this->mainSquare.x += this->speed * this->speedModifier;
        break;
    }
}
