/**
 * @file main.cpp
 * @brief This file is responsible for putting it all together.
 * 
 * @author Willow Ciesialka
 * @date 2023-06-03
*/

#include "Tests.hpp"
#define RUN_TESTS

#include "GolfEngine/Rendering/Window.hpp"

#define SCREEN_W 800
#define SCREEN_H 600

int main(){
    #ifdef RUN_TESTS
    runTests();
    #endif

    GolfEngine::Window window(SCREEN_W, SCREEN_H);

    return 0;
}

#undef SCREEN_W
#undef SCREEN_H