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
 * @file algo_dir_utils.c
 * @author Paul Coral
 * @brief Some utils function, give algorithm function to the main program
 * @date 2020-11-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#pragma once
#include "../algo_interface/algo_interface.h"
#include "algo_error.h"

/**
 * @brief display the list of available algorithms
 *
 */
void list_algos(void);

/**
 * @brief return the sort function, or NULL in case of issue
 *
 * @param index index of the sort function
 * @param ai pointer to the func
 * @return an error code
 */
algo_error_t select_algo(const unsigned index, algo_interface_t *ai);

/**
 * @brief free the handle to shared library
 *
 */
void free_algo_lib(void);
