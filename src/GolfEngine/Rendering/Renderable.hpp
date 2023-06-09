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
#include "RenderableVisitor.hpp"
#include <SFML/Graphics.hpp>
#include "../Geometry/Constants.hpp"

namespace GolfEngine
{

    class Renderable
    {
    public:
        Renderable() : origin(GolfEngine::Vector2::zero),
                       rotation(0)
        {
        }

        Renderable(const Vector2& pos) : origin(pos),
                                  rotation(0)
        {
        }

        Renderable(const Vector2& pos, float rotation) : origin(pos),
                                                  rotation(0)
        {
            this->setRotation(rotation);
        }

        /**
         * @brief Set the object's origin
         *
         * @param origin New origin of object.
         */
        inline void setOrigin(const GolfEngine::Vector2 origin)
        {
            this->origin = origin;
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
         * @brief Get the origin of the object.
         *
         * @return object's origin.
         */
        inline GolfEngine::Vector2 getOrigin() const
        {
            return this->origin;
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
        virtual void render(sf::RenderWindow *window) = 0;

        /**
         * @brief Visit the object with a RenderableVisitor.
         * 
         * @param visitor Visitor to visit with.
        */
        virtual void visit(GolfEngine::RenderableVisitor* visitor) = 0;

        /**
         * @brief Convert a local-space coordinate to a world-space coordinate.
         *
         * @param local Local-space coordinate.
         * @returns World-space coordinate.
         */
        inline GolfEngine::Vector2 localToWorld(GolfEngine::Vector2 local) const
        {
            return this->origin + local;
        }

        /**
         * @brief Convert a world-space coordinate to a local-space coordinate.
         *
         * @param world World-space coordinate.
         * @returns Local-space coordinate.
         */
        inline GolfEngine::Vector2 worldToLocal(GolfEngine::Vector2 world) const
        {
            return world - this->origin;
        }

    private:
        // Object properties
        GolfEngine::Vector2 origin;

        /**
         * @brief The rotation of the object in radians.
         */
        float rotation;
    };
}

#endif