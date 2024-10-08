#pragma once

#include "helper.h"
#include "sprite.hpp"
#include "weapon.h"
#include <stdint.h>
#include <vector>

using namespace std;

class Hitbox {
public:
  Vector3D<int32_t> dim;
  Vector3D<int32_t> pos;
  bool collides(Hitbox hitbox2);
  Spritesheet *sprite = nullptr;
  Hitbox(Vector3D<int32_t> dim, Vector3D<int32_t> pos) {
    this->pos = pos;
    this->dim = dim;
  };
  iVector2D get2DPos();
  Hitbox() {
    dim = Vector3D<int32_t>(0, 0, 0);
    pos = Vector3D<int32_t>(0, 0, 0);
  };
  virtual void draw(iVector2D offset);
};

class Entity : public Hitbox {
public:
  float speed;
  Entity(Vector3D<int32_t> dim, Vector3D<int32_t> pos, float speed)
      : Hitbox(dim, pos), speed(speed){};
  virtual void draw(iVector2D offset);
};

// class Bullet : public Entity {
//   // data like direction, damage and explosion radius etc
// };

class ItsAlive : public Entity {
public:
  int32_t energy;
  ItsAlive(Vector3D<int32_t> dim, Vector3D<int32_t> pos, float speed,
           int32_t energy)
      : Entity(dim, pos, speed), energy(energy){};
};

class Player : public ItsAlive {
public:
  vector<Weapon> weapons;
  int32_t currentWeapon;
  void switchWeapon();
  void useWeapon();

  void draw(iVector2D offset);
  Player(Vector3D<int32_t> dim, Vector3D<int32_t> pos, float speed,
         int32_t energy)
      : ItsAlive(dim, pos, speed, energy), currentWeapon(0),
        weapons(vector<Weapon>()){};
};

extern Player dummyPlayer();

// class Mob : public ItsAlive {};
