/**
 * @file main.cpp
 * @brief This file is responsible for putting it all together.
 * 
 * @author Willow Ciesialka
 * @date 2023-06-03
*/

#include "Tests.hpp"
#define RUN_TESTS
#include "GolfEngine/GameManagement/Scene.hpp"
#include "GolfEngine/Rendering/Window.hpp"
#include "GolfEngine/GameManagement/Entities/PolygonEntity.hpp"
#include "GolfEngine/GameManagement/Entities/CircleEntity.hpp"
#include "GolfEngine/Geometry/Shapes/Circle.hpp"


int main(){
    #ifdef RUN_TESTS
    runTests();
    #endif

    GolfEngine::Scene scene;
    GolfEngine::Tile tile;
    GolfEngine::Circle();
    GolfEngine::Window window(&scene, 0x8b8589ff);
    window.beginDisplay();

    return 0;
}
