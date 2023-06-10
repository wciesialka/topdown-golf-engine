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

bool Tile::addEntity(GolfEngine::Entity* entity){
    GolfEngine::Vector2 pos = entity->getOrigin();
    std::cout << pos << std::endl;
    if(pos.x <= this->getOrigin().x && pos.x >= (this->getOrigin().x + Tile::TILE_SIZE) &&
       pos.y <= this->getOrigin().y && pos.y >= (this->getOrigin().y + Tile::TILE_SIZE)){
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
    sf::RectangleShape rectangle(sf::Vector2f(Tile::TILE_SIZE, Tile::TILE_SIZE));
    sf::Vector2f render_pos(this->getOrigin().x, this->getOrigin().y);
    rectangle.setPosition(render_pos);
    rectangle.setFillColor(sf::Color::Green);

    window->draw(rectangle);
}