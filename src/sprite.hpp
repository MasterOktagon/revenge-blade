#pragma once

#include "app.hpp"
#include <SDL2/SDL.h>
#include <string>
#include <map>
#include <vector>

#include "helper.h"

using namespace std;

class Sprite {
/*
Base renderable sprite class
*/
    protected:
        SDL_Texture* texture; // we are using SDL_Texture here because it is faster

    public:
        Sprite(string fileName);
        /*
        open and load a sprite
        */
        
        Sprite();
        /*
        create a Sprite without loading
        */
        
        ~Sprite();
        /*
        cleanup the sprite
        */
        
        virtual void draw(int x, int y);
        /*
        draw this sprite on the App root screen at this position
        */
        
        virtual void draw(Vector2D<int> pos);
        /*
        draw this sprite on the App root screen at this position
        */
};

class Spritesheet : public Sprite {
/*
class managing multiple Sprites in one file
*/
    public:
        uVector2D sheetSize; // in how many images this Spritesheet should be tiled
        
        Spritesheet();
        Spritesheet(string fileName, uVector2D size);
        /*
        open and load a spritesheet
        
        [param filename] name of image file to load
        [param size]     amount of tiles in x/y direction. Must be bigger than 0 on both axis
        */
        
        ~Spritesheet();
        /*
        cleanup the spritesheet
        */
        
        virtual void draw(int x, int y, uVector2D indices);
        /*
        draw this sprite on the App root screen at this position
        
        [param x]       X position
        [param y]       Y position
        [param indices] which image to use (indices)
        */
        
        virtual void draw(Vector2D<int> pos, uVector2D indices);
        /*
        draw this sprite on the App root screen at this position
        
        [param pos]     where to blit
        [param indices] which image to use (indices)
        */
};


class AnimatedSprite : public Spritesheet{
    
    
    
    public:
        map<string, vector<uVector2D>> animations;
        string animation;      // which animation to use
        int animationProgress; // which frame to animate
        
        AnimatedSprite(string fileName, uVector2D size, map<string, vector<uVector2D>> animation);
        /*
        open and load a spritesheet for the animation
        
        [param filename]  name of image file to load
        [param size]      amount of tiles in x/y direction. Must be bigger than 0 on both axis
        [param animation] specified animations and frames
        */
        
        ~AnimatedSprite();
        /*
        cleanup the spritesheet
        */
        
        void draw(int x, int y);
        void draw(Vector2D<int> pos);
        
        void setAnimation(string name);
        /*
        set current animtion to this animation. resets animationProgress.
        */
        
};





