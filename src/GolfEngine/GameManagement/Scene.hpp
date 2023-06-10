/**
 * @file Scene.hpp
 * @brief This file contains declerations for the Scene class.
 *
 * @author Willow Ciesialka
 * @date 2023-06-02
 */

#ifndef SCENE_H
#define SCENE_H

#include "Entities/Entity.hpp"
#include "Tile.hpp"
#include "../Geometry/Vector2.hpp"
#include <vector>
#include <unordered_map>
#include "../Rendering/RenderableVisitor.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>

namespace GolfEngine
{
    class Scene
    {
    public:
        const unsigned int DEFAULT_MAX_SIDE_LENGTH = 64;

        Scene() : tilemap(std::unordered_map<unsigned int, Tile *>()),
                  max_side_length(Scene::DEFAULT_MAX_SIDE_LENGTH){};
        Scene(unsigned int side_length) : tilemap(std::unordered_map<unsigned int, Tile *>()),
                                          max_side_length(side_length){};

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
         * @brief Convert a vector to a tile index.
         *
         * @param vec Vector
         * @returns Index
         */
        inline int getTileIndex(GolfEngine::Vector2 vec) const{
            // floor int
            int x = std::floor(vec.x / GolfEngine::Tile::TILE_SIZE);
            int y = std::floor(vec.y / GolfEngine::Tile::TILE_SIZE);
            int i = x + (y * this->max_side_length);
            return i;
        }

        /**
         * @brief Handle event
         */
        void handleEvent(sf::Event event);

        /**
         * @brief This function finds and returns a tile designated by a position.
         *
         * @param pos Position of tile.
         * @returns Tile found at given position. Returns nullptr if no such tile exists.
         */
        Tile *findTile(GolfEngine::Vector2 pos) const;

        /**
         * @brief Render the scene by visiting all renderables and rendering them.
         *
         * @param visitor A RenderableVisitor responsible for rendering all objects.
         */
        inline void visit(GolfEngine::RenderableVisitor *visitor)
        {
            for (auto it : this->tilemap)
            {
                it.second->visit(visitor);
            }
        };

    private:
        std::unordered_map<unsigned int, Tile *> tilemap;
        unsigned int max_side_length;
    };
}

#endif