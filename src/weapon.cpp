#include "weapon.h"

// set energy drain and later other stats that are weapon specific and can be
// changed later on
Jokegun::Jokegun() { this->energy_drain = 10; }

// called when mob or player uses the weapon on a target pos
void Jokegun::use(Vector2D<int32_t> pos) {
  std::cout << "PIUU PIIUU " << pos.x << " " << pos.y << std::endl;
}

// maybe add super lvl function in Weapon with dmg formula that can be called
// for weapons that deal dmg
