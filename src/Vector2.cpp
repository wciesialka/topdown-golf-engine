/**
 * @file Vector2.cpp
 * @brief This file contains definitions for the Vector2 class.
 * 
 * @author Willow Ciesialka
 * @date 2023-05-30
*/

#include "Vector2.hpp"

// Vector-Vector Arithmetic

Vector2 Vector2::operator+(const Vector2& rhs) const{
    return Vector2{
        this->x + rhs.x,
        this->y + rhs.y
    };
}

Vector2 Vector2::operator-(const Vector2& rhs) const{
    return Vector2{
        this->x - rhs.x,
        this->y - rhs.y
    };
}

float Vector2::operator*(const Vector2& rhs) const{
    return (this->x * rhs.x) + (this->y * rhs.y);
}

// Vector-Scalar Arithmetic

Vector2 Vector2::operator*(float scalar) const{
    return Vector2(
        this->x * scalar,
        this->y * scalar
    );
}

Vector2 Vector2::operator/(float scalar) const{
    return Vector2(
        this->x / scalar,
        this->y / scalar
    );
}

Vector2 operator*(float scalar, const Vector2& vec){
    return vec * scalar;
}

// tostring
std::ostream& operator<<(std::ostream& os, const Vector2& vec){
    os << "Vector2(" << vec.x << ", " << vec.y << ")";
    return os;
}