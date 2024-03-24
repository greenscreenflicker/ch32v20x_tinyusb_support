################################################################################
# MRS Version: {"version":"1.8.5","date":"2023/05/22"}
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include tinyusb/typec/subdir.mk
-include tinyusb/portable/wch/subdir.mk
-include tinyusb/portable/valentyusb/eptri/subdir.mk
-include tinyusb/portable/ti/msp430x5xx/subdir.mk
-include tinyusb/portable/template/subdir.mk
-include tinyusb/portable/synopsys/dwc2/subdir.mk
-include tinyusb/portable/sunxi/subdir.mk
-include tinyusb/portable/st/typec/subdir.mk
-include tinyusb/portable/st/stm32_fsdev/subdir.mk
-include tinyusb/portable/sony/cxd56/subdir.mk
-include tinyusb/portable/renesas/rusb2/subdir.mk
-include tinyusb/portable/raspberrypi/rp2040/subdir.mk
-include tinyusb/portable/raspberrypi/pio_usb/subdir.mk
-include tinyusb/portable/ohci/subdir.mk
-include tinyusb/portable/nxp/lpc_ip3511/subdir.mk
-include tinyusb/portable/nxp/lpc17_40/subdir.mk
-include tinyusb/portable/nxp/khci/subdir.mk
-include tinyusb/portable/nuvoton/nuc505/subdir.mk
-include tinyusb/portable/nuvoton/nuc121/subdir.mk
-include tinyusb/portable/nuvoton/nuc120/subdir.mk
-include tinyusb/portable/nordic/nrf5x/subdir.mk
-include tinyusb/portable/mindmotion/mm32/subdir.mk
-include tinyusb/portable/microchip/samx7x/subdir.mk
-include tinyusb/portable/microchip/samg/subdir.mk
-include tinyusb/portable/microchip/samd/subdir.mk
-include tinyusb/portable/microchip/pic32mz/subdir.mk
-include tinyusb/portable/microchip/pic/subdir.mk
-include tinyusb/portable/mentor/musb/subdir.mk
-include tinyusb/portable/espressif/esp32sx/subdir.mk
-include tinyusb/portable/ehci/subdir.mk
-include tinyusb/portable/dialog/da146xx/subdir.mk
-include tinyusb/portable/chipidea/ci_hs/subdir.mk
-include tinyusb/portable/chipidea/ci_fs/subdir.mk
-include tinyusb/portable/bridgetek/ft9xx/subdir.mk
-include tinyusb/portable/analog/max3421/subdir.mk
-include tinyusb/host/subdir.mk
-include tinyusb/device/subdir.mk
-include tinyusb/common/subdir.mk
-include tinyusb/class/video/subdir.mk
-include tinyusb/class/vendor/subdir.mk
-include tinyusb/class/usbtmc/subdir.mk
-include tinyusb/class/net/subdir.mk
-include tinyusb/class/msc/subdir.mk
-include tinyusb/class/midi/subdir.mk
-include tinyusb/class/hid/subdir.mk
-include tinyusb/class/dfu/subdir.mk
-include tinyusb/class/cdc/subdir.mk
-include tinyusb/class/bth/subdir.mk
-include tinyusb/class/audio/subdir.mk
-include tinyusb/subdir.mk
-include User/subdir.mk
-include Startup/subdir.mk
-include Peripheral/src/subdir.mk
-include FreeRTOS/portable/MemMang/subdir.mk
-include FreeRTOS/portable/GCC/RISC-V/subdir.mk
-include FreeRTOS/subdir.mk
-include Debug/subdir.mk
-include Core/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
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
SECONDARY_FLASH += \
FreeRTOS.hex \

SECONDARY_LIST += \
FreeRTOS.lst \

SECONDARY_SIZE += \
FreeRTOS.siz \


# All Target
all: FreeRTOS.elf secondary-outputs

# Tool invocations
FreeRTOS.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused  -g -T "C:\Users\mchhe\OneDrive\Dokumente\git\delete2\ch32v203_freertos3\FreeRTOS_10kbram_static_usbdragon\Ld\Link.ld" -nostartfiles -Xlinker --gc-sections -Wl,-Map,"FreeRTOS.map" --specs=nano.specs --specs=nosys.specs -o "FreeRTOS.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@	@
FreeRTOS.hex: FreeRTOS.elf
	@	riscv-none-embed-objcopy -O ihex "FreeRTOS.elf"  "FreeRTOS.hex"
	@	@
FreeRTOS.lst: FreeRTOS.elf
	@	riscv-none-embed-objdump --all-headers --demangle --disassemble -M xw "FreeRTOS.elf" > "FreeRTOS.lst"
	@	@
FreeRTOS.siz: FreeRTOS.elf
	@	riscv-none-embed-size --format=berkeley "FreeRTOS.elf"
	@	@
# Other Targets
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) FreeRTOS.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
