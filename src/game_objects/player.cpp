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

    this->squareRect.w = BLOCK_SIZE;
    this->squareRect.h = BLOCK_SIZE;
    this->squareRect.x = SCREEN_WIDTH / 2 - squareRect.w / 2;
    this->squareRect.y = SCREEN_HEIGHT / 2 - squareRect.h / 2;
}

void Player::update() {
    // to implement
}

void Player::render(SDL_Renderer* window, SDL_Texture* texture) {
    SDL_RenderCopy(window, texture, &this->imageSquare, &this->squareRect);
}

void Player::control(SDL_Event event) {
    if(SDLK_LCTRL == event.key.keysym.sym) {
        this->speedModifier = (event.type == SDL_KEYDOWN) ? 1.5 : 1;
    }

    switch(event.key.keysym.sym) {
    case SDLK_UP:
        this->squareRect.y -= this->speed * this->speedModifier;
        break;
    case SDLK_DOWN:
        this->squareRect.y += this->speed * this->speedModifier;
        break;
    case SDLK_LEFT:
        this->squareRect.x -= this->speed * this->speedModifier;
        break;
    case SDLK_RIGHT:
        this->squareRect.x += this->speed * this->speedModifier;
        break;
    }
}
