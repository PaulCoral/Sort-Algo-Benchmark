/**
 * @file rand_array.c
 * @author Paul Coral 
 * @brief Create, free and print states of random array
 * @date 2020-11-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#pragma once

#include "../algo_interface/algo_interface.h"
#include "algo_error.h"
#include <stdlib.h>

/**
 * @brief create an array of random int
 *
 * @param size the size of the array
 * @param ra pointer to array to initialize
 * @return An error code
 */
algo_error_t rand_array_init(const size_t size, rand_array_t* ra);

/**
 * @brief free the given rand_array
 *
 * @param ptr
 */
void rand_array_free(rand_array_t *ra);

/**
 * @brief Check if the given `rand_array_t` is sorted
 *
 * @param ra the array to check
 * @return int non-zero if sorted, 0 otherwise
 */
int rand_array_is_sorted(const rand_array_t ra);

/**
 * @brief Print the given rand_array_t (size and elements)
 *
 * @param ra the array to print
 */
void rand_array_print(const rand_array_t ra);

/**
 * @brief Print a message, if the array is sorted or not
 * 
 * @param ra the array to tell if sorted or not
 */
void rand_array_print_is_sorted(const rand_array_t ra);
