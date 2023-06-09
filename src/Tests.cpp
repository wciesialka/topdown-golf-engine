/**
 * @file Tests.cpp
 * @brief This file is responsible for testing general program correctness.
 * 
 * @author Willow Ciesialka
 * @date 2023-06-04
*/

#include "Tests.hpp"
#include "GolfEngine/Geometry/Vector2.hpp"
#include "GolfEngine/Geometry/Shapes/Quadrilateral.hpp"
#include <iostream>
#include <cassert>

#define ABS(n) ((n < 0) ? (-n) : n )
#define MAX_CLOSENESS 0.01
#define IS_APPROXIMATELY(n, m) (ABS((n-m)) < MAX_CLOSENESS)

void vectorTests(){
    GolfEngine::Vector2 a = GolfEngine::Vector2::zero;
    GolfEngine::Vector2 b(2, 2);
    const GolfEngine::Vector2 &c = GolfEngine::Vector2::zero;
    GolfEngine::Vector2 d(1, 1);
    GolfEngine::Vector2 e(3, 4);
    GolfEngine::Vector2 f(4, 5);
    GolfEngine::Vector2 g(2, 0);
    GolfEngine::Vector2 h(1, 0);
    // Comparison
    assert(a != b); 
    assert(a == c);
    assert(&a != &c);
    assert(&c == &GolfEngine::Vector2::zero);
    // Arithmetic
    assert(a.distanceSqr(b) == 8.0);
    assert(b.distanceSqr(a) == 8.0);
    assert((d*2) == b);
    assert((2*d) == (d*2));
    assert((b*e) == 14.0);
    assert((b.magnitudeSqr()) == 8.0);
    assert((d+e) == f);
    assert((b-b) == a);
    assert(g.normalized() == h);
    assert((b/2) == d);
}

void quadTests(){
    GolfEngine::Quadrilateral quad(GolfEngine::Vector2(0, 0), GolfEngine::Vector2(1, 0), GolfEngine::Vector2(1, 1), GolfEngine::Vector2(0, 1));
    assert(IS_APPROXIMATELY(quad.getPerimeter(), 4.0));
    assert(IS_APPROXIMATELY(quad.getArea(), 1.0));
}

void runTest(const char* test_name, Test test){
    std::cout << "▶️  Running " << test_name << "..." << std::endl;
    test();
    std::cout << "✅ " << test_name << " Passed" << std::endl;
}

void runTests(){
    runTest("Vector2 Tests", vectorTests);
    runTest("Quad Tests", quadTests);
}
