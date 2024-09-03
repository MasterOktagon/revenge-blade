
#include "helper.h"

template <typename T>
Vector2D<T>::Vector2D(T x, T y){
    this->x = x;
    this->y = y;
}
template <typename T>
Vector2D<T> Vector2D<T>::operator+(Vector2D v2) {
    return Vector2D(x + v2.x, y + v2.y);
}
template <typename T>
Vector2D<T> Vector2D<T>::operator-(Vector2D v2) {
    return Vector2D(x - v2.x, y - v2.y);
}
template <typename T>
T Vector2D<T>::operator*(Vector2D v2) {
    return x * v2.x + y * v2.y;
}
