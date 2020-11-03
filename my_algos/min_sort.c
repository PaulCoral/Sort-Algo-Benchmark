/*
 *   This file is part of Sort-Algo-Benchmark.
 *
 *   Sort-Algo-Benchmark is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Sort-Algo-Benchmark is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Sort-Algo-Benchmark.  If not, see
 * <https://www.gnu.org/licenses/>.
 */

/**
 * @file min_sort.c
 * @author Paul Coral
 * @brief A simple sorting algorithm, as an example for the main program
 * @date 2020-11-01
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <stdio.h>
#include <assert.h>

#include "../algo_interface/algo_interface.h"

static void swap_int_ptr(int *a, int *b);
static int *index_of_min(int *arr, const size_t size);

void algo_sort_func(rand_array_t ra) {
  size_t size = ra.size;
  int *arr = ra.arr;

  if (arr == NULL) {
    fprintf(stderr, "Error : the given array is <NULL>. Aborting\n");
  }

  while (size > 1) {
    int *min_index = index_of_min(arr, size);
    swap_int_ptr(min_index, arr);

    --size;
    ++arr;
  }
}

static void swap_int_ptr(int *a, int *b) {
  assert(a != NULL && b != NULL);
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

static int *index_of_min(int *arr, const size_t size) {
  assert(arr != NULL);
  size_t min_index = 0;
  int min = arr[0];
  for (size_t i = 0; i < size; i++) {
    if (arr[i] < min) {
      min = arr[i];
      min_index = i;
    }
  }

  return ((int *)(arr + min_index));
}