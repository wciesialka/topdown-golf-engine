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
#include <SFML/Graphics.hpp>

using GolfEngine::Tile;

bool Tile::addEntity(GolfEngine::Entity* entity){
    GolfEngine::Vector2 pos = entity->getPosition();
    if(pos.x < this->getPosition().x && pos.x > (this->getPosition().x + TILE_SIZE) &&
       pos.y < this->getPosition().y && pos.y > (this->getPosition().y + TILE_SIZE)){
        return false;
    }
    this->entities.push_back(entity);
    return true;
}

inline GolfEngine::Entity::EntityList::iterator Tile::findEntity(GolfEngine::Entity* entity) {
    return std::find(this->entities.begin(), this->entities.end(), entity);
}

bool Tile::removeEntity(GolfEngine::Entity* entity){
    GolfEngine::Entity::EntityList::iterator it = this->findEntity(entity);
    if(it == this->entities.end()){
        return false;
    }
    this->entities.erase(it);
    return true;
}

void Tile::render(sf::RenderWindow* window){
    for(GolfEngine::Entity* ent : this->entities){
        ent->render(window);
    }
}