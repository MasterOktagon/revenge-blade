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

template class Vector2D<int32_t>;

template <typename T> Vector3D<T> Vector3D<T>::operator+(Vector3D v2) {
  return Vector3D(x + v2.x, y + v2.y, z + v2.z);
}
template <typename T> Vector3D<T> Vector3D<T>::operator-(Vector3D v2) {
  return Vector3D(x - v2.x, y - v2.y, z - v2.z);
}
template <typename T> Vector3D<T> Vector3D<T>::operator*(T scalar) {
  return Vector3D(x * scalar, y * scalar, z * scalar);
}

template class Vector3D<int32_t>;
