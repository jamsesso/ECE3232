BOARD_TYPES := boardless k22f
SRC_FILES := $(wildcard *.c)
OBJ_FILES := $(addprefix obj/, $(notdir $(SRC_FILES:.c=.o)))

CC := gcc
CCFLAGS = -g -Wall -Werror -Ihardware_abstraction_layer/include
LFLAGS := -L./hardware_abstraction_layer

clean:
	$(MAKE) -C hardware_abstraction_layer clean
	rm obj/*
	rm libkernel.a

$(BOARD_TYPES): $(OBJ_FILES)
	$(MAKE) -C hardware_abstraction_layer $@
	ar -x hardware_abstraction_layer/libhal.a
	mv *.o obj
	ar rcs libkernel.a obj/*.o

obj/%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<
