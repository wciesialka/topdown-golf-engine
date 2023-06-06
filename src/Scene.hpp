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
#include <unordered_map>

namespace GolfEngine
{
    class Scene
    {
    public:
        const unsigned int DEFAULT_MAX_SIDE_LENGTH = 64;

        Scene() : tilemap(std::unordered_map<unsigned int, Tile*>()),
                  tiles_to_update(std::vector<unsigned int>()),
                  max_side_length(Scene::DEFAULT_MAX_SIDE_LENGTH)
                  {};
        Scene(unsigned int side_length) : tilemap(std::unordered_map<unsigned int, Tile*>()),
                  tiles_to_update(std::vector<unsigned int>()),
                  max_side_length(side_length)
                  {};

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
         * @brief This function finds and returns a tile designated by a position.
         * 
         * @param x x position of tile
         * @param y y position of tile
         * @returns Tile found at given position. Returns nullptr if no such tile exists.
        */
        Tile *findTile(unsigned int x, unsigned int y) const;

        /**
         * @brief This function processes all entities that need processing.
         */
        virtual void processEntities() = 0;

    private:
        std::unordered_map<unsigned int, Tile*> tilemap;
        std::vector<unsigned int> tiles_to_update;
        unsigned int max_side_length;
    };
}

#endif