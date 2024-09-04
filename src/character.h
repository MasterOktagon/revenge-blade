#pragma once

#include "helper.h"
#include "weapon.h"
#include <stdint.h>
#include <vector>

using namespace std;
class Entity {
public:
  Vector2D<int32_t> pos;
  float speed;
  int32_t energy;
};

class Player : public Entity {
public:
  vector<Weapon> weapons;
  int32_t currentWeapon;
  void switchWeapon();
  void useWeapon();
  Player();
};
