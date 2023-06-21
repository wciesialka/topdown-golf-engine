/**
 * @file LevelA.cpp
 * @brief This file contains definitions for the "LevelA" Level.
 *
 * @date 2023-06-20
 * @author Willow Ciesialka
 */

#include "LevelA.hpp"
using GolfEngine::LevelA;

#include "../Tiles/FullTile.hpp"
#include "../Entities/Golfball.hpp"
#include "../Entities/Goal.hpp"
#include <iostream>

void LevelA::initialize()
{
    std::cout << "At least we're initializing!" << std::endl;
    GolfEngine::Vector2 start_pos(0, 0);
    GolfEngine::FullTile* start = new GolfEngine::FullTile(start_pos);
    this->addTile(start);
    GolfEngine::Vector2 end_pos(64, 0);
    GolfEngine::FullTile* end = new GolfEngine::FullTile(end_pos);
    this->addTile(end);
    GolfEngine::Golfball* player = new GolfEngine::Golfball(GolfEngine::Vector2(32, 32));
    this->addEntity(player);
    GolfEngine::Goal* goal = new GolfEngine::Goal(GolfEngine::Vector2(96, 32));
    this->addEntity(goal);
}

void LevelA::levelCollisions(GolfEngine::Collision& collision){
    // We have no special cases. Do nothing.
    if(collision.getAttached() == nullptr){
        return;
    }
}