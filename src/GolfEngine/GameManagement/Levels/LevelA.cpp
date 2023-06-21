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

void LevelA::initialize()
{
    GolfEngine::FullTile* start = new GolfEngine::FullTile(GolfEngine::Vector2(0, 0));
    this->addTile(start);
    GolfEngine::FullTile* end = new GolfEngine::FullTile(GolfEngine::Vector2(64, 0));
    this->addTile(end);
    GolfEngine::Golfball* player = new GolfEngine::Golfball(GolfEngine::Vector2(32, 32));
    this->addEntity(player);
    GolfEngine::Goal* goal = new GolfEngine::Goal(GolfEngine::Vector2(96, 32));
    this->addEntity(goal);
}