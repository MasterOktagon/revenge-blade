#include "userinput.h"
#include "helper.h"
#include <chrono>
#include <iostream>

using namespace std;

Vector2D<int32_t> mousePos() {
  int32_t x, y;
  SDL_GetMouseState(&x, &y);
  return Vector2D(x, y);
}

class MovementKey { // TODO: are there dataclasses?
public:
  chrono::time_point<chrono::system_clock> timestamp;
  Vector2D<int32_t> movement_vector;
  SDL_Scancode key;
  bool pressed;
  MovementKey(SDL_Scancode key, Vector2D<int32_t> movement_vector) {
    this->key = key;
    this->movement_vector = movement_vector;
    this->timestamp = chrono::system_clock::now();
    this->pressed = false;
  }
};

MovementKey key_w = MovementKey(SDL_SCANCODE_W, Vector2D<int32_t>(0, -1));
MovementKey key_a = MovementKey(SDL_SCANCODE_A, Vector2D<int32_t>(-1, 0));
MovementKey key_s = MovementKey(SDL_SCANCODE_S, Vector2D<int32_t>(0, 1));
MovementKey key_d = MovementKey(SDL_SCANCODE_D, Vector2D<int32_t>(1, 0));

vector<MovementKey> movement_keys = {key_w, key_a, key_s, key_d};

void observeMovement(Player &player) {
  int32_t timedelta_for_movement = 1000 / player.speed;
  auto keyboard_state = SDL_GetKeyboardState(NULL);
  for (MovementKey &key : movement_keys) {
    bool state = keyboard_state[key.key];
    if (state) {
      cout << "pressed" << endl;
      if (!key.pressed) {
        key.pressed = true;
        key.timestamp = chrono::system_clock::now();
      }
      int32_t delta = chrono::duration_cast<chrono::milliseconds>(
                          chrono::system_clock::now() - key.timestamp)
                          .count();
      int32_t count = delta / timedelta_for_movement;
      cout << count << endl;
      player.pos = player.pos + key.movement_vector * count;
      cout << player.pos.x << " " << player.pos.y << endl;
      key.timestamp =
          key.timestamp + chrono::milliseconds(count * timedelta_for_movement);
    } else {
      cout << "not pressed" << endl;
      key.pressed = false;
    }
  }
}
