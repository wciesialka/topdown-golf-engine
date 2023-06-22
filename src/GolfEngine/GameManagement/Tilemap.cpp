/**
 * @file Tilemap.cpp
 * @brief This file contains definitions for the Tilemap class.
 *
 * @date 2023-06-16
 * @author Willow Ciesialka
 */

#include "Tilemap.hpp"
using GolfEngine::Tilemap;

GolfEngine::Tile *Tilemap::findTile(GolfEngine::Vector2 pos) const
{
    int i = this->getTileIndex(pos);

    auto result = this->tiles.find(i);
    // If the tile doesn't exist, return nullptr.
    if (result == this->tiles.end())
    {
        return nullptr;
    }
    else
    {
        return result->second;
    }
}

bool Tilemap::addTile(GolfEngine::Tile *tile)
{
    if (this->findTile(tile->getOrigin()))
    {
        return false;
    }
    int i = this->getTileIndex(tile->getOrigin());
    this->tiles[i] = tile;
    return true;
}

GolfEngine::Entity::EntityList Tilemap::findEntitiesWithTag(const GolfEngine::Tag &tag) const
{
    GolfEngine::Entity::EntityList tagged_entities;
    for (GolfEngine::Entity *entity : this->getAllEntities())
    {
        if (entity->hasTag(tag))
        {
            tagged_entities.push_back(entity);
        }
    }
    return tagged_entities;
}

void Tilemap::reorderEntities()
{
    for (auto pair : this->tiles)
    {
        GolfEngine::Tile *tile = pair.second;
        GolfEngine::Entity::EntityList *entities = tile->getEntities();
        GolfEngine::Entity::EntityList copy;
        copy.assign(entities->begin(), entities->end());
        for (GolfEngine::Entity *entity : copy)
        {
            if (!tile->isEntityWithinBounds(entity))
            {
                GolfEngine::Tile *new_tile;
                try
                {
                    new_tile = this->findTile(entity->getOrigin());
                }
                catch (std::out_of_range& ex)
                {
                    // if oob, respawn
                    entity->respawn();
                    continue;
                }
                tile->removeEntity(entity);
                new_tile->addEntity(entity);
            }
        }
    }
}