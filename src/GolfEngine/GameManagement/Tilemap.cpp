/**
 * @file Tilemap.cpp
 * @brief This file contains definitions for the Tilemap class.
 * 
 * @date 2023-06-16
 * @author Willow Ciesialka
*/

#include "Tilemap.hpp"
using GolfEngine::Tilemap;


GolfEngine::Tile* Tilemap::findTile(GolfEngine::Vector2 pos) const{
    int i = this->getTileIndex(pos);

    auto result = this->tiles.find(i);
    // If the tile doesn't exist, return nullptr. 
    if( result == this->tiles.end()){
        return nullptr;
    } else {
        return result->second;
    }
}

bool Tilemap::addTile(GolfEngine::Tile* tile){
    std::cout << "Adding tile. Tile pos: ";
    std::cout << tile->getOrigin() << std::endl;
    if(this->findTile(tile->getOrigin())){
        return false;
    }
    int i = this->getTileIndex(tile->getOrigin());
    this->tiles[i] = tile;
    return true;
}
