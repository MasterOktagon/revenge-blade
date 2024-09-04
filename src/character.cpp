#include "character.h"
#include <vector>

using namespace std;

bool Hitbox::collides(Hitbox hitbox2) {
  return (this->pos.x < (hitbox2.pos.x + hitbox2.dim.x) &&
          (this->pos.x + this->dim.x) > hitbox2.pos.x &&
          this->pos.y < (hitbox2.pos.y + hitbox2.dim.y) &&
          (this->pos.y + this->dim.y) > hitbox2.pos.y);
}

Box Hitbox::getDrawBox() {
  auto box_pos = Vector2D<int32_t>(pos.y + dim.y / 2, pos.z + dim.z);
  auto box_dim = Vector2D<int32_t>(dim.y + pos.y, pos.z) - box_pos;
  return Box(box_pos, box_dim);
}

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
  pos = Vector2D<int32_t>(0, 0);
  sprite = new Spritesheet("assets/characters/outlaw.png", uVector2D(29,1));  
}

void Player::draw(iVector2D offset){
    sprite->draw(pos + offset, uVector2D(0,0));
    
void Hitbox::draw() {};

Player dummyPlayer() {
  Player p = Player{
      Vector3D<int32_t>(20, 120, 70),
      Vector3D<int32_t>(0, 100, 100),
      10,
      100,
  };
  p.weapons.push_back(Jokegun());
  return p;
}

void Entity::draw() {};
