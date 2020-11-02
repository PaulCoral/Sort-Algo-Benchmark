/*
 *   This file is part of Sort-Algo-Workbench.
 *
 *   Sort-Algo-Workbench is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Sort-Algo-Workbench is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Sort-Algo-Workbench.  If not, see
 * <https://www.gnu.org/licenses/>.
 */

/**
 * @file algo_dir_utils.c
 * @author Paul Coral
 * @brief Some utils function, give algorithm function to the main program
 * @date 2020-11-01
 *
 * @copyright Copyright (c) 2020
 *
 */

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

  // if handle not already taken
  if (handle == NULL) {
    handle = dlopen(name, RTLD_NOW);
    if (handle == NULL) {
      fprintf(stderr, "Error can't load algorithm : %s\n", dlerror());
      return ERR;
    }
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
    handle = NULL;
  }
}