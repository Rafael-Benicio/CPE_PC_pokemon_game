#include "Vector2D.hpp"

void Vector2D::setPossition(int x, int y) {
    this->x = x;
    this->y = y;
}

bool Vector2D::isEqual(Vector2D vec) {
    return (this->y == vec.y && this->x == vec.x);
}
