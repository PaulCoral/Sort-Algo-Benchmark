#include <dirent.h>
#include <dlfcn.h>
#include <stdio.h>
#include <string.h>

#include "algo_dir_utils.h"

#define ALGO_DIR "my_algos/"
#define CURRENT_DIR "."
#define PARENT_DIR ".."

void list_algos(void) {
  puts("The available algorithms are");
  DIR *dir = opendir(ALGO_DIR);
  if (dir == NULL) {
    fprintf(stderr, "Error : can't access directory.\n");
    return;
  }

  size_t i = 0;
  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    const char *const name = entry->d_name;
    if (strcmp(name, CURRENT_DIR) != 0 && strcmp(PARENT_DIR, name) != 0) {
      printf("%zu) : %s", i, entry->d_name);
      i++;
    }
  }

  closedir(dir);

  if (i == 0) {
    puts("<None>");
    printf("Add some algo to the %s directory !", ALGO_DIR);
  }
  putchar('\n');
}

algo_interface_t select_algo(const unsigned index) {
  DIR *dir = opendir(ALGO_DIR);

  if (dir == NULL) {
    fprintf(stderr, "Error : can't access directory.\n");
    return NULL;
  }

  size_t i = 0;
  struct dirent *entry;
  const char *name = NULL;
  while ((entry = readdir(dir)) != NULL && i < index) {
    name = entry->d_name;
    if (strcmp(name, CURRENT_DIR) != 0 && strcmp(PARENT_DIR, name) != 0) {
      i++;
    }
  }

  closedir(dir);

  if (i != index || name == NULL) {
    printf("Can't get algorithm at index %u\n", index);
    return NULL;
  }

  void *handle = NULL;
  algo_interface_t func = NULL;
  char *error = NULL;

  handle = dlopen(name, RTLD_NOW);
  if (handle == NULL) {
    fprintf(stderr, "Error can't load algorithm : %s\n", dlerror());
    return NULL;
  }

  dlerror(); /* Clear any error */

  // casting due to C99 standard, casting void* to func ptr undefined
  *(void **)(&func) = dlsym(handle, SORT_FUNC_NAME);

  if ((error = dlerror()) != NULL) {
    fprintf(stderr, "Can't load symbole %s() : %s\n", SORT_FUNC_NAME, error);
    exit(EXIT_FAILURE);
  }

  dlclose(handle);
  closedir(dir);

  return func;
}