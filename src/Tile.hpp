/**
 * @file Tile.hpp
 * @brief This file contains the decleration for the Tile class
 *
 * @author Willow Ciesialka
 * @date 2023-06-02
 */

#ifndef TILE_H
#define TILE_H

#define TILE_SIZE 64

#include "Vector2.hpp"
#include <vector>

namespace GolfEngine
{
    typedef std::vector<GolfEngine::Entity *> EntityList;
    class Tile
    {
    public:
        Tile() : entities(EntityList()){};
        /**
         * @brief This function adds an entity to the tile.
         *
         * @param ent The entity to add to the tile.
         * @returns True if the addition was a success, false otherwise.
         */
        bool addEntity(GolfEngine::Entity *ent);

        /**
         * @brief Remove an entity from the tile.
         *
         * @param[in] ent The entity to remove from the tile.
         * @returns True if the removal was a success, false otherwise.
         */
        bool removeEntity(GolfEngine::Entity *ent);

        /**
         * @brief Check if the tile contains an entity.
         *
         * @param[in] ent The entity to find.
         * @returns True if the entity is in the tile, false otherwise.
         */
        inline bool containsEntity(GolfEngine::Entity *ent) { return this->findEntity(ent) != this->entities.end(); };

        /**
         * @brief Get the tile's position.
         * @returns The tile's position.
         */
        inline Vector2 getPosition() { return this->position; };

    private:
        Vector2 position;
        EntityList entities;

        /**
         * @brief Find the entity in the Tile, if it exists.
         *
         * @param[in] entity Entity to find
         * @returns The entity, if it was found.
         */
        EntityList::iterator findEntity(GolfEngine::Entity *entity);
    };
}

#endif