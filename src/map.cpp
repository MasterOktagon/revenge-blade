

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <list>
#include <string>
#include "helper.h"
#include "sprite.hpp"
#include "map.hpp"
#include "character.h"
#include "app.hpp"
#include <iostream>

using namespace std;

TileType::TileType(string fileName, uVector2D size, SpriteUsage s, Vector2D<int> hitbox){
    spriteUsage = s;
    hitboxSize = hitbox;
    texture = IMG_LoadTexture(App.renderer, fileName.c_str());
    sheetSize = size;
    cout << "Sheet Size: {" << sheetSize.x << "," << sheetSize.y << "}" << endl;
    int w,h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    cout << "Tex Size: {" << w << "," << h << "} " << SDL_GetError() << endl;
}
TileType* dfloor;

void gmap::init(){
    //TileType empty(string(""), uVector2D(0,0), TileType::SpriteUsage::FIRST, Vector2D(0,0));
    dfloor = new TileType("assets/tiles/groundtiles-iso.png", uVector2D(1,1), TileType::SpriteUsage::FIRST, Vector2D(0,0));
}


////////////////////////////////////////////////////////

Tile::Tile(TileType* t, Vector2D<int> pos){
    type = t;
    mapPos = pos;
    this->pos = Vector2D(pos.x * 32 + pos.y * -32, pos.x * 16 + pos.y * 16);
}

void Tile::draw(iVector2D offset){
    cout << "Tile::draw()" << endl;
    cout << "Tile pos: {" << pos.x << "," << pos.y << "}" << endl;
    type->draw(pos + offset, uVector2D(0,0));
}

/////////////////////////////////////////////////////

Map::Map(Vector2D<int> dim){

    for(int x = 0; x < dim.x; x++){
        for(int y = 0; y < dim.y; y++){
            griddata.push_back(new Tile(dfloor, Vector2D(x,y)));
            cout << "Griddata size: " << griddata.size() << endl;
            griddata[griddata.size() - 1]->draw(iVector2D(0,0));
        }
    }
    scene.assign(griddata.begin(), griddata.end());
    cout << "Scene: " << scene.size() << endl;
}

bool comp (Hitbox* h1, Hitbox* h2){
    return h1->pos.y > h2->pos.y;
}

void Map::draw(){
    iVector2D offset(0,0);
    int screenWidth, screenHeight;
    SDL_GetRendererOutputSize(App.renderer, &screenWidth, &screenHeight);
    
    if (referenceEntity != nullptr){
        offset = referenceEntity->pos*-1;
    }
    offset = offset + iVector2D(int(screenWidth/2), int(screenHeight/2));
    scene.sort(comp);
    for (Hitbox* h : scene){
        h->draw(offset);
    }
}


