#pragma once

#include <vector>
#include <list>
#include <string>
#include "helper.h"
#include "sprite.hpp"
#include "character.h"

class GridEntity : public Hitbox {
/*
thing that is locked to the map grid
*/
    public:
        Vector2D<int> mapPos;
        GridEntity(){};
        virtual void draw(iVector2D offset){cout << "GridEntity::draw()" << endl;}
};


class TileType : public Spritesheet {
/*
class that defines how a tile of that kind can interact with its surroundings
*/

    public:
        enum SpriteUsage {
            FIRST, // use the first variant
            RANDOM, // use a random variant
            CONNECT_EDGES, // connect to edges
            CONNECT_HIDE_IN_ROOM
        };
        
        TileType(){};
        SpriteUsage spriteUsage; // how the sprites of this spritesheet are used
        Vector2D<int> hitboxSize;
        TileType(string fileName, uVector2D size, SpriteUsage s, Vector2D<int> hitbox);
        
        ~TileType(){ SDL_DestroyTexture(texture); }
};

class Tile : public GridEntity {
    public:
        TileType* type;
        // int adjacent;
        
        Tile(TileType* t, Vector2D<int> pos);

        void draw(iVector2D offset);
};

class Map {
    public:
        Entity* referenceEntity = nullptr; // center camera on this Entity
        list<Hitbox*> scene= {}; // all things to drawScene
        vector<GridEntity*> griddata = {};
        
        Map();
        Map(string filename);
        Map(Vector2D<int> dim);
        
        void draw();
};

namespace gmap{
    void init();
}
extern TileType* dfloor;





