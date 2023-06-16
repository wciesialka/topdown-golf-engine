/**
 * @file Tilemap.hpp
 * @brief This file contains declerations for the Tilemap class.
 *
 * @date 2023-06-16
 * @author Willow Ciesialka
 */

#ifndef TILEMAP_H
#define TILEMAP_H

#include "../Rendering/Renderable.hpp"
#include "Tile.hpp"
#include <unordered_map>
#include <stdexcept>

namespace GolfEngine
{
    class Tilemap
    {
    public:
        static const unsigned int DEFAULT_SIDE_LENGTH = 64;
        Tilemap() : side_length(Tilemap::DEFAULT_SIDE_LENGTH) {}
        Tilemap(unsigned int side_length) : side_length(side_length) {}

        /**
         * @brief Visit the object with a RenderableVisitor.
         *
         * @param visitor Visitor to visit with.
         */
        inline void visit(GolfEngine::RenderableVisitor *visitor)
        {
            for (auto it : this->tiles)
            {
                it.second->visit(visitor);
            }
        }

        /**
         * @brief This function finds and returns a tile designated by a position.
         *
         * @param pos Position of tile.
         * @returns Tile found at given position. Returns nullptr if no such tile exists.
         */
        Tile *findTile(GolfEngine::Vector2 pos) const;

        /**
         * @brief This function adds a tile to the tilemap.
         *
         * @param tile The tile to add to the tilemap.
         * @returns True if the addition was a success, false otherwise.
         */
        bool Tilemap::addTile(GolfEngine::Tile *tile);

        /**
         * @brief Convert a position vector to a tile index.
         * 
         * Each Tile is stored with an index in the Tilemap's internal unordered map.
         * This function will convert a position vector into an appropriate index.
         *
         * @param vec Position of the Tile to find.
         * @returns Index of the Tile sharing that position in the Tilemap.
         * @throws std::out_of_range If trying to find an index corresponding to a position outside of the Tilemap's limits.
         */
        inline int getTileIndex(GolfEngine::Vector2 vec) const
        {
            // floor int
            int x = std::floor(vec.x / GolfEngine::Tile::TILE_SIZE);
            int y = std::floor(vec.y / GolfEngine::Tile::TILE_SIZE);
            if(x < 0 || x >= this->getSideLength() || y < 0 || y >= this->getSideLength()){
                throw std::out_of_range("Tried to find tile outside of Tilemap limits.");
            }
            int i = x + (y * this->side_length);
            return i;
        }

        /**
         * @brief Return the maximum number of tiles that can be placed on the Tilemap (which can be viewed as a square)'s side.
         * 
         * @returns The maximum side length of the Tilemap.
        */
        inline unsigned int getSideLength() const {
            return this->side_length;
        }

    private:
        unsigned int side_length;
        std::unordered_map<unsigned int, Tile *> tiles;
    };
}

#endif