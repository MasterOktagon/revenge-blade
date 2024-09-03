#pragma once 


template <typename T> class Vector2D {
    public:
        T x;
        T y;
        Vector2D (T x, T y);
        Vector2D operator+(Vector2D v2);
        Vector2D operator-(Vector2D v2);
        T operator*(Vector2D v2);
};
