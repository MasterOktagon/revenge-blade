

Vector2D::Vector2D(T x, T y){
    this->x = x;
    this->y = y;
}
Vector2D<T> Vector2D::operator+(Vector2D v2) {
    return Vector2D(x + v2.x, y + v2.y);
}
Vector2D<T> Vector2D::operator-(Vector2D v2) {
    return Vector2D(x - v2.x, y - v2.y);
}
T Vector2D::operator*(Vector2D v2) {
    return x * v2.x + y * v2.y;
}
