/**
 * @file Golfball.hpp
 * @brief This file contains declerations for the Golfball Entity class.
 * 
 * @date 2023-06-13
 * @author Willow Ciesialka
*/

#ifndef GOLFBALL_H
#define GOLFBALL_H

#include "CircleEntity.hpp"

namespace GolfEngine {
    class Golfball : public GolfEngine::CircleEntity {
        Golfball() : GolfEngine::CircleEntity(4.0) {
            this->getShape()->setColor(0xFFFFFF);
            this->setTag("Golfball");
        }

        virtual void onCollision(Entity* collider);
    };
}

#endif