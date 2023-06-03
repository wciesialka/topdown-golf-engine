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

namespace GolfEngine
{
    class Tile
    {
    public:
        Tile() : position(Vector2::zero){};
        Tile(Vector2 pos) : position(pos){};

    private:
        Vector2 position;
    };
}

#endif