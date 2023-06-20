/**
 * @file LevelA.hpp
 * @brief This file contains declerations for the first level of the Golf Game.
 *
 * @date 2023-06-19
 * @author Willow Ciesialka
 */

#ifndef LEVELA_H
#define LEVELA_H

#include "Level.hpp"

namespace GolfEngine
{
    class LevelA : public Level
    {
    public:
        LevelA() : GolfEngine::Level(8) {}
        
    };
}

#endif