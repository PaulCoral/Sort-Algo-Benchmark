.PHONY : clean new

CC = gcc
CFLAGS = -g -pedantic -Wall -Iutils

OUTPUTS = sort_algo


all :  $(OUTPUTS)

#make_sub :
#	$(MAKE) -C utils

sort_algo : main.o utils/algo_dir_utils.o
	$(CC) $(CFLAGS) $? -o $@
	
main.o : main.c utils/algo_dir_utils.h

clean :
	rm -rf *.o $(OUTPUTS)
	$(MAKE) -C utils clean

new : clean all