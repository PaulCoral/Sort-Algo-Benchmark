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

    fprintf(out, "%s%s%s",title, msg, other);
}