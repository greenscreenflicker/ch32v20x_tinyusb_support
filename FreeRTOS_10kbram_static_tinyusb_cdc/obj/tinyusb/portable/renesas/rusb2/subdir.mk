################################################################################
# MRS Version: {"version":"1.8.5","date":"2023/05/22"}
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../tinyusb/portable/renesas/rusb2/dcd_rusb2.c \
../tinyusb/portable/renesas/rusb2/hcd_rusb2.c \
../tinyusb/portable/renesas/rusb2/rusb2_common.c 

OBJS += \
./tinyusb/portable/renesas/rusb2/dcd_rusb2.o \
./tinyusb/portable/renesas/rusb2/hcd_rusb2.o \
./tinyusb/portable/renesas/rusb2/rusb2_common.o 

C_DEPS += \
./tinyusb/portable/renesas/rusb2/dcd_rusb2.d \
./tinyusb/portable/renesas/rusb2/hcd_rusb2.d \
./tinyusb/portable/renesas/rusb2/rusb2_common.d 


# Each subdirectory must supply rules for building sources it contributes
tinyusb/portable/renesas/rusb2/%.o: ../tinyusb/portable/renesas/rusb2/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused  -g -I"C:\Users\mchhe\OneDrive\Dokumente\git\delete2\SRC\Debug" -I"C:\Users\mchhe\OneDrive\Dokumente\git\delete2\SRC\Core" -I"C:\Users\mchhe\OneDrive\Dokumente\git\delete2\ch32v203_freertos3\FreeRTOS_10kbram_static_usbdragon\User" -I"C:\Users\mchhe\OneDrive\Dokumente\git\delete2\SRC\Peripheral\inc" -I"C:\Users\mchhe\OneDrive\Dokumente\git\delete2\ch32v203_freertos3\FreeRTOS_10kbram_static_usbdragon\FreeRTOS" -I"C:\Users\mchhe\OneDrive\Dokumente\git\delete2\ch32v203_freertos3\FreeRTOS_10kbram_static_usbdragon\FreeRTOS\include" -I"C:\Users\mchhe\OneDrive\Dokumente\git\delete2\ch32v203_freertos3\FreeRTOS_10kbram_static_usbdragon\FreeRTOS\portable" -I"C:\Users\mchhe\OneDrive\Dokumente\git\delete2\ch32v203_freertos3\FreeRTOS_10kbram_static_usbdragon\FreeRTOS\portable\Common" -I"C:\Users\mchhe\OneDrive\Dokumente\git\delete2\ch32v203_freertos3\FreeRTOS_10kbram_static_usbdragon\FreeRTOS\portable\GCC\RISC-V" -I"C:\Users\mchhe\OneDrive\Dokumente\git\delete2\ch32v203_freertos3\FreeRTOS_10kbram_static_usbdragon\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\Users\mchhe\OneDrive\Dokumente\git\delete2\ch32v203_freertos3\FreeRTOS_10kbram_static_usbdragon\FreeRTOS\portable\MemMang" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

