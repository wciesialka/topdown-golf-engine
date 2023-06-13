/**
 * @file Collision.hpp
 * @brief This file contains declerations
 *
 * @date 2023-06-13
 * @author Willow Ciesialka
 */

#ifndef COLLISION_H
#define COLLISION_H

#include "Entities/Entity.hpp"

namespace GolfEngine
{
    class Collision
    {
    public:
        Collision(GolfEngine::Entity *attached, GolfEngine::Entity *collider) : attached(attached), collider(collider){};

        /**
         * @brief Get the attached entity.
         *
         * @returns The attached entity.
         * @note Internally, there is no difference between the "attached" entity and the "collider" entity.
         */
        inline GolfEngine::Entity* getAttached(){
            return this->attached;
        }

        /**
         * @brief Get the colliding entity.
         *
         * @returns The colliding entity.
         * @note Internally, there is no difference between the "attached" entity and the "collider" entity.
         */
        inline GolfEngine::Entity* getCollider(){
            return this->collider;
        }

    private:
        GolfEngine::Entity *attached;
        GolfEngine::Entity *collider;
    };
}

#endif