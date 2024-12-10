#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_rect.h>
#include <cstdio>
#include <stdbool.h>

#include "game.hpp"
#include "entry_point.h"
#include "player.hpp"

// Define MAX and MIN macros
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

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

    bool gameIsRunning = true;
    SDL_Event event;
    Player player = Player();

    while(gameIsRunning) {
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        // Input
        SDL_PollEvent(&event);
        if(event.type == SDL_QUIT) {
            gameIsRunning = false;
        }

        player.control(event);

        // Update

        // Render

        SDL_RenderClear(renderer);
        player.render(renderer);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return;
}
