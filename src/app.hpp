#pragma once

#include <SDL2/SDL.h>

#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 640


struct app {
    SDL_Window* root;
    SDL_Renderer* renderer;
};

extern app App;
extern bool init();
/*
init and create the window

[return] true if no errors occured
*/
