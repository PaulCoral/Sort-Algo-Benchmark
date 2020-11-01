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
 * @file algo_interface.h
 * @author Paul Coral
 * @brief An interface between the main program, and sorting algorithms
 * @date 2020-11-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#pragma once

#include <stdlib.h>

#define SORT_FUNC_NAME "algo_sort_func"

/**
 * @brief representation of an array of random int
 *
 */
typedef struct {
  size_t size;
  int *arr;
} rand_array_t;

/**
 * @brief the interface used by algorithms. THE FUNCTION SHOULD BE CALLED
 * `algo_sort_func`
 *
 */
typedef void (*algo_interface_t)(rand_array_t);

/**
 * @brief the function that will be called by  `sort-algo`
 *
 */
void algo_sort_func(rand_array_t);