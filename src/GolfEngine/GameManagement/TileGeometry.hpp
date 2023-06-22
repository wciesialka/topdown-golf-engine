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
#include "../Geometry/Shapes/Circle.hpp"
#include <vector>
#include <stdexcept>
#include "../Rendering/Renderable.hpp"

namespace GolfEngine
{
    class TileGeometry : public GolfEngine::Renderable
    {
    public:
        /**
         * @brief Tile size in pixel units.
         */
        static const unsigned int TILE_SIZE = 64;
        static const int GRASS_COLOR = 0x009170ff;
        static const int WALL_COLOR = 0xC0C2C9ff;
        static const int HOLE_COLOR = 0x000000ff;

        TileGeometry(GolfEngine::Vector2 origin) : GolfEngine::Renderable(origin)
        {
            this->line_geometry = new GolfEngine::Line::LineList();
            this->circle_geometry = new GolfEngine::Circle::CircleList();
            this->polygon_geometry = new GolfEngine::Polygon::PolygonList();
        }

        inline bool isPointValid(const GolfEngine::Vector2 &point) const
        {
            float tile_length = (float)(TileGeometry::TILE_SIZE);
            return (point.x >= 0 && point.x < tile_length && point.y >= 0 && point.y < tile_length);
        }

        virtual ~TileGeometry() {
            delete this->line_geometry;
            delete this->circle_geometry;
            delete this->polygon_geometry;
        }

        /**
         * @brief Check if a Line is considered "valid" i.e. within tile bounds.
         *
         * @param line Line to check.
         * @returns True if the line is valid, false is otherwise.
         * @note All lines should be defined in LOCAL SPACE i.e. x and y both have a domain of [0, TILE_LENGTH)
         */
        inline bool isLineValid(const GolfEngine::Line &line) const
        {
            // Bounds checking
            return this->isPointValid(line.a) && this->isPointValid(line.b);
        }

        /**
         * @brief Check if a Circle is considered "valid" i.e. within tile bounds.
         *
         * @param circle Circle to check.
         * @returns True if the circle is valid, false if otherwise.
         * @note Circles, like lines, are defined in Local Space.
         */
        inline bool isCircleValid(const GolfEngine::Circle &circle) const
        {
            // Bounds checking
            float tile_length = (float)(TileGeometry::TILE_SIZE);
            bool top_bounded = (circle.getCentroid().y - circle.getRadius()) >= 0;
            bool left_bounded = (circle.getCentroid().x - circle.getRadius()) >= 0;
            bool bottom_bounded = (circle.getCentroid().y + circle.getRadius()) < tile_length;
            bool right_bounded = (circle.getCentroid().x + circle.getRadius()) < tile_length;
            return top_bounded && left_bounded && bottom_bounded && right_bounded;
        }

        /**
         * @brief Check if a Polygon is considered "valid" i.e. within tile bounds.
         *
         * @param poly Polygon to check.
         * @returns True if the polygon is valid, false otherwise.
         */
        inline bool isPolygonValid(const GolfEngine::Polygon &poly) const
        {
            for (uint i = 0; i < poly.getVertexCount(); i++)
            {
                bool pointValidity = this->isPointValid(poly.getPoint(i));
                if (!pointValidity)
                {
                    return false;
                }
            }
            return true;
        }

        /**
         * @brief Add a line to the tile geometry.
         *
         * Lines define walls, which golfballs will bounce off of.
         *
         * @param line Line to add.
         * @throws std::out_of_range If the Line falls outside of tile bounds.
         */
        inline void addLine(GolfEngine::Line& line)
        {
            if (!this->isLineValid(line))
            {
                throw std::out_of_range("Line falls outside of map geometry.");
            }
            this->line_geometry->push_back(line);
        }

        /**
         * @brief Add a circle to the tile geometry.
         *
         * Circles define round holes, which golfballs will fall out of.
         *
         * @param circle Circle to add.
         * @throws std::out_of_range If the Circle falls outside of tile bounds.
         */
        inline void addCircle(GolfEngine::Circle& circle)
        {
            if (!this->isCircleValid(circle))
            {
                throw std::out_of_range("Circle falls outside of map geometry.");
            }
            this->circle_geometry->push_back(circle);
        }

        /**
         * @brief Add a polygon to the tile geometry.
         *
         * Polygons define shapes holes, which golfballs will fall out of.
         *
         * @param poly Polygon to add.
         * @throws std::out_of_range If the Polygon falls outside of tile bounds.
         */
        inline void addPolygon(GolfEngine::Polygon& poly)
        {
            if (!this->isPolygonValid(poly))
            {
                throw std::out_of_range("Polygon falls outside of map geometry.");
            }
            this->polygon_geometry->push_back(poly);
        }

        /**
         * @brief Check wall collisions on a shape.
         *
         * @param shape Shape to check.
         * @returns True if the shape is in a wall collision, false otherwise.
         */
        inline bool checkWallCollisions(const GolfEngine::Shape &shape)
        {
            for (GolfEngine::Line &line : *this->line_geometry)
            {
                if (shape.intersects(line))
                {
                    return true;
                }
            }
            return false;
        }

        /**
         * @brief Check hole collisions on a shape.
         * 
         * @param shape Shape to check.
         * @returns True if shape is in a hole collision, false otherwise.
         * @note A hole collision is NOT the same as an intersection - the shape's centroid MUST be contained by a hole to count.
        */
        inline bool checkHoleCollisions(const GolfEngine::Shape &shape) {
            GolfEngine::Vector2 point = shape.getCentroid();
            // First, check circles.
            for (GolfEngine::Circle &circle : *this->circle_geometry)
            {
                if (circle.contains(point))
                {
                    return true;
                }
            }
            // Then, check polygons.
            for (GolfEngine::Polygon &poly : *this->polygon_geometry){
                if(poly.contains(point)){
                    return true;
                }
            }
            return false;
        }

        void render(sf::RenderWindow* window);

        void visit(GolfEngine::RenderableVisitor* visitor);

    private:
        GolfEngine::Line::LineList* line_geometry;
        GolfEngine::Circle::CircleList* circle_geometry;
        GolfEngine::Polygon::PolygonList* polygon_geometry;
    };
}

#endif