
#include "app.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>


app App;

bool init(){

    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
        return false;
    }
    
    App.root = SDL_CreateWindow("A Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_WIDTH, SDL_WINDOW_RESIZABLE);
    
    if (!App.root)
    {
        printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
        return false;
    }
    
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    
    App.renderer = SDL_CreateRenderer(App.root, -1, SDL_RENDERER_ACCELERATED);
    
    if (!App.renderer)
    {
        printf("Failed to create renderer: %s\n", SDL_GetError());
        return false;
    }
    
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    
    return true;
}

void deinit(){
    SDL_DestroyRenderer(App.renderer);
    SDL_DestroyWindow(App.root);
}



