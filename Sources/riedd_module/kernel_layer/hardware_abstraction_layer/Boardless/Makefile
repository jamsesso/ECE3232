SRC_FILES := $(wildcard *.c)
OBJ_FILES := $(addprefix ../obj/, $(notdir $(SRC_FILES:.c=.o)))

CC = gcc
CCFLAGS = -g -Wall -Werror -I../include


libhal.a: $(OBJ_FILES)
	ar rcs $@ $(OBJ_FILES)

../obj/%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<
