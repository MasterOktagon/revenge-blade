
#include <SDL2/SDL.h>
#include <cstdio>
#include <iostream>

#define SCREEN_HEIGHT 720
#define SCREEN_WIDTH 1280

using namespace std;

int main() {
  cout << "Hello World" << endl;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("Couldn't initialize SDL: %s\n", SDL_GetError());
    exit(1);
  }
  SDL_Window *window =
      SDL_CreateWindow("A Window", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

  if (!window) {
    printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT,
           SDL_GetError());
    exit(1);
  }

  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

  while (true) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        exit(0);
        break;

      default:
        break;
      }
    }
  }

  return 0;
}
