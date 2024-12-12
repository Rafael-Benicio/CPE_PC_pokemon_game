#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_render.h>

#include "../game.hpp"
#include "player.hpp"

#define IDLE_FRAME 0
#define MAX_FRAME 4
#define PLAYER_IMAGE_FRAME_SIZE 64
#define FRAMES_TO_UPDATE (FRAME_HATE / 4)

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

void Player::walkingUpdate() {
    this->frameCounter++;

    if(this->frameCounter % FRAMES_TO_UPDATE == 0) {
        this->frame_x++;

        if(this->frame_x == MAX_FRAME) {
            this->frame_x      = IDLE_FRAME;
            this->frameCounter = 1;
        }
    }

    this->imageSquare.x = PLAYER_IMAGE_FRAME_SIZE * frame_x;
}

void Player::update() {
    this->walkingUpdate();
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
        this->imageSquare.y = PLAYER_IMAGE_FRAME_SIZE * IMAGE_CHAR::UP;
        break;
    case SDLK_DOWN:
        this->mainSquare.y += this->speed * this->speedModifier;
        this->imageSquare.y = PLAYER_IMAGE_FRAME_SIZE * IMAGE_CHAR::DOWN;
        break;
    case SDLK_LEFT:
        this->mainSquare.x -= this->speed * this->speedModifier;
        this->imageSquare.y = PLAYER_IMAGE_FRAME_SIZE * IMAGE_CHAR::LEFT;
        break;
    case SDLK_RIGHT:
        this->mainSquare.x += this->speed * this->speedModifier;
        this->imageSquare.y = PLAYER_IMAGE_FRAME_SIZE * IMAGE_CHAR::RIGHT;
        break;
    }
}
