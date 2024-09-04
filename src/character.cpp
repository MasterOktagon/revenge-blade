#include "character.h"
using namespace std;

void Player::switchWeapon() {
  currentWeapon = (currentWeapon + 1) % weapons.size();
}
void Player::useWeapon() {
  weapons.at(currentWeapon).use(Vector2D<int32_t>(0, 0));
  this->energy -= weapons.at(currentWeapon).energy_drain;
}

Player::Player() {
  weapons.push_back(Jokegun());
  currentWeapon = 0;
  energy = 100;
  speed = 100;
  pos = Vector2D<int32_t>(100, 100);
}
