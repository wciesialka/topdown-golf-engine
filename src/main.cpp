/**
 * @file main.cpp
 * @brief This file is responsible for putting it all together.
 * 
 * @author Willow Ciesialka
 * @date 2023-06-03
*/

#include "Tests.hpp"
#define RUN_TESTS

int main(){
    #ifdef RUN_TESTS
    runTests();
    #endif

    return 0;
}
