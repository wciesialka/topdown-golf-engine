/**
 * @file Tile.cpp
 * @brief This file contains definitions for the Tile class.
 * 
 * @author Willow Ciesialka
 * @date 2023-06-04
*/

#include <iostream>
#include "Tile.hpp"
#include "Entities/Entity.hpp"
#include "../Geometry/Vector2.hpp"
#include <algorithm>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Collision.hpp"

using GolfEngine::Tile;

inline GolfEngine::Entity::EntityList::iterator Tile::findEntity(GolfEngine::Entity* entity) {
    return std::find(this->entities->begin(), this->entities->end(), entity);
}

bool Tile::removeEntity(GolfEngine::Entity* entity){
    GolfEngine::Entity::EntityList::iterator it = this->findEntity(entity);
    if(it == this->entities->end()){
        return false;
    }
    this->entities->erase(it);
    return true;
}

GolfEngine::Collision::CollisionList Tile::frameUpdate(double dt_s){
    GolfEngine::Collision::CollisionList collisions;
    for(GolfEngine::Entity* ent : *this->entities){
        //Apply acceleration + velocity
        ent->applyAcceleration(dt_s);
        ent->applyVelocity(dt_s);

        // Apply friciton
        float friction = this->getFriction() * dt_s;
        ent->setVelocity(ent->getVelocity() * friction);

        // Check collisions
        for(GolfEngine::Entity* ent_other : *this->entities){
            if(ent == ent_other) continue;
            if(ent->getEntityType() == GolfEngine::EntityType::CIRCLE){
                GolfEngine::CircleEntity* ent_shape = (GolfEngine::CircleEntity*)(ent);
                if(ent_other->getEntityType() == GolfEngine::EntityType::CIRCLE){
                    GolfEngine::CircleEntity* other_shape = (GolfEngine::CircleEntity*)(ent_other);
                    if(ent_shape->getShape()->intersects(*other_shape->getShape())){
                        GolfEngine::Collision collision(ent, ent_other);
                        collisions.push_back(collision);
                    }
                }
            }
        }

        // Checl if player movin
        if(ent->hasTag("Golfball")){
            GolfEngine::Golfball* player = (GolfEngine::Golfball*)(ent);
            if(player->getState() == GolfballStates::MOVING && player->getAcceleration() == GolfEngine::Vector2::zero){
                player->setState(GolfballStates::STILL);
                player->setRespawnPosition(player->getPosition());
                player->addScore();
            }
        }
    }
    return collisions;
}