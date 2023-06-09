/**
 * @file Circle.hpp
 * @brief This file contains declerations for the Circle class.
 *
 * @author Willow Ciesialka
 * @date 2023-06-08
 */

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.hpp"
#include <stdexcept>

namespace GolfEngine
{
    class Circle : public GolfEngine::Shape
    {
    public:
        Circle(float radius)
        {
            this->setRadius(radius);
        }

        /**
         * @brief Sets the radius of the circle.
         *
         * @param radius New radius.
         */
        inline void setRadius(float radius)
        {
            if (radius < 0)
            {
                throw std::domain_error("Cannot have a circle with negative radius.");
            }
            this->radius = radius;
        }

        /**
         * @brief Gets the radius of the circle.
         *
         * @returns The radius of the circle.
         */
        inline float getRadius()
        {
            return this->radius;
        }

    private:
        float radius;
    };
}

#endif