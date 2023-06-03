/**
 * @file Scene.hpp
 * @brief This file contains declerations for the Scene abstract class.
 *
 * @author Willow Ciesialka
 * @date 2023-06-02
 */

#ifndef SCENE_H
#define SCENE_H

#include "Entity.hpp"
#include "Tile.hpp"
#include <vector>

namespace GolfEngine
{
    class Scene
    {
    public:
        Scene();

        /**
         * @brief This function adds an entity to the scene.
         *
         * @param ent The entity to add to the scene.
         * @returns True if the addition was a success, false otherwise.
         */
        bool addEntity(Entity *ent);

        /**
         * @brief This function adds a tile to the scene.
         *
         * @param tile The tile to add to the scene.
         * @returns True if the addition was a success, false otherwise.
         */
        bool addTile(Tile *tile);

        /**
         * @brief This function finds all entities inside a tile.
         * 
         * @param x x position of tile
         * @param y y position of tile
         * @returns Array of entities in the tile.
         */
        Entity **findEntitiesInTile(int x, int y);

        /**
         * @brief This function finds and returns a tile designated by a position.
         * 
         * @param x x position of tile
         * @param y y position of tile
         * @returns Tile found at given position.
        */
        Tile *findTile(int x, int y);

        /**
         * @brief This function processes all entities that need processing.
         */
        virtual void processEntities() = 0;

    private:
        std::vector<Tile*> tilemap;
        std::vector<int> tilesToUpdate;
    };
}

#endif