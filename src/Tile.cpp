/**
 * @file Tile.cpp
 * @brief This file contains definitions for the Tile class.
 * 
 * @author Willow Ciesialka
 * @date 2023-06-04
*/

#include "Tile.hpp"
#include "Entity.hpp"
#include "Vector2.hpp"
#include <algorithm>
#include <vector>

using GolfEngine::Tile;

bool Tile::addEntity(GolfEngine::Entity* entity){
    GolfEngine::Vector2 pos = entity->getPosition();
    if(pos.x < this->position.x && pos.x > (this->position.x + TILE_SIZE) &&
       pos.y < this->position.y && pos.y > (this->position.y + TILE_SIZE)){
        return false;
    }
    this->entities.push_back(entity);
    return true;
}

GolfEngine::EntityList::iterator Tile::findEntity(GolfEngine::Entity* entity){
    GolfEngine::EntityList::iterator it;
    it = std::find(this->entities.begin(), this->entities.end(), entity);
    return it;
}

bool Tile::removeEntity(GolfEngine::Entity* entity){
    GolfEngine::EntityList::iterator it = this->findEntity(entity);
    if(it == this->entities.end()){
        return false;
    }
    this->entities.erase(it);
    return true;
}