/**
 * @file TileGeometry.hpp
 * @brief This file contains the definitions for TileGeometry
 *
 * Tile Geometry is defined by a list of lines which the golfball will bounce off of, and a
 * list of Polygons and Circles that act as holes.
 * If a Tile does not have any lines on an edge, the golfball will fall out into either the void
 * or another Tile.
 * All lines should be defined in LOCAL SPACE i.e. x and y both have a domain of [0, TILE_LENGTH)
 *
 * @date 2023-06-19
 * @author Willow Ciesialka
 */

#ifndef TILEGEOMETRY_H
#define TILEGEOMETRY_H

#include "../Geometry/Line.hpp"
#include "../Geometry/Shapes/Polygon.hpp"
#include "../Geometry/Shapes/"
#include <vector>
#include <stdexcept>

namespace GolfEngine
{
    class TileGeometry
    {
    public:
        /**
         * @brief Tile size in pixel units.
        */
        static const unsigned int TILE_SIZE = 64;

        TileGeometry() {
            this->line_geometry = GolfEngine::Line::LineList();
        }

        /**
         * @brief Check if a Line is considered "valid" i.e. within tile bounds.
         * 
         * @param line Line to check.
         * @returns True if the line is valid, false is otherwise.
         * @note All lines should be defined in LOCAL SPACE i.e. x and y both have a domain of [0, TILE_LENGTH)
        */
        inline bool isLineValid(const GolfEngine::Line& line) const {
            // Bounds checking
            float tile_length = (float)(TileGeometry::TILE_SIZE);
            bool top_bounded = line.a.y >= 0 && line.b.y >= 0;
            bool left_bounded = line.a.x >= 0 && line.b.y >= 0;
            bool bottom_bounded = line.a.y < tile_length && line.b.y < tile_length;
            bool right_bounded = line.a.x < tile_length && line.b.x < tile_length;
            return top_bounded && left_bounded && bottom_bounded && right_bounded;
        }

        inline void addLine(const GolfEngine::Line line) {
            if(!isLineValid(line)){
                throw std::out_of_range("Line falls outside of map geometry.");
            }
            this->line_geometry.push_back(line);
        }

        void checkIntersection()

    private:
        GolfEngine::Line::LineList line_geometry;
        GolfEngine::Circle::CircleList circle_geometry;
        GolfEngine::Polygon::PolygonList polygon_geometry;
    };
}

#endif