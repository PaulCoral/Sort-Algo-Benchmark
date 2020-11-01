CC = gcc
CFLAGS += -g -pedantic -Wall -Iutils
LDFLAGS += -ldl -Wl,-rpath=./my_algos/lib

OUTPUTS = sort_algo_workbench
ALGOS = my_algos
.PHONY : clean new my_algos run


all :  $(OUTPUTS) $(ALGOS)

my_algos :
	$(MAKE) -C my_algos

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