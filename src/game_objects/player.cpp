#include "player.hpp"
#include "../game.hpp"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>

Player::Player() {
    this->speed        = BLOCK_SIZE * 4 / FRAME_HATE;
    this->squareRect.w = BLOCK_SIZE;
    this->squareRect.h = BLOCK_SIZE;
    this->squareRect.x = SCREEN_WIDTH / 2 - squareRect.w / 2;
    this->squareRect.y = SCREEN_HEIGHT / 2 - squareRect.h / 2;
}

void Player::update() {
    // to implement
}

void Player::render(SDL_Renderer* window) {
    SDL_SetRenderDrawColor(window, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(window, &this->squareRect);
}

void Player::control(SDL_Event event) {
    switch(event.key.keysym.sym) {
    case SDLK_UP: this->squareRect.y -= this->speed; break;
    case SDLK_DOWN: this->squareRect.y += this->speed; break;
    case SDLK_LEFT: this->squareRect.x -= this->speed; break;
    case SDLK_RIGHT: this->squareRect.x += this->speed; break;
    }
}
