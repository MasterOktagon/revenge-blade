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

iVector2D Hitbox::get2DPos(){
    return iVector2D(-pos.x + pos.y, -int(pos.x/2) - int(pos.y/2) + pos.z);
}

void Player::switchWeapon() {
  currentWeapon = (currentWeapon + 1) % weapons.size();
}
void Player::useWeapon() {
  weapons.at(currentWeapon).use(Vector2D<int32_t>(0, 0));
  this->energy -= weapons.at(currentWeapon).energy_drain;
}

void Player::draw(iVector2D offset){
    sprite->draw(get2DPos() + offset, uVector2D(0,0));
}
    
void Hitbox::draw(iVector2D offset) {};

Player dummyPlayer() {
  Player p = Player{
      Vector3D<int32_t>(20, 120, 70),
      Vector3D<int32_t>(0, 100, 100),
      100,
      100,
  };
  p.sprite = new Spritesheet("assets/characters/outlaw.png", uVector2D(29,1));  
  p.weapons.push_back(Jokegun());
  return p;
}

void Entity::draw(iVector2D offset) {};
