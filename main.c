#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils/algo_dir_utils.h"

#define OPTION_LIST "-l"

int * parse_input(int argc, char** argv);
void list_algos(void);

int main(int argc, char** argv){
    parse_input(argc, argv);
    return EXIT_SUCCESS;
}

int * parse_input(int argc, char** argv){
    if(argc < 2){
        fprintf(stderr, "Usage : %s <algorithm index> \nUse option -l to get a list of algo\n", argv[0]);
        exit(-1);
    }

    if(strcmp(OPTION_LIST, argv[1]) == 0){
        list_algos();
        return NULL;
    }

    return NULL;
}