/**
 * @file Line.hpp
 * @brief This file defines the Line helper struct.
 *
 * @author Willow Ciesialka
 * @date 2023-06-08
 */

#ifndef LINE_H
#define LINE_H

#include "Vector2.hpp"

namespace GolfEngine
{
    struct Line
    {
        GolfEngine::Vector2 a;
        GolfEngine::Vector2 b;
        Line(GolfEngine::Vector2 start, GolfEngine::Vector2 end) : a(start), b(end){};
        inline float length() const
        {
            return this->a.distance(this->b);
        }
        inline bool operator==(const Line &other) const { return (this->a == other.a) && (this->b == other.b); };
        inline bool operator!=(const Line &other) const { return !(*this == other); }

        /**
         * @brief Returns whether the line intersects a given point or not.
         *
         * @param point Point to compare against.
         * @returns True if the line intersects the point, false otherwise.
         */
        bool intersects(GolfEngine::Vector2 point) const;

        /**
         * @brief Returns whether the line intersects a given line or not.
         * 
         * @param other Line to compare against.
         * @returns True if the lines intersect, false otherwise.
         */
        bool Line::intersects(const Line* other) const;
    };
}

#endif