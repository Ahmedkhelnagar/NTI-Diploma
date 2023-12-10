################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
SPI_UART_MC2_task.lss \

FLASH_IMAGE += \
SPI_UART_MC2_task.hex \

EEPROM_IMAGE += \
SPI_UART_MC2_task.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: SPI_UART_MC2_task.elf secondary-outputs

# Tool invocations
SPI_UART_MC2_task.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SPI_UART_MC2_task.map -mmcu=atmega32 -o "SPI_UART_MC2_task.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SPI_UART_MC2_task.lss: SPI_UART_MC2_task.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SPI_UART_MC2_task.elf  >"SPI_UART_MC2_task.lss"
	@echo 'Finished building: $@'
	@echo ' '

SPI_UART_MC2_task.hex: SPI_UART_MC2_task.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SPI_UART_MC2_task.elf  "SPI_UART_MC2_task.hex"
	@echo 'Finished building: $@'
	@echo ' '

SPI_UART_MC2_task.eep: SPI_UART_MC2_task.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex SPI_UART_MC2_task.elf  "SPI_UART_MC2_task.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SPI_UART_MC2_task.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SPI_UART_MC2_task.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SPI_UART_MC2_task.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
