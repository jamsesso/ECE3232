release:
	gcc -o main.out \
		main.c \
		riedd_module/riedd.c \
		riedd_module/detector_module/adc.c \
		riedd_module/detector_module/detector.c \
		riedd_module/driver_module/dac.c \
		riedd_module/driver_module/driver.c \
		riedd_module/idle_module/gpio.c \
		riedd_module/idle_module/idle.c \
		riedd_module/led_module/led.c

debug:
	gcc -g -w -DBOARDLESS -o main.out \
		main.c \
		riedd_module/riedd.c \
		riedd_module/boardless_simulation.c \
		riedd_module/detector_module/boardless_adc.c \
		riedd_module/detector_module/detector.c \
		riedd_module/driver_module/boardless_dac.c \
		riedd_module/driver_module/driver.c \
		riedd_module/idle_module/boardless_gpio.c \
		riedd_module/idle_module/idle.c \
		riedd_module/led_module/boardless_led.c
