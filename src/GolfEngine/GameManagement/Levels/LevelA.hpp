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
#include <iostream>

namespace GolfEngine
{
    class LevelA : public Level
    {
    public:
        LevelA() : GolfEngine::Level(2) {}
        
        void initialize();

        inline void endScene(bool winStatus) {
            if(winStatus){
                std::cout << "Congrats!! You win!" << std::endl;
            } else {
                std::cout << "Game Over! Try Again!!" << std::endl;
            }
        }

        void levelCollisions(GolfEngine::Collision& collision);
    };
}

#endif