#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "algo_interface/algo_interface.h"
#include "utils/algo_dir_utils.h"
#include "utils/algo_error.h"
#include "utils/rand_array.h"

// ==================================================================

#define DEFAULT_ARRAY_SIZE 5

#define OPTION_LIST "-l"
#define FAILURE_EXIT_MESSAGE "\nBetter luck next time :(\n"
#define SUCCESS_EXIT_MESSAGE "\nFINISHED, bye ;)\n"

algo_error_t parse_input(int argc, char **argv, algo_interface_t *inter);
void list_algos(void);

// ==================================================================

int main(int argc, char **argv) {
  algo_error_t error = SUCCESS;

  algo_interface_t algo_to_use = NULL;
  if ((error = parse_input(argc, argv, &algo_to_use)) != SUCCESS) {
    algo_error_print(stderr, error, NULL);
    return EXIT_FAILURE;
  }
  if (algo_to_use == NULL) {
    return EXIT_SUCCESS;
  }

  // get random int array
  rand_array_t array;
  if((error = rand_array_init(DEFAULT_ARRAY_SIZE, &array)) != SUCCESS){
    algo_error_print(stderr, error, NULL);
    return EXIT_FAILURE;
  }

  rand_array_print(array);
  fflush(stdout);
  

  algo_to_use(array);

  rand_array_free(&array);

  puts(SUCCESS_EXIT_MESSAGE);
  return EXIT_SUCCESS;
}

// ==================================================================

algo_error_t parse_input(int argc, char **argv, algo_interface_t *inter) {
  if (argc != 2) {
    printf("Usage : %s <algorithm index> \nUse option -l to get a list of algo\n", argv[0]);
    return INV_ARG;
  }

  // when `-l` argument is given
  if (strcmp(OPTION_LIST, argv[1]) == 0) {
    list_algos();
    return SUCCESS;
  }
  
  return select_algo(atoi(argv[1]), inter);
}