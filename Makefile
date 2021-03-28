MCU   	   = atmega328p
CLOCK 	   = 1000000
COMPILE    = avr-gcc -Wall -Os -mmcu=$(MCU) -DF_CPU=$(CLOCK)

build:
	$(COMPILE) -c main.c -o main.o
	$(COMPILE) -c libs/sn74hc165.c -o sn74hc165.o
	$(COMPILE) -c libs/shift_util.c -o shift_util.o
	$(COMPILE) -c libs/i2c_slave.c -o i2c_slave.o

	$(COMPILE) -o main.elf main.o sn74hc165.o shift_util.o i2c_slave.o

	avr-objcopy -j .text -j .data -O ihex main.elf main.hex
	avr-size --format=avr --mcu=$(MCU) main.elf

	del /f main.o
	del /f sn74hc165.o
	del /f shift_util.o
	del /f i2c_slave.o
	del /f main.elf