release:
	gcc -o main.out \
		main.c \
		riedd_module/riedd.c \
		riedd_module/kernel_layer/detector.c \
		riedd_module/kernel_layer/driver.c \
		riedd_module/kernel_layer/idle.c \
		riedd_module/kernel_layer/hardware_abstraction_layer/adc.c \
		riedd_module/kernel_layer/hardware_abstraction_layer/dac.c \
		riedd_module/kernel_layer/hardware_abstraction_layer/gpio.c \
		riedd_module/kernel_layer/hardware_abstraction_layer/led.c

debug:
	gcc -g -Wall -Werror -DBOARDLESS -o main.out \
		main.c \
		riedd_module/riedd.c \
		riedd_module/boardless_simulation.c \
		riedd_module/kernel_layer/detector.c \
		riedd_module/kernel_layer/driver.c \
		riedd_module/kernel_layer/idle.c \
		riedd_module/kernel_layer/hardware_abstraction_layer/boardless_adc.c \
		riedd_module/kernel_layer/hardware_abstraction_layer/boardless_dac.c \
		riedd_module/kernel_layer/hardware_abstraction_layer/boardless_gpio.c \
		riedd_module/kernel_layer/hardware_abstraction_layer/boardless_led.c
