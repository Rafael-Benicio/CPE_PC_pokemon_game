#include <SDL2/SDL.h>
#include <stdbool.h>

#include "entry_point.h"

// Define MAX and MIN macros
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

// Define screen dimensions
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

void GAME() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    return;

  SDL_Window *window = SDL_CreateWindow(
      "Basic C SDL project", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
      SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (!window)
    return;

  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if (!renderer)
    return;

  SDL_Rect squareRect;

  squareRect.w = MIN(SCREEN_WIDTH, SCREEN_HEIGHT) / 2;
  squareRect.h = MIN(SCREEN_WIDTH, SCREEN_HEIGHT) / 2;

  squareRect.x = SCREEN_WIDTH / 2 - squareRect.w / 2;
  squareRect.y = SCREEN_HEIGHT / 2 - squareRect.h / 2;

  bool gameIsRunning = true;

  while (gameIsRunning) {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    // Input
    SDL_Event e;

    SDL_WaitEvent(&e);

    if (e.type == SDL_QUIT) {
      gameIsRunning = false;
    }
    // Update

    // Render

    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &squareRect);

    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return;
}
