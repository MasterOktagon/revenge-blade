#pragma once

template <typename T> class Vector2D {
public:
  T x;
  T y;
  Vector2D(T x, T y) {
    this->x = x;
    this->y = y;
  };
  Vector2D(){};
  Vector2D operator+(Vector2D v2);
  Vector2D operator-(Vector2D v2);
  T operator*(Vector2D v2);
  Vector2D operator*(T scalar);
};

template <typename T> class Vector3D {
public:
  T x;
  T y;
  T z;
  Vector3D(T x, T y, T z) {
    this->x = x;
    this->y = y;
    this->z = z;
  };
  Vector3D(){};
  Vector3D operator+(Vector3D v2);
  Vector3D operator-(Vector3D v2);
  Vector3D operator*(T scalar);
};

using uVector2D = Vector2D<unsigned int>;
using fVector2D = Vector2D<float>;
