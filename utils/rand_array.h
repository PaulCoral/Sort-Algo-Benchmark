#include "../algo_interface/algo_interface.h"
#include <stdlib.h>



/**
 * @brief create an array of random int
 * 
 * @param size the size of the array
 * @return int* the produced array
 */
rand_array_t init_rand_array(size_t size);

/**
 * @brief free the given rand_array
 * 
 * @param ptr 
 */
void free_rand_array(rand_array_t ra);