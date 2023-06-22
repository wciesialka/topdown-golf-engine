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

bool Scene::addEntity(GolfEngine::Entity* entity){
    GolfEngine::Vector2 pos = entity->getOrigin();
    GolfEngine::Tile* tile = this->findTile(pos);
    if(tile == nullptr){
        return false;
    }
    tile->addEntity(entity);
    return true;
}

