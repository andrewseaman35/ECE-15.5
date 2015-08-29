################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Freescale/KDS_2.0.0/eclipse/ProcessorExpert/lib/Kinetis/pdd2/MK64FN1M0LL12/system/CPU_Init.c \
C:/Freescale/KDS_2.0.0/eclipse/ProcessorExpert/lib/Kinetis/pdd2/MK64FN1M0LL12/system/Peripherals_Init.c \
C:/Freescale/KDS_2.0.0/eclipse/ProcessorExpert/lib/Kinetis/pdd2/MK64FN1M0LL12/system/Vectors.c 

OBJS += \
./Generated_Code/System/CPU_Init.o \
./Generated_Code/System/Peripherals_Init.o \
./Generated_Code/System/Vectors.o 

C_DEPS += \
./Generated_Code/System/CPU_Init.d \
./Generated_Code/System/Peripherals_Init.d \
./Generated_Code/System/Vectors.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/System/CPU_Init.o: C:/Freescale/KDS_2.0.0/eclipse/ProcessorExpert/lib/Kinetis/pdd2/MK64FN1M0LL12/system/CPU_Init.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:\Freescale\KDS_2.0.0\eclipse\ProcessorExpert/lib/Kinetis/pdd2/MK64FN1M0LL12/system" -I"C:\Freescale\KDS_2.0.0\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:\Freescale\KDS_2.0.0\eclipse\ProcessorExpert/lib/Kinetis/iofiles" -I"C:/Users/Kyle/bb_repos/ece_15_5_data_collection_firmware/LED Current/Sources" -I"C:/Users/Kyle/bb_repos/ece_15_5_data_collection_firmware/LED Current/Generated_Code" -std=c99 -MMD -MP -MF"Generated_Code/System/CPU_Init.d" -MT"Generated_Code/System/CPU_Init.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/System/Peripherals_Init.o: C:/Freescale/KDS_2.0.0/eclipse/ProcessorExpert/lib/Kinetis/pdd2/MK64FN1M0LL12/system/Peripherals_Init.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:\Freescale\KDS_2.0.0\eclipse\ProcessorExpert/lib/Kinetis/pdd2/MK64FN1M0LL12/system" -I"C:\Freescale\KDS_2.0.0\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:\Freescale\KDS_2.0.0\eclipse\ProcessorExpert/lib/Kinetis/iofiles" -I"C:/Users/Kyle/bb_repos/ece_15_5_data_collection_firmware/LED Current/Sources" -I"C:/Users/Kyle/bb_repos/ece_15_5_data_collection_firmware/LED Current/Generated_Code" -std=c99 -MMD -MP -MF"Generated_Code/System/Peripherals_Init.d" -MT"Generated_Code/System/Peripherals_Init.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/System/Vectors.o: C:/Freescale/KDS_2.0.0/eclipse/ProcessorExpert/lib/Kinetis/pdd2/MK64FN1M0LL12/system/Vectors.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:\Freescale\KDS_2.0.0\eclipse\ProcessorExpert/lib/Kinetis/pdd2/MK64FN1M0LL12/system" -I"C:\Freescale\KDS_2.0.0\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:\Freescale\KDS_2.0.0\eclipse\ProcessorExpert/lib/Kinetis/iofiles" -I"C:/Users/Kyle/bb_repos/ece_15_5_data_collection_firmware/LED Current/Sources" -I"C:/Users/Kyle/bb_repos/ece_15_5_data_collection_firmware/LED Current/Generated_Code" -std=c99 -MMD -MP -MF"Generated_Code/System/Vectors.d" -MT"Generated_Code/System/Vectors.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


