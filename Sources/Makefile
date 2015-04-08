BOARD_TYPES := boardless k22f

CC := gcc
LFLAGS := -L./riedd_module -L./riedd_module/kernel_layer -L./riedd_module/kernel_layer/hardware_abstraction_layer

clean:
	$(MAKE) -C riedd_module clean
	rm main.out

$(BOARD_TYPES):
	$(MAKE) -C riedd_module $@
	$(CC) -g -static -Wall -Werror -o main.out *.c $(LFLAGS) -lriedd -lkernel -lhal
