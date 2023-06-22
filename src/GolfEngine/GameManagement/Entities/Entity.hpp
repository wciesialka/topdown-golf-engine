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
#include <stdexcept>
#include <iostream>

namespace GolfEngine
{

    enum EntityType {
        SPRITE,
        CIRCLE,
        POLY
    };

    class Entity : public Renderable
    {
    public:
        typedef std::vector<GolfEngine::Entity *> EntityList;

        typedef void (*EntityFunction)(GolfEngine::Entity *);

        Entity() : GolfEngine::Renderable()
        {
            this->setRespawnPosition(this->getPosition());
        };
        Entity(GolfEngine::Vector2 pos) : GolfEngine::Renderable(pos)
        {
            this->setRespawnPosition(this->getPosition());
        };
        Entity(GolfEngine::Vector2 pos, float rotation) : GolfEngine::Renderable(pos, rotation)
        {
            this->setRespawnPosition(this->getPosition());
        };

        /**
         * @brief Apply acceleration to the entity.
         *
         * @param dt Time, in seconds, to factor in.
         * @throws std::domain_error If dt is > 1 or < 0.
         */
        inline void applyAcceleration(float dt = 1)
        {
            if(dt > 1 || dt < 0){
                throw std::domain_error("dt cannot be less than 0 or greater than 1.");
            }
            GolfEngine::Vector2 current_acceleration = this->getAcceleration();
            GolfEngine::Vector2 acceleration = current_acceleration * dt;
            this->addVelocity(acceleration);
            GolfEngine::Vector2 new_acceleration = current_acceleration - acceleration; 
            this->setAcceleration(new_acceleration);
        }

        /**
         * @brief Apply velocity to the entity.
         * 
         * @param dt Time, in seconds, to factor in.
         * @throws std::domain_error If dt is > 1 or < 0.
         */
        inline void applyVelocity(float dt = 1)
        {
            if(dt > 1 || dt < 0){
                throw std::domain_error("dt cannot be less than 0 or greater than 1.");
            }
            GolfEngine::Vector2 current = this->getVelocity();
            GolfEngine::Vector2 velocity = current * dt;
            this->move(velocity);
            GolfEngine::Vector2 new_velocity = current - velocity;
            this->setVelocity(new_velocity);
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
        inline void setVelocity(const GolfEngine::Vector2& vel)
        {
            if(vel.magnitudeSqr() < 1){
                this->velocity = GolfEngine::Vector2::zero;
                return;
            }
            this->velocity = vel;
        }

        /**
         * @brief Set the entity's acceleration.
         *
         * @param accel The entity's new acceleration.
         */
        inline void setAcceleration(const GolfEngine::Vector2& accel)
        {
            if(accel.magnitudeSqr() < 1){
                this->acceleration = GolfEngine::Vector2::zero;
                return;
            }
            this->acceleration = accel;
        }


        /**
         * @brief Move the object's origin.
         *
         * @param by Vector to move the origin by.
         */
        inline void move(const GolfEngine::Vector2& by)
        {
            if(by == GolfEngine::Vector2::zero) return;
            GolfEngine::Vector2 pos = this->getPosition();
            GolfEngine::Vector2 new_pos = pos + by;
            this->setPosition(new_pos);
        }

        /**
         * @brief Add to the entity's velocity.
         *
         * @param vel Velocity to add.
         */
        inline void addVelocity(const GolfEngine::Vector2& vel)
        {
            GolfEngine::Vector2 current = this->getVelocity();
            this->setVelocity(current + vel);
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
            if(!this->isActive()){
                return;
            }
            if (visitor->canView(this->getOrigin()))
            {
                this->render(visitor->getWindow());
            }
        }

        /**
         * @brief Set the entity's tag.
         *
         * @param tag String representing the entity's new tag.
         */
        inline void setTag(std::string tag)
        {
            this->tag = GolfEngine::Tag(tag);
        }

        /**
         * @brief Set the entity's tag.
         * 
         * @param tag Tag to set.
        */
        inline void setTag(GolfEngine::Tag tag)
        {
            this->tag = tag;
        }

        /**
         * @brief Get the entity's tag.
         *
         * @returns The tag of the Entity.
         */
        inline GolfEngine::Tag getTag() const
        {
            return this->tag;
        }

        /**
         * @brief Check if the entity has a matching tag.
         * 
         * @param tag Tag to check
         * @returns True if the entity's tag is the same, false otherwise.
        */
        inline bool hasTag(GolfEngine::Tag tag) const{
            return this->getTag() == tag;
        }

        /**
         * @brief Check if the entity has a tag matching the given string.
         * 
         * @param tag Tag to check.
         * @returns True if the entity's tag is the same, false otherwise.
        */
        inline bool hasTag(std::string tag) const{
            return this->getTag() == tag;
        }

        /**
         * @brief Respawn the entity.
        */
        virtual inline void respawn(){
            this->setAcceleration(GolfEngine::Vector2::zero);
            this->setVelocity(GolfEngine::Vector2::zero);
            this->setPosition(this->getRespawnPosition());
            this->setActiveStatus(true);
        } 

        /**
         * @brief Get the entity's respawn position.
         *
         * @returns The entity's respawn position.
         */
        inline GolfEngine::Vector2 getRespawnPosition() const
        {
            return this->respawn_pos;
        }

        /**
         * @brief Set the entity's respawn position.
         *
         * @param pos New respawn position.
         */
        inline void setRespawnPosition(GolfEngine::Vector2 pos)
        {
            this->respawn_pos = pos;
        }

        /**
         * @brief Set the entity's position.
         *
         * @param pos New position.
         */
        inline void setPosition(GolfEngine::Vector2 pos)
        {
            this->setOrigin(pos);
        }

        /**
         * @brief Get the entity's position.
         *
         * @returns The entity's position.
         */
        inline GolfEngine::Vector2 getPosition() const
        {
            return this->getOrigin();
        }

        virtual EntityType getEntityType() const = 0;

        /**
         * @brief Return the entity's active status.
         *
         * @returns True if the entity is active, false otherwise.
         */
        inline bool isActive() const
        {
            return this->active;
        }

        /**
         * @brief Set the entity's active status.
         *
         * @param status True to enable the entity, false to disable it.
         */
        inline void setActiveStatus(bool status)
        {
            this->active = status;
        }

    private:
        // Entity properties.
        GolfEngine::Vector2 velocity;
        GolfEngine::Vector2 acceleration;
        GolfEngine::Tag tag;
        GolfEngine::Vector2 respawn_pos;

        bool active;
    };
};

#endif