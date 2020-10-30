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
 * `algo_sort_func`.
 *
 */
typedef void (*algo_interface_t)(rand_array_t);

/**
 * @brief the function that will be called by  `sort-algo`. Used
 * by algorithm programmer
 *
 */
void algo_sort_func(rand_array_t);