
#include <SDL2/SDL.h>
#include <cstdio>
#include <iostream>

#include "app.hpp"
#include "draw.hpp"
#include "sprite.hpp"
#include "userinput.h"

using namespace std;

int main() {
  cout << "Program started" << endl;

  if (!init()) {
    return 1;
  }

  Vector2D<int32_t> pos(0, 0);
  while (true) {
    SDL_Event event;
    pos = mousePos();
    cout << pos.x << " " << pos.y << endl;

    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        exit(0);
        break;

      default:
        break;
      }
    }
    drawScene();
    SDL_RenderPresent(App.renderer);
  }
  deinit();
  return 0;
}
