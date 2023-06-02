/**
 * @file Entity.hpp
 * @brief This file contains declerations of the Entity abstract class.
 * 
 * @author Willow Ciesialka
 * @date 2023-06-01
*/

#ifndef ENTITY_H
#define ENTITY_H

#include "Vector2.hpp"
#include <cmath>

namespace GolfEngine {
    const float pi = (float)(std::acos(-1.0));
    const float tau = pi*2.0; /* My best friend ❤️ */

    class Entity {
        public:
            // Entity properties
            Entity() : position(GolfEngine::Vector2()) {};
            Entity(Vector2 pos) : position(pos), anchored(false) {};
            Entity(Vector2 pos, float rotation) : position(pos), anchored(false) { this->setRotation(rotation); }
            Entity(Vector2 pos, float rotation, bool frozen) : position(pos), anchored(frozen) { this->setRotation(rotation); }
            ~Entity() {};

            /**
             * @brief Set whether the entity is \ref anchored "anchored" or not.
             * 
             * This function allows control over if the entity is anchored or not.
             * Anchored entities are not affected by force.
             * This may be useful for making gates, etc. controlled by buttons.
             * 
             * @param anchored_status True to anchor an entity, false to unanchor an entity.
            */
            inline void setAnchored(bool anchored_status){ this->anchored = anchored_status; }
            
            /**
             * @brief Apply a force to an entity.
             * 
             * @param direction Nornalized vector representing direction of force.
             * @param force_point Point to apply force at in local space.
             * @param magnitude Magnitude of force. 
            */
            void applyForce(GolfEngine::Vector2 direction, GolfEngine::Vector2 force_point, float magnitude);

            /**
             * @brief Apply acceleration to the entity.
             * 
             * @note This resets the current accumulated acceleration.
            */
            inline void applyAcceleration() {
                this->velocity += this->acceleration;
                this->acceleration = Vector2::zero;
            };

            /**
             * @brief Apply velocity to the entity.
            */
           inline void applyVelocity() { this->position += this->velocity; }

        private:
            // Entity properties
            GolfEngine::Vector2 position;
            GolfEngine::Vector2 velocity;
            GolfEngine::Vector2 acceleration;

            /**
             * @brief Anchored entities aren't affected by force.
            */
            bool anchored;

            /**
             * @brief The rotation of the entity in radians. 
            */ 
            float rotation;

            /**
             * @brief Set the rotation of the entity.
             * 
             * @param radians The new rotation of the entity in radians.
            */
            inline void setRotation(float radians) { this->rotation = fmod(radians, GolfEngine::tau); }
    };  
};

#endif