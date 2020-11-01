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