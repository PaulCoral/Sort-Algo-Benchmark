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
 * @brief the interface used by algorithms. THE FUNCTION SHOULD BE CALLED `algo_sort_func`
 *
 */
typedef rand_array_t (*algo_interface_t)(rand_array_t);
