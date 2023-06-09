/**
 * @file Line.cpp
 * @brief Contains definitions for the Line struct.
 * 
 * @author Willow Ciesialka
 * @date 2023-06-08
*/

#include "Line.hpp"
#include "Vector2.hpp"
using GolfEngine::Line;

#define ABS(n) ((n < 0) ? (-n) : n )
#define MAX_CLOSENESS 0.01
#define IS_APPROXIMATELY(n, m) (ABS((n-m)) < MAX_CLOSENESS)

bool Line::intersects(GolfEngine::Vector2 point) const {
    float d1 = point.distance(this->a);
    float d2 = point.distance(this->b);

    float dsum = (d1+d2);

    if( IS_APPROXIMATELY(dsum, this->length()) ){
        return true;
    }
    return false;
}

bool Line::intersects(const Line& other) const {
    float denominator = ((this->b.x - this->a.x) * (other.b.y - other.a.y)) - ((this->b.y - this->a.y) * (other.b.x - other.a.x));
    float numerator1 = ((this->a.y - other.a.y) * (other.b.x - other.a.x)) - ((this->a.x - other.a.x) * (other.b.y - other.a.y));
    float numerator2 = ((this->a.y - other.a.y) * (this->b.x - this->a.x)) - ((this->a.x - other.a.x) * (this->b.y - this->a.y));

    if(denominator == 0) {
        return (numerator1 == 0) && (numerator2 == 0);
    } 

    float r = numerator1 / denominator;
    float s = numerator2 / denominator;

    return (r >= 0 && r <= 1) && (s >= 0 && s <= 0);
}

#undef IS_APPROXIMATELY
#undef MAX_CLOSENESS
#undef ABS