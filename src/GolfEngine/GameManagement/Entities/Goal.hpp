/**
 * @file Goal.hpp
 * @brief This file contains declerations for the Goal class.
 * 
 * @date 2023-06-16
 * @author Willow Ciesialka
*/

#ifndef GOAL_H
#define GOAL_H

#include "../../Geometry/Vector2.hpp"
#include "CircleEntity.hpp"

namespace GolfEngine {
    class Goal : public GolfEngine::CircleEntity {
        public:
            static const int RADIUS = 6;
            static const int COLOR = 0x000000;
            Goal() : GolfEngine::CircleEntity(Goal::RADIUS) {
                this->getShape()->setColor(Goal::COLOR);
                this->setTag("Goal");
            }
            
            Goal(const GolfEngine::Vector2& pos) : GolfEngine::CircleEntity(Goal::RADIUS, pos){
                this->getShape()->setColor(Goal::COLOR);
                this->setTag("Goal");
            }
    };
}

#endif