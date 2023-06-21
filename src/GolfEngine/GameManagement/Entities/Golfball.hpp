/**
 * @file Golfball.hpp
 * @brief This file contains declerations for the Golfball Entity class.
 *
 * @date 2023-06-13
 * @author Willow Ciesialka
 */

#ifndef GOLFBALL_H
#define GOLFBALL_H

#include "../../Geometry/Vector2.hpp"
#include "CircleEntity.hpp"

namespace GolfEngine
{
    class Golfball : public GolfEngine::CircleEntity
    {
    public:
        static const int RADIUS = 4;
        static const int COLOR = 0xFFFFFF;

        Golfball() : GolfEngine::CircleEntity(Golfball::RADIUS)
        {
            this->getShape()->setColor(Golfball::COLOR);
            this->setTag("Golfball");
        }
        Golfball(const GolfEngine::Vector2& pos) : GolfEngine::CircleEntity(Golfball::RADIUS, pos){
            this->getShape()->setColor(Golfball::COLOR);
            this->setTag("Golfball");
        }
    };
}

#endif