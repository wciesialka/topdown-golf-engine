/**
 * @file Entity.hpp
 * @brief This file contains declerations of the Entity abstract class.
 *
 * @author Willow Ciesialka
 * @date 2023-06-02
 */

#ifndef ENTITY_H
#define ENTITY_H

#include "Renderable.hpp"
#include "Vector2.hpp"
#include <cmath>

namespace GolfEngine
{

    class Entity : public Renderable
    {
    public:
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
            this->move(this->velocity);
            this->velocity = Vector2::zero;
        }

    private:
        // Entity properties.
        GolfEngine::Vector2 velocity;
        GolfEngine::Vector2 acceleration;
    };
};

#endif