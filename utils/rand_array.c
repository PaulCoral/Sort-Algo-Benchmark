#include "rand_array.h"
#include <bits/types/__FILE.h>
#include <stdio.h>
#include <stdlib.h>

// ==================================================================

rand_array_t init_rand_array(const size_t size) {
  rand_array_t ra;
  ra.size = size;
  if ((ra.arr = calloc(size, sizeof(int))) == NULL) {
    fprintf(stderr, "Error : Can't allocate memory for random array\nIn %s at line %d", __FILE__, __LINE__);
    exit(-1);
  }
  for (size_t i = 0; i < size; i++) {
    ra.arr[i] = rand();
  }

  return ra;
}

// ==================================================================

void free_rand_array(rand_array_t ra) {
  free(ra.arr);
  ra.size = 0;
  ra.arr = NULL;
}