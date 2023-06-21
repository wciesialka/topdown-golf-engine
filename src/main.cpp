/**
 * @file main.cpp
 * @brief This file is responsible for putting it all together.
 * 
 * @author Willow Ciesialka
 * @date 2023-06-03
*/

#include "GolfEngine/Rendering/Window.hpp"
#include "GolfEngine/GameManagement/Levels/LevelA.hpp"

#define SCREEN_W 800
#define SCREEN_H 600

int main(){
    GolfEngine::Window window(SCREEN_W, SCREEN_H);
    GolfEngine::LevelA level;
    window.loadLevel(&level);
    window.beginDisplay();

    return 0;
}

#undef SCREEN_W
#undef SCREEN_H