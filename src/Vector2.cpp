/**
 * @file Vector2.cpp
 * @brief This file contains definitions for the Vector2 class.
 * 
 * @author Willow Ciesialka
 * @date 2023-05-30
*/

#include "Vector2.hpp"
using GolfEngine::Vector2;

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

Vector2& Vector2::operator+=(const Vector2& rhs){
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
}

Vector2& Vector2::operator-=(const Vector2& rhs){
    this->x -= rhs.x;
    this->y -= rhs.y;
    return *this;
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

Vector2 Vector2::zero = Vector2(0.0, 0.0);
