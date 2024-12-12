#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>

#include "./../interfaces/game_object.hpp"

class Player : public GameObject {
    public:
    double speed;
    double speedModifier;

    enum IMAGE_CHAR { DOWN = 0, LEFT = 1, RIGHT = 2, UP = 3 };
    int frame_x      = 0;
    int frameCounter = 0;

    SDL_Rect mainSquare;
    SDL_Rect imageSquare;

    Player();

    void walkingUpdate();

    virtual void update();
    virtual void render(SDL_Renderer* window, SDL_Texture* texture);
    virtual void control(SDL_Event event);
};

#endif