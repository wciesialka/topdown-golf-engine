/**
 * @file Entity.hpp
 * @brief This file contains declerations of the Entity abstract class.
 *
 * @author Willow Ciesialka
 * @date 2023-06-02
 */

#ifndef ENTITY_H
#define ENTITY_H

#include "../../Rendering/Renderable.hpp"
#include "../../Geometry/Vector2.hpp"
#include "../Tag.hpp"
#include <cmath>

namespace GolfEngine
{

    class Entity : public Renderable
    {
    public:
        typedef std::vector<GolfEngine::Entity *> EntityList;

        typedef void (*EntityFunction)(GolfEngine::Entity *);

        Entity() : GolfEngine::Renderable(){};
        Entity(GolfEngine::Vector2 pos) : GolfEngine::Renderable(pos){};
        Entity(GolfEngine::Vector2 pos, float rotation) : GolfEngine::Renderable(pos, rotation){};

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

        /**
         * @brief Get the entity's velocity.
         *
         * @returns The entity's velocity.
         */
        inline GolfEngine::Vector2 getVelocity() const
        {
            return this->velocity;
        }

        /**
         * @brief Get the entity's acceleration.
         *
         * @returns The entity's acceleration.
         */
        inline GolfEngine::Vector2 getAcceleration() const
        {
            return this->acceleration;
        }

        /**
         * @brief Set the entity's velocity.
         *
         * @param vel The entity's new velocity.
         */
        inline void setVelocity(GolfEngine::Vector2 vel)
        {
            this->velocity = vel;
        }

        /**
         * @brief Set the entity's acceleration.
         *
         * @param accel The entity's new acceleration.
         */
        inline void setAcceleration(GolfEngine::Vector2 accel)
        {
            this->acceleration = accel;
        }

        /**
         * @brief Add to the entity's velocity.
         *
         * @param vel Velocity to add.
         */
        inline void addVelocity(GolfEngine::Vector2 vel)
        {
            this->setVelocity(this->getVelocity() + vel);
        }

        /**
         * @brief Add to the entity's acceleration.
         *
         * @param accel Acceleration to add.
         */
        inline void addAcceleration(GolfEngine::Vector2 accel)
        {
            this->setAcceleration(this->getAcceleration() + accel);
        }

        inline void visit(GolfEngine::RenderableVisitor *visitor)
        {
            if (visitor->canView(this->getOrigin()))
            {
                this->render(visitor->getWindow());
            }
        }

        /**
         * @brief Set the entity's tag.
         *
         * @param tag Tag to set.
         */
        inline void setTag(std::string tag)
        {
            this->tag = GolfEngine::Tag(tag);
        }

        inline void setTag(GolfEngine::Tag tag)
        {
            this->tag = tag;
        }

        /**
         * @brief Get the entity's tag.
         *
         * @returns The tag of the Entity.
         */
        inline GolfEngine::Tag getTag()
        {
            return this->tag;
        }

        /**
         * @brief Handle collisions between two entities.
         *
         * @param collider Entity that this entity has collided with.
         */
        virtual void onCollision(Entity *collider) = 0;

    private:
        // Entity properties.
        GolfEngine::Vector2 velocity;
        GolfEngine::Vector2 acceleration;
        GolfEngine::Tag tag;
    };
};

#endif