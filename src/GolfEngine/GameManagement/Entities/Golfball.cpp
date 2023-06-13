/**
 * @file Golfball.cpp
 * @brief This file contains definitions for the Golfball class.
 * 
 * @date 2023-06-13
 * @author Willow Ciesialka
*/

#include "Golfball.hpp"
using GolfEngine::Golfball;

void Golfball::onCollision(Entity* collider){
    if(collider->getTag() == "Goal"){
        
    }
}