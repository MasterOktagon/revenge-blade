
#include <SDL2/SDL.h>
#include <cstdio>
#include <iostream>

#include "app.hpp"
#include "draw.hpp"
#include "sprite.hpp"
#include "userinput.h"
#include "map.hpp"

using namespace std;

int main() {
  cout << "Program started" << endl;

  if (!init()) {
    return 1;
  }
  gmap::init();
  Player player = Player();
  
  Map gamemap(Vector2D(10,10));
  gamemap.scene.insert(gamemap.scene.begin(),&player);
  gamemap.referenceEntity = &player;

  Vector2D<int32_t> pos(0, 0);
  while (true) {
    SDL_Event event;

    observeMovement(player);
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        exit(0);
        break;

      default:
        break;
      }
    }
    //cout << "Playerpos: " << player.pos.x << " " << player.pos.y << endl;
    drawScene();
    //player.draw(player.pos);
    gamemap.draw();
    //s.draw(player.pos.x, player.pos.y, uVector2D(0,0));
    SDL_RenderPresent(App.renderer);
  }
  deinit();
  return 0;
}
