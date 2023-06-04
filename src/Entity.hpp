/**
 * @file Entity.hpp
 * @brief This file contains declerations of the Entity abstract class.
 *
 * @author Willow Ciesialka
 * @date 2023-06-02
 */

#ifndef ENTITY_H
#define ENTITY_H

#include "Vector2.hpp"
#include <cmath>

namespace GolfEngine
{
    const float pi = (float)(std::acos(-1.0));
    const float tau = pi * 2.0; /* My best friend ❤️ */

    class Entity
    {
    public:
        // Entity properties
        Entity() : position(GolfEngine::Vector2::zero) {}
        Entity(Vector2 pos) : position(pos) {}
        Entity(Vector2 pos, float rotation) : position(pos) { this->setRotation(rotation); }

        /**
         * @brief Set the entity's position
         *
         * @param position New position of entity.
         */
        inline void setPosition(const Vector2 position)
        {
            this->position = position;
        }

        /**
         * @brief Set the rotation of the entity.
         *
         * @param radians The new rotation of the entity in radians.
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
         * @brief Get the position of the Entity.
         *
         * @return Entity's position.
         */
        inline Vector2 getPosition()
        {
            return this->position;
        }

        /**
         * @brief Get the rotation of the Entity.
         *
         * @return Entity's rotation, clockwise, in radians.
         */
        inline float getRotation()
        {
            return this->rotation;
        }

        /**
         * @brief Rotate the entity by a set amount.
         *
         * @param radians Amount to rotate, clockwise, in radians.
         */
        inline void rotate(float radians)
        {
            this->setRotation(this->rotation + radians);
        }

        /**
         * @brief Apply acceleration to the entity.
         *
         * @note This resets the current accumulated acceleration.
         */
        inline void applyAcceleration()
        {
            this->velocity += this->acceleration;
            this->acceleration = Vector2::zero;
        }

        /**
         * @brief Apply velocity to the entity.
         */
        inline void applyVelocity()
        {
            this->position += this->velocity;
            this->velocity = Vector2::zero;
        }

    private:
        // Entity properties
        GolfEngine::Vector2 position;
        GolfEngine::Vector2 velocity;
        GolfEngine::Vector2 acceleration;

        /**
         * @brief The rotation of the entity in radians.
         */
        float rotation;
    };
};

#endif