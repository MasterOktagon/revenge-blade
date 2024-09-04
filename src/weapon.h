#pragma once

#include "helper.h"
#include <iostream>
#include <stdint.h>

class Weapon { // any abbility or weapon that targets a specific position or
               // entity
public:
  int32_t energy_drain;
  virtual void use(Vector2D<int32_t> pos) {};
};

class Jokegun : public Weapon {
public:
  Jokegun();
  void use(Vector2D<int32_t> pos);
};
