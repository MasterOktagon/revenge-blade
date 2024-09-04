
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
  Player player = Player();

  Vector2D<int32_t> pos(0, 0);
  while (true) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
      observeMovement(player, event);
      switch (event.type) {
      case SDL_QUIT:
        exit(0);
        break;

      default:
        break;
      }
    }
    cout << "Playerpos: " << player.pos.x << " " << player.pos.y << endl;
    drawScene();
    SDL_RenderPresent(App.renderer);
  }
  deinit();
  return 0;
}
