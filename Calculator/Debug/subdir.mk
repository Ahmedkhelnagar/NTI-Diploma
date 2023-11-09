################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Cal_Prog.c \
../DIO.c \
../DIO_Cfg.c \
../LCD.c \
../keypad.c \
../main.c 

OBJS += \
./Cal_Prog.o \
./DIO.o \
./DIO_Cfg.o \
./LCD.o \
./keypad.o \
./main.o 

C_DEPS += \
./Cal_Prog.d \
./DIO.d \
./DIO_Cfg.d \
./LCD.d \
./keypad.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


