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
 *   along with Sort-Algo-Benchmark.  If not, see <https://www.gnu.org/licenses/>.
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

#include "algo_error.h"
#include <stdio.h>
#include <string.h>

#define OTHER_SIZE 257
#define SEPARATOR " : "

void algo_error_print(FILE* out, algo_error_t err, const char* other){
    char* title = NULL;
    char* msg = NULL;
    char other_cat[OTHER_SIZE];
    switch (err) {
        case SUCCESS:
            title = "SUCCESS : ";
            msg = "Executed with success !";
            break;
        case INV_ARG:
            title = "ERROR : ";
            msg = "Invalid arguement to function";
            break;
        case MEM_ERR:
            title = "ERROR : ";
            msg = "Unable to locate memory";
            break;
        default:
            title = "ERROR? : ";
            msg = "Invalid error code !";
            break;
    }
    if(other == NULL || strnlen(other, OTHER_SIZE) == 0){
        other = "";
    }else{
        strcpy(other_cat, SEPARATOR);
        const size_t size_cat = OTHER_SIZE - strlen(SEPARATOR) - 1;
        strncat(other_cat, other, size_cat);
    }

    fprintf(out, "\n%s%s%s\n",title, msg, other);
}