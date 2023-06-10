/**
 * @file Scene.cpp
 * @brief This file contains definitions for the Scene class.
 * 
 * @author Willow Ciesialka
 * @date 2023-06-02
 */

#include "Scene.hpp"
#include "Tile.hpp"
#include "../Rendering/RenderableVisitor.hpp"
#include <iostream>

using GolfEngine::Scene;

GolfEngine::Tile* Scene::findTile(GolfEngine::Vector2 pos) const{
    int i = this->getTileIndex(pos);

    auto result = this->tilemap.find(i);
    // If the tile doesn't exist, return nullptr. 
    if( result == this->tilemap.end()){
        return nullptr;
    } else {
        return result->second;
    }
}

bool Scene::addTile(GolfEngine::Tile* tile){
    std::cout << "Adding tile. Tile pos: ";
    std::cout << tile->getOrigin() << std::endl;
    if(this->findTile(tile->getOrigin())){
        return false;
    }
    int i = this->getTileIndex(tile->getOrigin());
    this->tilemap[i] = tile;
    return true;
}

bool Scene::addEntity(GolfEngine::Entity* entity){
    GolfEngine::Tile* tile = this->findTile(entity->getOrigin());
    if(!tile){
        return false;
    }
    return tile->addEntity(entity);
}

void Scene::handleEvent(sf::Event event){

}