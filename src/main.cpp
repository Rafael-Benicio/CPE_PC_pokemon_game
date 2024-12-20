#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_rect.h>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <stdbool.h>
#include <string>

#include "./game_objects/player.hpp"
#include "./interfaces/game_object.hpp"
#include "entry_point.h"
#include "game.hpp"

#define TARGET_DELTA_TICK 1000 / FRAME_HATE

void GAME() {
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
        return;

    SDL_Window* window = SDL_CreateWindow("Basic C SDL project", SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(!window)
        return;

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(!renderer)
        return;

    // Game Logic =================================================

    bool gameIsRunning = true;
    SDL_Event event;
    std::map<std::pmr::string, SDL_Texture*> textures;
    std::list<GameObject*> game_entitys = { new Player() };

    textures.insert({ "player", IMG_LoadTexture(renderer, "assets/main_char.png") });

    while(gameIsRunning) {
        const int START_TICK = SDL_GetTicks();

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        // Input
        SDL_PollEvent(&event);
        if(event.type == SDL_QUIT) {
            gameIsRunning = false;
        }

        for(GameObject* entity : game_entitys) {
            entity->control(event);
        }

        // Update

        for(GameObject* entity : game_entitys) {
            entity->update();
        }

        // Render

        SDL_RenderClear(renderer);

        for(GameObject* entity : game_entitys) {
            entity->render(renderer, textures);
        }

        SDL_RenderPresent(renderer);

        // CAPPING FRAME_HATE
        const int DELTA_TICK = SDL_GetTicks() - START_TICK;

        if(DELTA_TICK < TARGET_DELTA_TICK) {
            SDL_Delay(TARGET_DELTA_TICK - DELTA_TICK);
        }
    }

    // SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return;
}
