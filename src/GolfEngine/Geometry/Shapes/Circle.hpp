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
#include "../Constants.hpp"

#define SQR(n) (n*n)

namespace GolfEngine
{
    class Circle : public GolfEngine::Shape
    {
    public:
        Circle(float radius) : GolfEngine::Shape()
        {
            this->setRadius(radius);
        }
        Circle(GolfEngine::Vector2 pos, float radius) : GolfEngine::Shape(pos)
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
        inline float getRadius() const
        {
            return this->radius;
        }

        inline GolfEngine::Vector2 getPosition() const
        {
            return this->getOrigin();
        }

        inline virtual bool contains(GolfEngine::Vector2 point) const
        {
            return (point.distance(this->getCentroid()) <= this->getRadius());
        }

        virtual bool intersects(const GolfEngine::Line *line) const;

        /**
         * @brief Compare if the circle is intersecting another circle.
         * 
         * @param other Circle to compare against.
         * @returns True if there is an intersection, false otherwise.
        */
        inline bool intersects(const GolfEngine::Circle* other) const {
            return this->getPosition().distance(other->getPosition()) <= (this->getRadius() + other->getRadius());
        }

        inline virtual float getPerimeter() const {
            return 2.0 * GolfEngine::pi * this->getRadius();
        }

        virtual float getArea() const {
            return GolfEngine::pi * SQR(this->getRadius());
        }

        virtual GolfEngine::Vector2 getCentroid() const
        {
            return this->getPosition();
        }

        virtual void render(sf::RenderWindow *window);

    private:
        float radius;
    };
}

#undef SQR

#endif