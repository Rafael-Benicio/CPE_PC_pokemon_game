#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>

#include "./../interfaces/game_object.hpp"

class Player : public GameObject {
    public:
    int speed;
    SDL_Rect squareRect;
    Player();
    virtual void update();
    virtual void render(SDL_Renderer* window);
    virtual void control(SDL_Event event);
};

#endif