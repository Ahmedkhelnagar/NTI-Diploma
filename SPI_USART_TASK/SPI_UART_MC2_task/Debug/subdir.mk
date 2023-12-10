################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO.c \
../DIO_Cfg.c \
../Global_Interr.c \
../LCD.c \
../Mc2.c \
../SPI_Prog.c \
../UART_PROG.c \
../keypad.c 

OBJS += \
./DIO.o \
./DIO_Cfg.o \
./Global_Interr.o \
./LCD.o \
./Mc2.o \
./SPI_Prog.o \
./UART_PROG.o \
./keypad.o 

C_DEPS += \
./DIO.d \
./DIO_Cfg.d \
./Global_Interr.d \
./LCD.d \
./Mc2.d \
./SPI_Prog.d \
./UART_PROG.d \
./keypad.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


