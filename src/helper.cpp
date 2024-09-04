#include "helper.h"
#include <stdint.h>

/*template <typename T> Vector2D<T>::Vector2D(T x, T y) {
  this->x = x;
  this->y = y;
}*/
template <typename T> Vector2D<T> Vector2D<T>::operator+(Vector2D v2) {
  return Vector2D(x + v2.x, y + v2.y);
}
template <typename T> Vector2D<T> Vector2D<T>::operator-(Vector2D v2) {
  return Vector2D(x - v2.x, y - v2.y);
}
template <typename T> T Vector2D<T>::operator*(Vector2D v2) {
  return x * v2.x + y * v2.y;
}
template <typename T> Vector2D<T> Vector2D<T>::operator*(T scalar) {
  return Vector2D(x * scalar, y * scalar);
}

template class Vector2D<int32_t>; // doesnt work without this, idk why
