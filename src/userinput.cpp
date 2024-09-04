#include "userinput.h"
#include "helper.h"

using namespace std;

Vector2D<int32_t> mousePos() {
  int32_t x, y;
  SDL_GetMouseState(&x, &y);
  return Vector2D(x, y);
}
