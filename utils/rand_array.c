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

#include <bits/types/__FILE.h>
#include <stdio.h>
#include <stdlib.h>

#include "algo_error.h"
#include "rand_array.h"

// ==================================================================

algo_error_t rand_array_init(const size_t size, rand_array_t *ra) {
  ra->size = size;
  if ((ra->arr = calloc(size, sizeof(int))) == NULL) {
    fprintf(stderr, "Error : Can't allocate memory for random array\nIn %s at line %d", __FILE__, __LINE__);
    return MEM_ERR;
  }
  for (size_t i = 0; i < size; i++) {
    ra->arr[i] = rand() % 100;
  }

  return SUCCESS;
}

// ==================================================================

void rand_array_free(rand_array_t *ra) {
  free(ra->arr);
  ra->size = 0;
  ra->arr = NULL;
}

// ==================================================================

int rand_array_is_sorted(const rand_array_t ra) {
  int is_sorted = ra.arr != NULL;
  for (size_t i = 1; i < ra.size; i++) {
    is_sorted &= ra.arr[i - 1] <= ra.arr[i];
  }

  return is_sorted;
}

// ==================================================================

void rand_array_print(const rand_array_t ra) {
  if (ra.arr == NULL) {
    puts("<NULL>\n\n");
    return;
  }

  printf("Printing a rand_array_t of size %zu : \n", ra.size);
  rand_array_print_is_sorted(ra);
  printf("\t|");
  for (size_t i = 0; i < ra.size; i++) {
    printf(" %d ", ra.arr[i]);
    putchar('|');
  }
  puts("\n");
}

// ==================================================================

void rand_array_print_is_sorted(const rand_array_t ra){
  if (rand_array_is_sorted(ra)) {
    puts("The array is sorted");
  } else {
    puts("The array is NOT sorted");
  }
}
