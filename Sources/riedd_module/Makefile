BOARD_TYPES := boardless k22f
SRC_FILES := $(wildcard *.c)

CC := gcc
CCFLAGS = -g -Wall -Werror -I./kernel_layer
LFLAGS := -L./kernel_layer

clean:
	$(MAKE) -C kernel_layer clean
	rm obj/*
	rm libriedd.a

$(BOARD_TYPES):
	$(MAKE) -C kernel_layer $@
	ar -x kernel_layer/libkernel.a
	mv *.o obj
	$(CC) $(if $(subst boardless,,$@),,-DBOARDLESS) $(CCFLAGS) -c -o riedd.o riedd.c
	ar rcs libriedd.a obj/*.o
