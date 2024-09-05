
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <vector>
#include <map>
#include <iostream>

#include "app.hpp"
#include "sprite.hpp"
#include "helper.h"

#define ANIMATION_SLOWNESS 5

using namespace std;

Sprite::Sprite(string fileName){
    texture = IMG_LoadTexture(App.renderer, fileName.c_str());

}

Sprite::Sprite(){}

Sprite::~Sprite(){
    SDL_DestroyTexture(texture);
}

void Sprite::draw(int x, int y){
    SDL_Rect dest;

    int w,h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    
    dest.x = x-int(w/2);
    dest.y = y-h;
    dest.w = w;
    dest.h = h;

    SDL_RenderCopy(App.renderer, texture, NULL, &dest);
}

void Sprite::draw(Vector2D<int> pos){
    SDL_Rect dest;

    int w,h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    
    dest.x = pos.x-int(w/2);
    dest.y = pos.y-h;
    dest.w = w;
    dest.h = h;

    SDL_RenderCopy(App.renderer, texture, NULL, &dest);
}



//////////////////////////////////////////////////////

Spritesheet::Spritesheet(){}

Spritesheet::Spritesheet(string fileName, uVector2D size){
    texture = IMG_LoadTexture(App.renderer, fileName.c_str());
    sheetSize = size;
}

Spritesheet::~Spritesheet(){
    SDL_DestroyTexture(texture);
}

void Spritesheet::draw(int x, int y, uVector2D indices){
    SDL_Rect dest;
    SDL_Rect index;

    int w,h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);

    dest.x = x-int(w/2/sheetSize.x);
    dest.y = y-int(h/sheetSize.y);    
    
    index.x = indices.x*int(w/sheetSize.x);
    index.y = indices.y*int(h/sheetSize.y);
    
    dest.w = int(w/sheetSize.x);
    dest.h = int(h/sheetSize.y);
    index.w = int(w/sheetSize.x);
    index.h = int(h/sheetSize.y);

    SDL_RenderCopy(App.renderer, texture, &index, &dest);
}

void Spritesheet::draw(Vector2D<int> pos, uVector2D indices){
    SDL_Rect dest;
    SDL_Rect index;

    int w,h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);

    dest.x = pos.x-int(w/2/sheetSize.x);
    dest.y = pos.y-int(h/sheetSize.y);    
    
    
    index.x = indices.x*int(w/sheetSize.x);
    index.y = indices.y*int(h/sheetSize.y);
    
    dest.w = int(w/sheetSize.x);
    dest.h = int(h/sheetSize.y);
    index.w = int(w/sheetSize.x);
    index.h = int(h/sheetSize.y);
    
    cout << "draw index: {" << index.x << "," << index.y << "}{" << index.w << "," << index.h << "}" << endl;

    SDL_RenderCopy(App.renderer, texture, &index, &dest);
}
//////////////////////////////////////////////////////////////////////////////

AnimatedSprite::AnimatedSprite(string fileName, uVector2D size, map<string, vector<uVector2D>> animation){
    texture = IMG_LoadTexture(App.renderer, fileName.c_str());
    sheetSize = size;
    animations = animation;
    this->animation = "idle";
    animationProgress = 0;
}

AnimatedSprite::~AnimatedSprite(){
    SDL_DestroyTexture(texture);
}

void AnimatedSprite::setAnimation(string name){
    animationProgress = 0;
    animation = name;
}

void AnimatedSprite::draw(int x, int y){
    vector<uVector2D> current = animations[animation];
    Spritesheet::draw(x,y, current[int(animationProgress/ANIMATION_SLOWNESS)]);
    
    animationProgress = (animationProgress + 1) % (current.size() * ANIMATION_SLOWNESS);
}
void AnimatedSprite::draw(Vector2D<int> pos){
    vector<uVector2D> current = animations[animation];
    Spritesheet::draw(pos, current[int(animationProgress/ANIMATION_SLOWNESS)]);
    
    animationProgress = (animationProgress + 1) % (current.size() * ANIMATION_SLOWNESS);
}

