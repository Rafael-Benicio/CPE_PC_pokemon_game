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

void Player::update() {
    this->walkingMovimentUpdate();
    this->walkingAnimationUpdate();
}

void Player::render(SDL_Renderer* window, std::map<std::pmr::string, SDL_Texture*>& texture) {

    if(texture.find("player") == texture.end()) { // key not founded
        SDL_SetRenderDrawColor(window, 255, 0, 0, 255);
        SDL_RenderDrawRect(window, &this->mainSquare);
        return;
    }

    SDL_RenderCopy(window, texture["player"], &this->imageSquare, &this->mainSquare);
}

void Player::control(SDL_Event event) {
    switch(event.type) {
    case SDL_KEYUP: this->keyupMappaing(event); break;
    case SDL_KEYDOWN: this->keydownMapping(event); break;
    }
}

void Player::keyupMappaing(SDL_Event event) {
    this->keyIsPressed = false;

    if(SDLK_LCTRL == event.key.keysym.sym) {
        this->speedModifier = 1;
    }
}

void Player::keydownMapping(SDL_Event event) {
    this->keyIsPressed = true;

    if(SDLK_LCTRL == event.key.keysym.sym) {
        this->speedModifier = 1.5;
    }

    if(this->movimentIsBlocked)
        return;

    switch(event.key.keysym.sym) {
    case SDLK_UP: this->setMovimentRoutine(0, -1, IMAGE_CHAR::UP); break;
    case SDLK_DOWN: this->setMovimentRoutine(0, 1, IMAGE_CHAR::DOWN); break;
    case SDLK_LEFT: this->setMovimentRoutine(-1, 0, IMAGE_CHAR::LEFT); break;
    case SDLK_RIGHT: this->setMovimentRoutine(1, 0, IMAGE_CHAR::RIGHT); break;
    }
}

void Player::walkingAnimationUpdate() {
    this->frameCounter++;

    if(this->frameCounter % FRAMES_TO_UPDATE == 0) {
        this->frame_x++;

        if(this->frame_x == MAX_FRAME) {
            this->frame_x      = IDLE_FRAME;
            this->frameCounter = 1;
        }
    }

    if(!this->keyIsPressed && !this->movimentIsBlocked) {
        this->frame_x      = IDLE_FRAME;
        this->frameCounter = 1;
    }

    this->imageSquare.x = PLAYER_IMAGE_FRAME_SIZE * frame_x;
}

void Player::setMovimentRoutine(int x, int y, int imageChar) {
    this->movimentIsBlocked = true;
    this->movimentVector.setPossition(x, y);
    this->setPlayerTargetPosition(x, y);
    this->imageSquare.y = PLAYER_IMAGE_FRAME_SIZE * imageChar;
}

void Player::walkingMovimentUpdate() {
    this->mainSquare.y += this->movimentVector.y * this->speed * this->speedModifier;
    this->mainSquare.x += this->movimentVector.x * this->speed * this->speedModifier;

    if(!movimentIsBlocked)
        return;

    if(this->movimentVector.x == 1 &&
    !(this->mainSquare.x >= this->movimentTargetPosition.x)) {
        return;
    } else if(this->movimentVector.x == -1 &&
    !(this->mainSquare.x <= this->movimentTargetPosition.x)) {
        return;
    } else if(this->movimentVector.y == 1 &&
    !(this->mainSquare.y >= this->movimentTargetPosition.y)) {
        return;
    } else if(this->movimentVector.y == -1 &&
    !(this->mainSquare.y <= this->movimentTargetPosition.y)) {
        return;
    }

    if(this->keyIsPressed) {
        this->setMainsSquarePosition(&this->movimentTargetPosition);
        this->setPlayerTargetPosition(
        this->movimentVector.x, this->movimentVector.y);
        return;
    }

    reachPositionTarget();
}

void Player::reachPositionTarget() {
    this->setMainsSquarePosition(&this->movimentTargetPosition);
    this->movimentIsBlocked = false;
    this->movimentVector.setPossition(0, 0);
}

void Player::setMainsSquarePosition(Vector2D* vec) {
    this->mainSquare.x = vec->x;
    this->mainSquare.y = vec->y;
}

void Player::setPlayerTargetPosition(int x, int y) {
    this->movimentTargetPosition.setPossition(
    x * BLOCK_SIZE + this->mainSquare.x, y * BLOCK_SIZE + this->mainSquare.y);
}