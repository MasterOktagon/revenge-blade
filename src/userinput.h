#pragma once

#include "character.h"
#include "helper.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mouse.h>
#include <stdint.h>

using namespace std;
Vector2D<int32_t> mousePos();

void observeMovement(Player &player);
