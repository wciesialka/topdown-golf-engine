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

int main(){
    #ifdef RUN_TESTS
    runTests();
    #endif

    GolfEngine::Scene scene;
    GolfEngine::Tile tile(GolfEngine::Vector2(0, 0));
    bool success = scene.addTile(&tile);
    std::cout << success << std::endl;
    GolfEngine::Tile tile2(GolfEngine::Vector2(64, 0));
    std::cout << "Origin after construction: " << tile2.getOrigin() << std::endl;
    success = scene.addTile(&tile2);
    std::cout << success << std::endl;
    GolfEngine::Tile tile3(GolfEngine::Vector2(0, 64));
    success = scene.addTile(&tile3);
    std::cout << success << std::endl;
    GolfEngine::Tile tile4(GolfEngine::Vector2(64, 64));
    success = scene.addTile(&tile4);
    std::cout << success << std::endl;
    GolfEngine::Circle golfball_shape(8);
    golfball_shape.setColor(0xFFFFFF);
    GolfEngine::CircleEntity golfball(&golfball_shape, GolfEngine::Vector2(32, 32));
    if(scene.addEntity(&golfball)){
        std::cout << "Success!" << std::endl;
    }
    GolfEngine::Circle hole_shape(10);
    hole_shape.setColor(0x0);
    GolfEngine::CircleEntity hole(&hole_shape, GolfEngine::Vector2(110, 100));

    GolfEngine::Window window(&scene, 0x8b8589ff);

    window.beginDisplay();

    return 0;
}
