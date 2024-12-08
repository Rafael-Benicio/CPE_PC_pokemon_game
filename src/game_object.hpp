#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>

class GameObject {
    public:
    virtual void update() {};
    virtual void render(SDL_Renderer* window) {};
    virtual void control(SDL_Event event) {};
};

#endif