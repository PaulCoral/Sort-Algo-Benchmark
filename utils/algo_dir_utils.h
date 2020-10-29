#pragma once
#include "../algo_interface/algo_interface.h"

/**
 * @brief display the list of available algorithms
 *
 */
void list_algos(void);

/**
 * @brief return the sort function, or NULL in case of issue
 *
 * @param index index of the sort function
 * @return algo_interface_t the sort function, NULL in case of issue
 */
algo_interface_t select_algo(const unsigned index);