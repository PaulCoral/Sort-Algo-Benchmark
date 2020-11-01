/**
 * @file main.c
 * @author Paul Coral
 * @brief A simple program to test speed of sorting algorithm
 * @date 2020-11-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "algo_interface/algo_interface.h"
#include "utils/algo_dir_utils.h"
#include "utils/algo_error.h"
#include "utils/rand_array.h"

// ==================================================================

#define OPTION_LIST "-l"
#define OPTION_SHOW_AFTER "-sa"
#define OPTION_SHOW_BEFORE "-sb"
#define SUCCESS_EXIT_MESSAGE "\nFINISHED, bye ;)\n"

typedef struct {
  char list;
  char show_before;
  char show_after;
  size_t array_size;
} algo_args_t;

algo_error_t parse_input(const int argc, char **argv, algo_interface_t *inter, algo_args_t *options);
void list_algos(void);

// ==================================================================

#define PRINT_RA(A, O, BA)                                                                                             \
  do {                                                                                                                 \
    if (O.BA) {                                                                                                        \
      rand_array_print(A);                                                                                             \
    }                                                                                                                  \
  } while (0)
#define PRINT_BEFORE(A, O) PRINT_RA(A, O, show_before)
#define PRINT_AFTER(A, O) PRINT_RA(A, O, show_after)

// ---------------------------------------

int main(int argc, char **argv) {
  algo_error_t error = SUCCESS;

  algo_interface_t algo_to_use = NULL;
  algo_args_t options;
  if ((error = parse_input(argc, argv, &algo_to_use, &options)) != SUCCESS) {
    algo_error_print(stderr, error, NULL);
    return EXIT_FAILURE;
  }
  if (algo_to_use == NULL) {
    return EXIT_SUCCESS;
  }

  // get random int array
  rand_array_t array;
  if ((error = rand_array_init(options.array_size, &array)) != SUCCESS) {
    algo_error_print(stderr, error, NULL);
    return EXIT_FAILURE;
  }

  printf("Starting sort...");
  PRINT_BEFORE(array, options);
  clock_t t1;
  clock_t t2;
  t1 = clock();
  algo_to_use(array);
  t2 = clock();
  PRINT_AFTER(array, options);
  puts("Sorting finished :)\n");

  rand_array_print_is_sorted(array);
  const double time_elapsed = ((double)(t2 - t1)) / CLOCKS_PER_SEC;
  printf("\n\nSorting performed in %.3lf sec.\n\n", time_elapsed);

  rand_array_free(&array);

  puts(SUCCESS_EXIT_MESSAGE);
  return EXIT_SUCCESS;
}

// ==================================================================

#define COMP_ARGS(X, Y) (strcmp(argv[(X)], (Y)) == 0)

/**
 * @brief Parse the input arguments, give pointer to sorting function and fill options struct
 *
 * @param argc The number of arguement, the argc of main
 * @param argv The list of arguement, the argv of main
 * @param inter The function pointer to sorting function, interface between shared library and the program
 * @param options A pointer to struct options, which will be initialized and filled by this function
 * @return algo_error_t An error code
 */
algo_error_t parse_input(const int argc, char **argv, algo_interface_t *inter, algo_args_t *options) {
  if (argv == NULL || options == NULL) {
    return INV_ARG;
  }

  // when `-l` argument is given
  if ((argc == 2) && (strcmp(OPTION_LIST, argv[1])) == 0) {
    list_algos();
    options->list = 1;
    return SUCCESS;
  }

  if (argc < 3) {
    printf("Usage : %s <algorithm index> <size of array (non-zero)> [OPTIONS...] \n", argv[0]);
    printf("Usage : %s %s to show list of available algorithm \n", argv[0], OPTION_LIST);
    printf("OPTION : %s to show list after sort\n", OPTION_SHOW_AFTER);
    printf("OPTION : %s to show list before sort\n", OPTION_SHOW_BEFORE);
    return SUCCESS;
  }

  memset(options, 0, sizeof(algo_args_t));

  const size_t index = atol(argv[1]);
  if ((options->array_size = atol(argv[2])) == 0) {
    fprintf(stderr, "Error array size can't be zero");
    return INV_ARG;
  }

  for (size_t i = 3; i < (argc - 1); i++) {
    if (COMP_ARGS(i, OPTION_SHOW_AFTER)) {
      options->show_after = 1;
    } else if (COMP_ARGS(i, OPTION_SHOW_BEFORE)) {
      options->show_before = 1;
    } else {
      printf("Warning : unrecognized options : %s\n", argv[i]);
    }
  }

  return select_algo(index, inter);
}