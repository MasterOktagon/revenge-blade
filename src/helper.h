#pragma once 


template <typename T> class Vector2D {
    public:
        T x;
        T y;
        Vector2D (T x, T y){this->x = x; this->y = y;};
        Vector2D (){};
        Vector2D operator+(Vector2D v2);
        Vector2D operator-(Vector2D v2);
        T operator*(Vector2D v2);
        
};

using uVector2D = Vector2D<unsigned int>;
using fVector2D = Vector2D<float>;


