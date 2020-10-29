#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "algo_interface/algo_interface.h"
#include "utils/algo_dir_utils.h"

#define OPTION_LIST "-l"
#define FAILURE_EXIT_MESSAGE "\nBetter luck next time :(\n"
#define SUCCESS_EXIT_MESSAGE "\nFINISHED, bye ;)\n"

algo_interface_t parse_input(int argc, char **argv);
void list_algos(void);

int main(int argc, char **argv) {
  algo_interface_t algo_to_use = NULL;
  if ((algo_to_use = parse_input(argc, argv)) == NULL) {
    puts(FAILURE_EXIT_MESSAGE);
    return EXIT_FAILURE;
  }

  puts(SUCCESS_EXIT_MESSAGE);
  return EXIT_SUCCESS;
}

algo_interface_t parse_input(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage : %s <algorithm index> \nUse option -l to get a list of algo\n", argv[0]);
    return NULL;
  }

  if (strcmp(OPTION_LIST, argv[1]) == 0) {
    list_algos();
    return NULL;
  }

  select_algo(atoi(argv[1]));

  return select_algo(atoi(argv[1]));
}