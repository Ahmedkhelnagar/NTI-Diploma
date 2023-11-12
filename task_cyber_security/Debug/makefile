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
task_cyber_security.lss \

FLASH_IMAGE += \
task_cyber_security.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: task_cyber_security.elf secondary-outputs

# Tool invocations
task_cyber_security.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,task_cyber_security.map -mmcu=atmega32 -o "task_cyber_security.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

task_cyber_security.lss: task_cyber_security.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S task_cyber_security.elf  >"task_cyber_security.lss"
	@echo 'Finished building: $@'
	@echo ' '

task_cyber_security.hex: task_cyber_security.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex task_cyber_security.elf  "task_cyber_security.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: task_cyber_security.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 task_cyber_security.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) task_cyber_security.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
