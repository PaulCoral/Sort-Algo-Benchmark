#include <dirent.h>
#include <stdio.h>

#include "algo_dir_utils.h"

#define ALGO_DIR "my_algos/"

void list_algos(void){
    puts("The available algorithms are");
    DIR * dir = opendir(ALGO_DIR);

    size_t i = 0;
    struct dirent * entry;
    while((entry = readdir(dir)) != NULL){
        printf("%zu) : %s", i, entry->d_name);
        i++;
    }

    if(i == 0){
        puts("<None>");
        printf("Add some algo to the %s directory !", ALGO_DIR);
    }
    putchar('\n');
}