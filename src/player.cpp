#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>

#include "player.hpp"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

Player::Player() {
    this->squareRect.w = 200;
    this->squareRect.h = 200;
    this->squareRect.x = SCREEN_WIDTH / 2 - squareRect.w / 2;
    this->squareRect.y = SCREEN_HEIGHT / 2 - squareRect.h / 2;
}

void Player::update() {
    printf("Nao faz nada");
}

void Player::render(SDL_Renderer* window) {
    SDL_SetRenderDrawColor(window, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(window, &this->squareRect);
}

void Player::control(SDL_Event event) {
    switch(event.key.keysym.sym) {
    case SDLK_UP: this->squareRect.y -= 1; break;
    case SDLK_DOWN: this->squareRect.y += 1; break;
    case SDLK_LEFT: this->squareRect.x -= 1; break;
    case SDLK_RIGHT: this->squareRect.x += 1; break;
    }
}
