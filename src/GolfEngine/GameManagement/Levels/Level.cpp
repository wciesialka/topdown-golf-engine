/**
 * @file Level.cpp
 * @brief This file contains definitions for the Level abstract class.
 * 
 * @date 2023-06-16
 * @author Willow Ciesialka
*/

#include "Level.hpp"
using GolfEngine::Level;

// General, shared level collisions.
void Level::handleCollision(GolfEngine::Collision& collision){
    // Goal collisions.
    if(collision.getAttached()->getTag() == "Goal"){
        // Goal shouldn't have any collisions.
        return;
    }
    // Golfball collisions.
    if(collision.getAttached()->getTag() == "Golfball"){
        // If golfball hits goal, we win!
        if(collision.getCollider()->getTag() == "Goal"){
            this->endScene(true);
        }
        // If golball hits obstacle, respawn!
        if(collision.getCollider()->getTag() == "Obstacle"){
            collision.getAttached()->respawn();
        }
    }
    this->levelCollisions(collision);
}