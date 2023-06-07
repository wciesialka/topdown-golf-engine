/**
 * @file main.cpp
 * @brief This file is responsible for putting it all together.
 * 
 * @author Willow Ciesialka
 * @date 2023-06-03
*/

#include "Tests.hpp"
// #define RUN_TESTS
#include "GameManagement/Scene.hpp"
#include "Rendering/Window.hpp"

int main(){
    #ifdef RUN_TESTS
    runTests();
    #endif

    GolfEngine::Scene scene;
    GolfEngine::Window window(&scene, 0x8b8589ff);
    window.beginDisplay();

    return 0;
}
