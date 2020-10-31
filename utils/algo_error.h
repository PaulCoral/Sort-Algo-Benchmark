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