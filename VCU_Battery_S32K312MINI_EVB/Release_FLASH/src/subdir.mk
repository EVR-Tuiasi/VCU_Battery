################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/CanMessaging.c \
../src/Messaging.c \
../src/UartMessaging.c \
../src/main.c 

OBJS += \
./src/CanMessaging.o \
./src/Messaging.o \
./src/UartMessaging.o \
./src/main.o 

C_DEPS += \
./src/CanMessaging.d \
./src/Messaging.d \
./src/UartMessaging.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/CanMessaging.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


