/**
 * @file Quadrilateral.hpp
 * @brief This file contains declerations for the Quadrilateral shape class.
 *
 * @author Willow Ciesialka
 * @date 2023-06-07
 */

#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include "FixedPolygon.hpp"
#include "../Vector2.hpp"

namespace GolfEngine
{
    class Quadrilateral : public GolfEngine::FixedPolygon
    {
    public:
        Quadrilateral() : GolfEngine::FixedPolygon(4) {}

        Quadrilateral(Vector2 a, Vector2 b, Vector2 c, Vector2 d) : GolfEngine::FixedPolygon(4)
        {
            GolfEngine::FixedPolygon::addPoint(a);
            GolfEngine::FixedPolygon::addPoint(b);
            GolfEngine::FixedPolygon::addPoint(c);
            GolfEngine::FixedPolygon::addPoint(d);
        }
    };
}

#endif