#pragma once

#include "helper.h"
#include "weapon.h"
#include "sprite.hpp"
#include <stdint.h>
#include <vector>

using namespace std;

class Hitbox {
    public:
        Vector2D<int> pos;
        Vector2D<int> dimensions;
        virtual void draw(iVector2D offset){cout << "Hitbox: {" << pos.x << "," << pos.y << "}" << endl;};
        bool operator < (Hitbox h){
            return pos.y < h.pos.y;
        }
};

class Entity : public Hitbox {
public:
  float speed;
  int32_t energy;
  virtual void draw(){};
};

class Player : public Entity {
public:
  Spritesheet* sprite = nullptr;
  vector<Weapon> weapons;
  int32_t currentWeapon;
  void switchWeapon();
  void useWeapon();
  Player();
  
  void draw(iVector2D offset);
};
