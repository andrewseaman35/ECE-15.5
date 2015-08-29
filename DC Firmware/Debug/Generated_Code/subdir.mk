################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/CD1.c \
../Generated_Code/CI2C1.c \
../Generated_Code/CS1.c \
../Generated_Code/Cpu.c \
../Generated_Code/EInt1.c \
../Generated_Code/EInt2.c \
../Generated_Code/FAT1.c \
../Generated_Code/FX1.c \
../Generated_Code/GI2C1.c \
../Generated_Code/LED_B.c \
../Generated_Code/LED_G.c \
../Generated_Code/LED_R.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/SD1.c \
../Generated_Code/SM1.c \
../Generated_Code/SS1.c \
../Generated_Code/TI1.c \
../Generated_Code/TI2.c \
../Generated_Code/TMOUT1.c \
../Generated_Code/TU1.c \
../Generated_Code/TU2.c \
../Generated_Code/TimerIntLdd1.c \
../Generated_Code/TimerIntLdd2.c \
../Generated_Code/TmDt1.c \
../Generated_Code/UTIL1.c \
../Generated_Code/WAIT1.c \
../Generated_Code/ff.c 

OBJS += \
./Generated_Code/CD1.o \
./Generated_Code/CI2C1.o \
./Generated_Code/CS1.o \
./Generated_Code/Cpu.o \
./Generated_Code/EInt1.o \
./Generated_Code/EInt2.o \
./Generated_Code/FAT1.o \
./Generated_Code/FX1.o \
./Generated_Code/GI2C1.o \
./Generated_Code/LED_B.o \
./Generated_Code/LED_G.o \
./Generated_Code/LED_R.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/SD1.o \
./Generated_Code/SM1.o \
./Generated_Code/SS1.o \
./Generated_Code/TI1.o \
./Generated_Code/TI2.o \
./Generated_Code/TMOUT1.o \
./Generated_Code/TU1.o \
./Generated_Code/TU2.o \
./Generated_Code/TimerIntLdd1.o \
./Generated_Code/TimerIntLdd2.o \
./Generated_Code/TmDt1.o \
./Generated_Code/UTIL1.o \
./Generated_Code/WAIT1.o \
./Generated_Code/ff.o 

C_DEPS += \
./Generated_Code/CD1.d \
./Generated_Code/CI2C1.d \
./Generated_Code/CS1.d \
./Generated_Code/Cpu.d \
./Generated_Code/EInt1.d \
./Generated_Code/EInt2.d \
./Generated_Code/FAT1.d \
./Generated_Code/FX1.d \
./Generated_Code/GI2C1.d \
./Generated_Code/LED_B.d \
./Generated_Code/LED_G.d \
./Generated_Code/LED_R.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/SD1.d \
./Generated_Code/SM1.d \
./Generated_Code/SS1.d \
./Generated_Code/TI1.d \
./Generated_Code/TI2.d \
./Generated_Code/TMOUT1.d \
./Generated_Code/TU1.d \
./Generated_Code/TU2.d \
./Generated_Code/TimerIntLdd1.d \
./Generated_Code/TimerIntLdd2.d \
./Generated_Code/TmDt1.d \
./Generated_Code/UTIL1.d \
./Generated_Code/WAIT1.d \
./Generated_Code/ff.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:\Freescale\KDS_2.0.0\eclipse\ProcessorExpert/lib/Kinetis/pdd2/MK64FN1M0LL12/system" -I"C:\Freescale\KDS_2.0.0\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:\Freescale\KDS_2.0.0\eclipse\ProcessorExpert/lib/Kinetis/iofiles" -I"C:/Users/Kyle/bb_repos/ece_15_5_data_collection_firmware/LED Current/Sources" -I"C:/Users/Kyle/bb_repos/ece_15_5_data_collection_firmware/LED Current/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


