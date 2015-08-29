################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Application.c \
../Sources/Events.c \
../Sources/LEDController.c \
../Sources/SDBuffer.c \
../Sources/TimeKeep.c \
../Sources/main.c 

OBJS += \
./Sources/Application.o \
./Sources/Events.o \
./Sources/LEDController.o \
./Sources/SDBuffer.o \
./Sources/TimeKeep.o \
./Sources/main.o 

C_DEPS += \
./Sources/Application.d \
./Sources/Events.d \
./Sources/LEDController.d \
./Sources/SDBuffer.d \
./Sources/TimeKeep.d \
./Sources/main.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:\Freescale\KDS_2.0.0\eclipse\ProcessorExpert/lib/Kinetis/pdd2/MK64FN1M0LL12/system" -I"C:\Freescale\KDS_2.0.0\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:\Freescale\KDS_2.0.0\eclipse\ProcessorExpert/lib/Kinetis/iofiles" -I"C:/Users/Kyle/bb_repos/ece_15_5_data_collection_firmware/LED Current/Sources" -I"C:/Users/Kyle/bb_repos/ece_15_5_data_collection_firmware/LED Current/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


