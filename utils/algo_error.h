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
 * @file algo_error.c
 * @author Paul Coral 
 * @brief A few values and utils funciton to handle errors.
 * @date 2020-11-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */
 
#pragma once
#include <stdio.h>

typedef enum{
    INV_ARG,    // invalid arguement to func (or to program)
    MEM_ERR,
    ACCESS_ERR,
    ERR,
    SUCCESS     // No error, function executed with success
}algo_error_t;

void algo_error_print(FILE* out, algo_error_t err, const char* other);