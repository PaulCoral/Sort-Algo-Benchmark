#include <dirent.h>
#include <dlfcn.h>
#include <stdio.h>
#include <string.h>

#include "../algo_interface/algo_interface.h"
#include "algo_dir_utils.h"
#include "algo_error.h"

#define ALGO_DIR "my_algos/lib"
#define CURRENT_DIR "."
#define PARENT_DIR ".."

static void *handle = NULL;

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

// ==================================================================

algo_error_t select_algo(const unsigned index, algo_interface_t *ai) {
  DIR *dir = opendir(ALGO_DIR);

  if (dir == NULL) {
    fprintf(stderr, "Error : can't access directory.\n");
    return ACCESS_ERR;
  }

  size_t i = 0;
  struct dirent *entry;
  char name[256];
  while ((entry = readdir(dir)) != NULL && i <= index) {
    strncpy(name, entry->d_name, 256);
    if (strcmp(name, CURRENT_DIR) != 0 && strcmp(PARENT_DIR, name) != 0) {
      i++;
    }
  }

  if (i <= index || strlen(name) == 0) {
    printf("Can't get algorithm at index %u\n", index);
    return INV_ARG;
  }

  char *error = NULL;

  handle = dlopen(name, RTLD_NOW);
  if (handle == NULL) {
    fprintf(stderr, "Error can't load algorithm : %s\n", dlerror());
    return ERR;
  }

  dlerror(); /* Clear any error */

  // casting due to C99 standard, casting void* to func ptr undefined
  *((void **)ai) = dlsym(handle, SORT_FUNC_NAME);

  if ((error = dlerror()) != NULL) {
    fprintf(stderr, "Can't load symbole %s() : %s\n", SORT_FUNC_NAME, error);
    return ERR;
  }

  closedir(dir);

  return SUCCESS;
}

// ==================================================================

void free_algo_lib(void) {
  if (handle != NULL) {
    dlclose(handle);
  }
}