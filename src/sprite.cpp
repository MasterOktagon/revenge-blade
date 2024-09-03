
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#include "app.hpp"
#include "sprite.hpp"
#include "helper.h"

using namespace std;

Sprite::Sprite(string fileName){
    texture = IMG_LoadTexture(App.renderer, fileName.c_str());

}

Sprite::~Sprite(){
    SDL_DestroyTexture(texture);
}

void Sprite::draw(int x, int y){
    SDL_Rect dest;

    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

    SDL_RenderCopy(App.renderer, texture, NULL, &dest);
}

void Sprite::draw(Vector2D<int> pos){
    SDL_Rect dest;

    dest.x = pos.x;
    dest.y = pos.y;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

    SDL_RenderCopy(App.renderer, texture, NULL, &dest);
}



