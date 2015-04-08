CC = gcc
CCFLAGS = -I../include \
			-I../../../../../SDK/platform/CMSIS/Include \
			-I../../../../../SDK/platform/CMSIS/Include/device \
			-I../../../../../SDK/platform/CMSIS/Include/device/MK22F51212

libhal.so:
	$(CC) -DCPU_MK22FN512VDC12 -Wall -Werror -shared -o $@ -fPIC *.c $(CCFLAGS)
