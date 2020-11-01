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

####################################################
####             An Example Makefile            ####
####        Template to create your algo        ####
####################################################

.PHONY : clean

CC = gcc
CFLAGS += -g -Wall -fpic
LDFLAGS += -shared

OUTPUT = min_sort.so #replace with your output file
OUTPUT_DIR = lib

# CHANGE THE RULES

#new_algo : new_algo.o 

all : $(OUTPUT)

min_sort.so : min_sort.o
	$(CC) $(LDFLAGS) $? -o $(OUTPUT_DIR)/$@

min_sort.o : min_sort.c algo_interface.h
	$(CC) -c $(CFLAGS) $<

clean:
	rm -rf *.o
	$(foreach prog,$(OUTPUT), rm -rf $(OUTPUT_DIR)/$(OUTPUT))