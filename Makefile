# This file is part of Sort-Algo-Workbench.

# Sort-Algo-Workbench is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# Sort-Algo-Workbench is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# You should have received a copy of the GNU General Public License
# along with Sort-Algo-Workbench.  If not, see <https://www.gnu.org/licenses/>.
 
# ============================================================================

#  @file main.c
#  @author Paul Coral
#  @brief main Makefile
#  @date 2020-11-01
#  
#  @copyright Copyright (c) 2020


CC = gcc
CFLAGS += -O3 -pedantic -Wall -c
LDFLAGS += -ldl -Wl,-rpath=./my_algos/lib


OUTPUTS = sort_algo_workbench
BIN_DIR = bin
OTHER_DIR = utils
ALGOS = my_algos
.PHONY : clean new my_algos run create_bin


all : $(OTHER_DIR) $(ALGOS) $(OUTPUTS)

create_bin :
	mkdir -p $(BIN_DIR)
	$(eval BIN_DIR = $(shell realpath $(BIN_DIR)))

my_algos : create_bin
	BIN_DIR=$(shell realpath $(BIN_DIR)) CFLAGS='$(CFLAGS)' CC='$(CC)' $(MAKE) -C $@

utils: create_bin
	BIN_DIR=$(shell realpath $(BIN_DIR)) CFLAGS='$(CFLAGS)' CC='$(CC)' $(MAKE) -C $@

sort_algo_workbench : utils main.o
	$(CC) $(LDFLAGS) $(wildcard $(shell realpath $(BIN_DIR)/*)) -o $@
	
main.o: main.c utils/algo_dir_utils.h algo_interface/algo_interface.h utils/algo_error.h utils/rand_array.h
	$(CC) $(CFLAGS) $< -o $(BIN_DIR)/$@

clean :
	rm -rf *.o $(OUTPUTS) $(BIN_DIR)
	$(MAKE) -C utils clean
	$(MAKE) -C my_algos clean

debug : CFLAGS += -g
debug : new

new : clean all

run : all
	./sort_algo_workbench

archive: new
	mkdir -p sort_algo_workbench_bin/my_algos/
	cp -r my_algos/lib/ sort_algo_workbench_bin/my_algos/
	cp sort_algo_workbench sort_algo_workbench_bin/
	tar cvfz sort_algo_workbench_bin.tar.gz sort_algo_workbench_bin/
	rm -rf sort_algo_workbench_bin/
