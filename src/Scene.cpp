/**
 * @file Scene.cpp
 * @brief This file contains definitions for the Scene class.
 * 
 * @author Willow Ciesialka
 * @date 2023-06-02
 */

#include "Scene.hpp"
#include "Tile.hpp"

using GolfEngine::Scene;

GolfEngine::Tile* Scene::findTile(unsigned int x, unsigned int y) const{
    if (x > this->max_side_length || y > this->max_side_length){
        return nullptr;
    }
    unsigned int i = (y * this->max_side_length) + x;

    auto result = this->tilemap.find(i);
    // If the tile doesn't exist, return nullptr. 
    if( result == this->tilemap.end()){
        return nullptr;
    } else {
        return (Tile*)(result->first);
    }
}

bool Scene::addTile(GolfEngine::Tile* tile){
    int x = (int)(tile->getPosition().x);
    int y = (int)(tile->getPosition().y);
    if(this->findTile(x, y)){
        return false;
    }
    unsigned int i = (y * this->max_side_length) + x;
    this->tilemap[i] = tile;
    return true;
}