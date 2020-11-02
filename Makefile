# This file is part of Sort-Algo-Benchmark.

# Sort-Algo-Benchmark is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# Sort-Algo-Benchmark is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# You should have received a copy of the GNU General Public License
# along with Sort-Algo-Benchmark.  If not, see <https://www.gnu.org/licenses/>.
 
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


OUTPUTS = sort_algo_benchmark
BIN_DIR = bin
OTHER_DIR = utils
ALGOS = my_algos
ARCHIVE = sort_algo_benchmark_bin_linux.tar.gz
.PHONY : clean new my_algos run create_bin


all : $(OTHER_DIR) $(ALGOS) $(OUTPUTS)

create_bin :
	mkdir -p $(BIN_DIR)
	$(eval BIN_DIR = $(shell realpath $(BIN_DIR)))

my_algos : create_bin
	BIN_DIR=$(shell realpath $(BIN_DIR)) CFLAGS='$(CFLAGS)' CC='$(CC)' $(MAKE) -C $@

utils: create_bin
	BIN_DIR=$(shell realpath $(BIN_DIR)) CFLAGS='$(CFLAGS)' CC='$(CC)' $(MAKE) -C $@

sort_algo_benchmark : utils main.o
	$(CC) $(LDFLAGS) $(wildcard $(shell realpath $(BIN_DIR)/*)) -o $@
	
main.o: main.c utils/algo_dir_utils.h algo_interface/algo_interface.h utils/algo_error.h utils/rand_array.h
	$(CC) $(CFLAGS) $< -o $(BIN_DIR)/$@

clean :
	rm -rf *.o $(OUTPUTS) $(BIN_DIR) $(ARCHIVE)
	$(MAKE) -C $(ALGOS) clean
	$(MAKE) -C $(OTHER_DIR) clean

debug : CFLAGS += -g
debug : new

new : clean all

run : all
	./sort_algo_benchmark

archive: new
	mkdir -p sort_algo_benchmark_bin_linux/my_algos/
	cp -r my_algos/lib/ sort_algo_benchmark_bin_linux/my_algos/
	cp sort_algo_benchmark sort_algo_benchmark_bin_linux/
	tar cvfz $(ARCHIVE) sort_algo_benchmark_bin_linux/
	rm -rf sort_algo_benchmark_bin_linux/

format :
	clang-format -i -style=file $(wildcard *.c) $(wildcard *.h)
	clang-format -i -style=file $(wildcard algo_interface/*.c) $(wildcard algo_interface/*.h)
	$(MAKE) -C $(ALGOS) format
	$(MAKE) -C $(OTHER_DIR) format