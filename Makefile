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
CFLAGS += -O3 -pedantic -Wall -Iutils
LDFLAGS += -ldl -Wl,-rpath=./my_algos/lib

OUTPUTS = sort_algo_workbench
ALGOS = my_algos
.PHONY : clean new my_algos run


all :  $(OUTPUTS) $(ALGOS)

my_algos :
	$(MAKE) -C $@

sort_algo_workbench : main.o utils/algo_dir_utils.o utils/rand_array.o utils/algo_error.o
	$(CC) $(CFLAGS) $(LDFLAGS) $? -o $@

main.o: main.c utils/algo_dir_utils.h algo_interface/algo_interface.h utils/algo_error.h utils/rand_array.h

clean :
	rm -rf *.o $(OUTPUTS)
	$(MAKE) -C utils clean
	$(MAKE) -C my_algos clean

new : clean all

run : all
	./sort_algo