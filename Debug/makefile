################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/MTIMER1/subdir.mk
-include MCAL/MGIE/subdir.mk
-include MCAL/MEXTI/subdir.mk
-include MCAL/MDIO/subdir.mk
-include HAL/HCLCD/subdir.mk
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
DIGITAL_WATCH.lss \

FLASH_IMAGE += \
DIGITAL_WATCH.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: DIGITAL_WATCH.elf secondary-outputs

# Tool invocations
DIGITAL_WATCH.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,DIGITAL_WATCH.map -mmcu=atmega32 -o "DIGITAL_WATCH.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

DIGITAL_WATCH.lss: DIGITAL_WATCH.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S DIGITAL_WATCH.elf  >"DIGITAL_WATCH.lss"
	@echo 'Finished building: $@'
	@echo ' '

DIGITAL_WATCH.hex: DIGITAL_WATCH.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex DIGITAL_WATCH.elf  "DIGITAL_WATCH.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: DIGITAL_WATCH.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 DIGITAL_WATCH.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) DIGITAL_WATCH.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
