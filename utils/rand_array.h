/*
 *   This file is part of Sort-Algo-Workbench.
 *
 *   Sort-Algo-Workbench is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Sort-Algo-Workbench is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Sort-Algo-Workbench.  If not, see <https://www.gnu.org/licenses/>.
 */


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
