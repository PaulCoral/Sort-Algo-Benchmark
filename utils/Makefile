CC = gcc
CFLAGS += -g -pedantic -Wall
CFLAGS += -c

OUTPUTS = algo_dir_utils.o

.PHONY: clean new

all : $(OUTPUTS)

clean :
	rm -rf *.o 

new : clean all

algo_dir_utils.o: algo_dir_utils.c algo_dir_utils.h

rand_array.o: rand_array.c rand_array.h

algo_error.o: algo_error.c algo_error.h