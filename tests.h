#ifndef TESTS_H
#define TESTS_H

/** @file tests.h
 *  @brief Used to call Snake-test.h and check the results of the tests performed.
 *  @author Ahmed N.Adamjee
 *  @date 9th May 2019
 */
 
#include "Snake-test.h"

/**
 * @brief Run all the tests for this program
 * @returns The number of tests that failed
 */
int run_all_tests()
{
    int number_of_failed_tests = 0; // A log of the number of tests that have failed

    // Run the Snake_test_movement
    printf("Testing Snake_test_movement...\n");
    bool snake_movement_test_passed = Snake_test_movement();

    // Print out the result of this test
    if (snake_movement_test_passed) {
        printf("...Passed!, no worries the game is alright\n");
    } else {
        printf("...FAILED!\n");
        ++number_of_failed_tests; // Increment number of failures
    }


    // Finish by printing a summary of the tests
    if (number_of_failed_tests > 0) {
        printf("%d tests FAILED!\n", number_of_failed_tests);
    } else {
        printf("All tests passed!\n");
    }

    return number_of_failed_tests;
}

#endif