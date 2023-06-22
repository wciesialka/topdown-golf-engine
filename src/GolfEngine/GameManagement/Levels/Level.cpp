/**
 * @file Level.cpp
 * @brief This file contains definitions for the Level abstract class.
 *
 * @date 2023-06-16
 * @author Willow Ciesialka
 */

#include "Level.hpp"
#include "../Entities/Golfball.hpp"
#include <iostream>
using GolfEngine::Level;

// General, shared level collisions.
void Level::onCollision(GolfEngine::Collision &collision)
{
    // Goal collisions.
    if (collision.getAttached()->getTag() == "Goal")
    {
        // Goal shouldn't have any collisions.
        return;
    }
    // Golfball collisions.
    if (collision.getAttached()->getTag() == "Golfball")
    {
        // If golfball hits goal, we win!
        if (collision.getCollider()->getTag() == "Goal")
        {
            this->endScene(true);
            return;
        }
        // If golball hits obstacle, respawn!
        if (collision.getCollider()->getTag() == "Obstacle")
        {
            collision.getAttached()->respawn();
        }
    }
    this->levelCollisions(collision);
}

/**
 * @brief Mouse down event. Fires when the player presses down on a mouse button.
 *
 * @param event Mouse Button event.
 */
void Level::onMouseDown(sf::Event::MouseButtonEvent &event)
{
    GolfEngine::Vector2 target(event.x, event.y);
    this->setTarget(target);
}

/**
 * @brief Mouse up event. Fires when the player presses up on a mouse button.
 *
 * @param event Mouse Button event.
 */

const float MAX_SWING_FORCE = 10000;

void Level::onMouseUp(sf::Event::MouseButtonEvent &event)
{
    GolfEngine::Vector2 current(event.x, event.y);
    GolfEngine::Vector2 force = (this->getTarget() - current) * 10;
    if (force.magnitudeSqr() > (MAX_SWING_FORCE * MAX_SWING_FORCE))
    {
        force = force.normalized() * MAX_SWING_FORCE;
    }
    this->applyPlayerForce(force);
}

/**
 * @brief Mouse Move event. Fires when the player moves the mouse in focus of the Scene.
 *
 * @param event Mouse Move event.
 */
void Level::onMouseMove(sf::Event::MouseMoveEvent &event)
{
    // do nothing
    if (event.x == 42)
    {
        return;
    }
}

const GolfEngine::Tag PLAYER_TAG = GolfEngine::Tag("Golfball");

void Level::applyPlayerForce(const GolfEngine::Vector2 &force)
{
    for (GolfEngine::Entity *golfball : this->findEntitiesWithTag(PLAYER_TAG))
    {
        GolfEngine::Golfball *player = (GolfEngine::Golfball *)(golfball);
        if (player->getState() == GolfEngine::GolfballStates::STILL)
        {
            player->setState(GolfEngine::GolfballStates::MOVING);
            golfball->addAcceleration(force);
        }
    }
}

void Level::frameUpdate(uint dt)
{
    if(this->isPaused()) return;
    this->getTilemap()->reorderEntities();
    // Convert dt (which is in milliseconds) to seconds
    double dt_s = dt / 1000.0;

    // Apply acceleration + velocity
    GolfEngine::Tilemap *map = this->getTilemap();
    GolfEngine::Collision::CollisionList collisions = map->frameUpdate(dt_s);
    for(GolfEngine::Collision& collision : collisions){
        this->onCollision(collision);
    }
}