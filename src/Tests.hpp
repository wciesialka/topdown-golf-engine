/**
 * @file Tests.cpp
 * @brief This file is responsible for defining tests for testing general program correctness.
 * 
 * @author Willow Ciesialka
 * @date 2023-06-04
*/

#ifndef TESTS_H
#define TESTS_H

typedef void (*Test)();

/**
 * @brief Runs all applicable tests.
*/
void runTests();

/**
 * @brief Run a test and print it's success status.
 * 
 * @param[in] test_name Name of the test to run.
 * @param[in] test Function pointer to test to run. 
*/
void runTest(const char* test_name, Test test);

/**
 * @brief Tests for proving vector correctness.
*/
void vectorTests();

#endif