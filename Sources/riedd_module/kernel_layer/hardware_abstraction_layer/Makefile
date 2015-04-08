LIBHALS := $(wildcard */libhal.a)

clean:
	rm $(LIBHALS)
	rm obj/*
	unlink libhal.a

boardless:
	$(MAKE) -C Boardless
	ln -sf Boardless/libhal.a libhal.a

k22f:
	$(MAKE) -C Boardless
	ln -sf Boardless/libhal.a libhal.a
	#$(MAKE) -C FRDM-K22F
	#ln -sf FRDM-K22F/libhal.a libhal.a
