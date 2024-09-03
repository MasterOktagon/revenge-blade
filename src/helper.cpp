template <typename T>

class Vector2D {
public:
  T x;
  T y;
  Vector2D operator+(Vector2D v2) { return Vector2D(x + v2.x, y + v2.y); }
  Vector2D operator-(Vector2D v2) { return Vector2D(x - v2.x, y - v2.y); }
  T operator*(Vector2D v2) { return x * v2.x + y * v2.y; }
};
