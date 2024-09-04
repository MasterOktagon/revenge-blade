#pragma once

#include "helper.h"
#include "weapon.h"
#include <stdint.h>
#include <vector>

using namespace std;

class Box {
public:
  Vector2D<int32_t> pos;
  Vector2D<int32_t> dim;
  Box(Vector2D<int32_t> pos, Vector2D<int32_t> dim) : pos(pos), dim(dim){};
};

class Hitbox {
public:
  Vector3D<int32_t> dim;
  Vector3D<int32_t> pos;
  bool collides(Hitbox hitbox2);
  Hitbox(Vector3D<int32_t> dim, Vector3D<int32_t> pos) {
    this->pos = pos;
    this->dim = dim;
  };
  void draw();
  Box getDrawBox();
};

class Entity : public Hitbox {
public:
  float speed;
  Entity(Vector3D<int32_t> dim, Vector3D<int32_t> pos, float speed)
      : Hitbox(dim, pos), speed(speed){};
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
  Player(Vector3D<int32_t> dim, Vector3D<int32_t> pos, float speed,
         int32_t energy)
      : ItsAlive(dim, pos, speed, energy), currentWeapon(0),
        weapons(vector<Weapon>()){};
};

Player dummyPlayer();

// class Mob : public ItsAlive {};
