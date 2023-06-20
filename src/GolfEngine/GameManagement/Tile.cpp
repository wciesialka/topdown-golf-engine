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