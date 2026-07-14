################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include generate/src/subdir.mk
-include board/subdir.mk
-include RTD/src/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_SIZE += \
VCU_Pedals_S32K312MINI_EVB.siz \


# All Target
all: VCU_Pedals_S32K312MINI_EVB.elf secondary-outputs

# Tool invocations
VCU_Pedals_S32K312MINI_EVB.elf: $(OBJS) C:/NXP/Workplace/VCU_Pedals_S32K312MINI_EVB/Project_Settings/Linker_Files/linker_ram_s32k312.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "VCU_Pedals_S32K312MINI_EVB.elf" "@VCU_Pedals_S32K312MINI_EVB.args"  $(USER_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

VCU_Pedals_S32K312MINI_EVB.siz: VCU_Pedals_S32K312MINI_EVB.elf
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley VCU_Pedals_S32K312MINI_EVB.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
