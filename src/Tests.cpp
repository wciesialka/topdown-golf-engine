/**
 * @file Tests.cpp
 * @brief This file is responsible for testing general program correctness.
 * 
 * @author Willow Ciesialka
 * @date 2023-06-04
*/

#include "Tests.hpp"
#include "Vector2.hpp"
#include <iostream>
#include <cassert>

void vectorTests(){
    GolfEngine::Vector2 a(0, 0);
    GolfEngine::Vector2 b(2, 2);
    GolfEngine::Vector2 c(0, 0);
    GolfEngine::Vector2 d(1, 1);
    // Comparison
    assert(a != b); 
    assert(a == c);
    // Arithmetic
    assert(a.distanceSqr(b) == 8.0);
    assert(b.distanceSqr(a) == 8.0);
    assert((d*2) == b);
    assert((2*d) == (d*2));
}

void runTest(const char* test_name, Test test){
    std::cout << "▶️  Running " << test_name << "..." << std::endl;
    test();
    std::cout << "✅ " << test_name << " Passed" << std::endl;
}

void runTests(){
    runTest("Vector2 Tests", vectorTests);
}
