#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <map>
#include <string>

class GameObject {
    public:
    virtual void update() {};
    virtual void render(SDL_Renderer* window,
    std::map<std::pmr::string, SDL_Texture*>& texture) {};
    virtual void control(SDL_Event event) {};
};

#endif