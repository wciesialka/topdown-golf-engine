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
    GolfEngine::Tile* tile = this->findTile(entity->getOrigin());
    if(!tile){
        return false;
    }
    return tile->addEntity(entity);
}