/**
 * @file Vector2.hpp
 * @brief This file contains the decleration for the Vector2 class.
 * 
 * @author Willow Ciesialka
 * @date 2023-06-02
*/

#ifndef VECTOR2_H
#define VECTOR2_H

#include <iostream>
#include <math.h>

#define SQR(a) ((a)*(a))

namespace GolfEngine {
    class Vector2 {
        public:
            // Vector properties

            float x;
            float y;

            Vector2() : x(0), y(0) {};
            Vector2(float x_, float y_) : x(x_), y(y_) {};

            /**
             * @brief The zero vector is a vector with zero length and undefined direction.
            */
            static Vector2 zero;

            /**
             * @brief Returns the square of the vector's magnitude (length)
             * 
             * @return The square of the vector's magnitude.
             * @note Magnitude is returned by \ref magnitude "magnitude()" function.
            */
            inline float magnitudeSqr() const { return SQR(this->x) + SQR(this->y); }
            
            /**
             * @brief Returns the vector's magnitude (length).
             * 
             * @return The vector's magnitude.
             * @note This function uses \ref magnitudeSqr "mangitudeSqr()" internally.
            */
            inline float magnitude() const { return sqrt(this->magnitudeSqr()); };

            /**
             * @brief Returns the normalized form of the vector.
             * 
             * The normal form of a vector is defined as a vector that contains the same
             * direction as the vector, but with a length of one.
             * 
             * @return Normalized form of the vector.
            */
            inline Vector2 normalized() const { return Vector2(
                SQR(this->x) / this->magnitudeSqr(),
                SQR(this->y) / this->magnitudeSqr()
            ); }

            // Vector-Vector Arithmetic

            /**
             * @brief Returns the square of the distance between two vectors.
             * 
             * @return The square of the distance between two vectors.
             * @note The distance between two vectors is returned by \ref distance "distance(Vector2)"
            */
            inline float distanceSqr(const Vector2& other) const { 
                return SQR(this->x - other.x) - SQR(this->y - other.y);
            }

            /**
             * @brief Returns the distance between two vectors.
             * 
             * This function returns the Euclidian distance between the two points
             * described by the vectors.
             * 
             * @return The distance between two vectors.
             * @note This function uses \ref distanceSqr "distanceSqr(Vector2)" internally.
            */
            inline float distance(const Vector2& other) const {
                return sqrt(this->distanceSqr(other));
            }

            Vector2 operator+(const Vector2& rhs) const;
            Vector2 operator-(const Vector2& rhs) const;
            Vector2& operator+=(const Vector2& rhs);
            Vector2& operator-=(const Vector2& rhs);
            float operator*(const Vector2& rhs) const; 

            // Vector-Scalar Arithmetic
            Vector2 operator*(float scalar) const;
            Vector2 operator/(float scalar) const;
            inline friend Vector2 operator*(float scalar, const Vector2& vec) {
                return vec * scalar;
            };

            // Comparison
            inline bool operator==(const Vector2& rhs) const{
                return this->x == rhs.x && this->y == rhs.y;
            }
            inline bool operator!=(const Vector2& rhs) const{
                return !(*this == rhs);
            }

            // tostring
            inline friend std::ostream& operator<<(std::ostream& os, const Vector2& vec) {
                os << "Vector2(" << vec.x << ", " << vec.y << ")";
                return os;
            };
    };
}

#undef SQR

#endif