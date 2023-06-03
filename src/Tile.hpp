/**
 * @file Tile.hpp
 * @brief This file contains the decleration for the Tile class
 *
 * @author Willow Ciesialka
 * @date 2023-06-02
 */

#ifndef TILE_H
#define TILE_H

#include "Vector2.hpp"
#include <vector>

namespace GolfEngine
{
    class Tile
    {
    public:
        Tile() : entities(std::vector<Entity*>()) {};
        /**
         * @brief This function adds an entity to the tile.
         *
         * @param ent The entity to add to the tile.
         * @returns True if the addition was a success, false otherwise.
         */
        bool addEntity(Entity *ent);

    private:
        Vector2 position;
        std::vector<Entity*> entities;
    };
}

#endif