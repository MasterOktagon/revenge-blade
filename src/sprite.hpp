#pragma once

#include "app.hpp"
#include <SDL2/SDL.h>
#include <string>

#include "helper.h"

using namespace std;

class Sprite {
/*
Base renderable sprite class
*/
    SDL_Texture* texture; // we are using SDL_Texture here because it is faster

    public:
        Sprite(string fileName);
        /*
        open and load a sprite
        */
        
        ~Sprite();
        /*
        cleanup the sprite
        */
        
        void draw(int x, int y);
        /*
        draw this sprite on the App root screen at this position
        */
        
        void draw(Vector2D<int> pos);
        /*
        draw this sprite on the App root screen at this position
        */
};





