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