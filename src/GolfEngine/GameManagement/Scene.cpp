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
        return result->second;
    }
}

bool Scene::addTile(GolfEngine::Tile* tile){
    int x = (int)(tile->getOrigin().x);
    int y = (int)(tile->getOrigin().y);
    if(this->findTile(x, y)){
        return false;
    }
    unsigned int i = (y * this->max_side_length) + x;
    this->tilemap[i] = tile;
    return true;
}

void Scene::render(GolfEngine::RenderableVisitor visitor){
    for(auto it : this->tilemap){
        visitor.visit(it.second);
    }
}