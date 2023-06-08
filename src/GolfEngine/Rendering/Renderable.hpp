/**
 * @file Renderable.hpp
 * @brief This file contains code that defines the Renderable abstract class.
 *
 * The Renderable abstract class declares functions for an instance of a class
 * to be rendered with.
 *
 * @author Willow Ciesialka
 * @date 2023-06-06
 */

#ifndef RENDERABLE_H
#define RENDERABLE_H

#include "../Geometry/Vector2.hpp"
#include <cmath>
#include <SFML/Graphics.hpp>

namespace GolfEngine
{
    const float pi = (float)(std::acos(-1.0));
    const float tau = pi * 2.0; /* My best friend ❤️ */

    class Renderable
    {
    public:
        Renderable() : position(GolfEngine::Vector2::zero),
                       rotation(0)
                       {}

        Renderable(Vector2 pos) : position(pos),
                                  rotation(0)
                                  {}

        Renderable(Vector2 pos, float rotation) : position(pos),
                                                  rotation(0)
                                                  { this->setRotation(rotation); }

        /**
         * @brief Set the object's position
         *
         * @param position New position of object.
         */
        inline void setPosition(const GolfEngine::Vector2 position)
        {
            this->position = position;
        }

        /**
         * @brief Set the rotation of the object.
         *
         * @param radians The new rotation of the object in radians.
         */
        inline void setRotation(float radians)
        {
            if (radians >= GolfEngine::tau)
            {
                radians = fmod(radians, GolfEngine::tau);
            }
            this->rotation = radians;
        }

        /**
         * @brief Get the position of the object.
         *
         * @return object's position.
         */
        inline GolfEngine::Vector2 getPosition() const
        {
            return this->position;
        }

        /**
         * @brief Get the rotation of the object.
         *
         * @return object's rotation, clockwise, in radians.
         */
        inline float getRotation() const
        {
            return this->rotation;
        }

        /**
         * @brief Move the object's position.
         * 
         * @param by Vector to move the position by.
        */
        inline void move(const GolfEngine::Vector2 by){
            this->setPosition(this->getPosition() + by);
        }

        /**
         * @brief Rotate the object by a set amount.
         *
         * @param radians Amount to rotate, clockwise, in radians.
         */
        inline void rotate(float radians)
        {
            this->setRotation(this->rotation + radians);
        }

        /**
         * @brief Render the object on the screen.
         * 
         * @param window SFML Window to render the object onto.
        */
        virtual void render(sf::RenderWindow* window) = 0;

    private:
        // Object properties
        GolfEngine::Vector2 position;

        /**
         * @brief The rotation of the object in radians.
         */
        float rotation;
    };
}

#endif