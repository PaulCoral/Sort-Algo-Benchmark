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


OUTPUTS = algo_dir_utils.o rand_array.o algo_error.o

.PHONY: clean new

all : $(OUTPUTS)

clean :
	rm -rf *.o 

new : clean all

algo_dir_utils.o: algo_dir_utils.c algo_dir_utils.h
	$(CC) $(CFLAGS) $< -o $(BIN_DIR)/$@

rand_array.o: rand_array.c rand_array.h
	$(CC) $(CFLAGS) $< -o $(BIN_DIR)/$@

algo_error.o: algo_error.c algo_error.h
	$(CC) $(CFLAGS) $< -o $(BIN_DIR)/$@