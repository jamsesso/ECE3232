release:
	gcc -o main.out \
		main.c \
		riedd_module/riedd.c \
		riedd_module/kernel_layer/detector.c \
		riedd_module/kernel_layer/driver.c \
		riedd_module/kernel_layer/speed_switch_driver_controller.c \
		riedd_module/kernel_layer/idle.c \
		riedd_module/kernel_layer/led.c \
		riedd_module/kernel_layer/hardware_abstraction_layer/adc.c \
		riedd_module/kernel_layer/hardware_abstraction_layer/dac.c \
		riedd_module/kernel_layer/hardware_abstraction_layer/gpio.c \
		riedd_module/kernel_layer/hardware_abstraction_layer/rgb_led.c

debug:
	gcc -g -Wall -Werror -DBOARDLESS -o main.out \
		main.c \
		riedd_module/riedd.c \
		riedd_module/kernel_layer/detector.c \
		riedd_module/kernel_layer/driver.c \
		riedd_module/kernel_layer/speed_switch_driver_controller.c \
		riedd_module/kernel_layer/idle.c \
		riedd_module/kernel_layer/led.c \
		riedd_module/kernel_layer/hardware_abstraction_layer/boardless_simulation.c \
		riedd_module/kernel_layer/hardware_abstraction_layer/boardless_adc.c \
		riedd_module/kernel_layer/hardware_abstraction_layer/boardless_dac.c \
		riedd_module/kernel_layer/hardware_abstraction_layer/boardless_gpio.c \
		riedd_module/kernel_layer/hardware_abstraction_layer/boardless_rgb_led.c
