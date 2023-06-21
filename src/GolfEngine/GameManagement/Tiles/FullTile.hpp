/**
 * @file FullTile.hpp
 * @brief This file contains the definitions for the "Full Tile" tile.
 * 
 * @date 2023-06-20
 * @author Willow Ciesialka
*/

#ifndef FULLTILE_H
#define FULLTILE_H

#include "../Tile.hpp"

namespace GolfEngine {
    class FullTile : public GolfEngine::Tile {
        public:
            FullTile(const GolfEngine::Vector2& pos) : GolfEngine::Tile(pos) {};

            inline void initialize() {
                /* This tile is a full tile - all open grass. No geometry to report, boss! */
                return;
            }
    };
}

#endif