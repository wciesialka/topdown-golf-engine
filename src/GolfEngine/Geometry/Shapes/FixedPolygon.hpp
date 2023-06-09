/**
 * @file FixedPolygon.hpp
 * @brief This file contains declerations for the Fixed Polygon shape class.
 *
 * A Fixed Polygon cannot adjust it's maximum number of sides after it has been instantiated.
 *
 * @author Willow Ciesialka
 * @date 2023-06-07
 */

#ifndef FIXEDPOLYGON_H
#define FIXEDPOLYGON_H

#include "Polygon.hpp"
#include "../Vector2.hpp"
#include <stdexcept>

namespace GolfEngine
{
    class FixedPolygon : public GolfEngine::Polygon
    {
    public:
        const static uint DEFAULT_MAX_VERTICES = 3;

        FixedPolygon() : GolfEngine::Polygon(DEFAULT_MAX_VERTICES) {};
        FixedPolygon(uint max_vertices) : GolfEngine::Polygon(max_vertices) {};

        /**
         * @brief Adds a point to the polygon.
         * 
         * @param point New point to add.
         * @throws std::length_error If the polygon has hit it's max vertex count, an exception will be thrown.
        */
        inline void addPoint(GolfEngine::Vector2 point){
            if(this->getVertexCount() == this->getMaxVertices()){
                throw std::length_error("Fixed Polygon has hit it's max amount of vertices.");
            }
            GolfEngine::Polygon::addPoint(point);
        }
    };
}

#endif