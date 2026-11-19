################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/bendi/SimplicityStudio/SDKs/gecko_sdk/platform/emlib/src/em_cmu.c \
/home/bendi/SimplicityStudio/SDKs/gecko_sdk/platform/emlib/src/em_core.c \
/home/bendi/SimplicityStudio/SDKs/gecko_sdk/platform/emlib/src/em_emu.c \
/home/bendi/SimplicityStudio/SDKs/gecko_sdk/platform/emlib/src/em_gpio.c \
/home/bendi/SimplicityStudio/SDKs/gecko_sdk/platform/emlib/src/em_lcd.c \
/home/bendi/SimplicityStudio/SDKs/gecko_sdk/platform/emlib/src/em_msc.c \
/home/bendi/SimplicityStudio/SDKs/gecko_sdk/platform/emlib/src/em_system.c \
/home/bendi/SimplicityStudio/SDKs/gecko_sdk/platform/emlib/src/em_usart.c 

OBJS += \
./gecko_sdk_4.4.6/platform/emlib/src/em_cmu.o \
./gecko_sdk_4.4.6/platform/emlib/src/em_core.o \
./gecko_sdk_4.4.6/platform/emlib/src/em_emu.o \
./gecko_sdk_4.4.6/platform/emlib/src/em_gpio.o \
./gecko_sdk_4.4.6/platform/emlib/src/em_lcd.o \
./gecko_sdk_4.4.6/platform/emlib/src/em_msc.o \
./gecko_sdk_4.4.6/platform/emlib/src/em_system.o \
./gecko_sdk_4.4.6/platform/emlib/src/em_usart.o 

C_DEPS += \
./gecko_sdk_4.4.6/platform/emlib/src/em_cmu.d \
./gecko_sdk_4.4.6/platform/emlib/src/em_core.d \
./gecko_sdk_4.4.6/platform/emlib/src/em_emu.d \
./gecko_sdk_4.4.6/platform/emlib/src/em_gpio.d \
./gecko_sdk_4.4.6/platform/emlib/src/em_lcd.d \
./gecko_sdk_4.4.6/platform/emlib/src/em_msc.d \
./gecko_sdk_4.4.6/platform/emlib/src/em_system.d \
./gecko_sdk_4.4.6/platform/emlib/src/em_usart.d 


# Each subdirectory must supply rules for building sources it contributes
gecko_sdk_4.4.6/platform/emlib/src/em_cmu.o: /home/bendi/SimplicityStudio/SDKs/gecko_sdk/platform/emlib/src/em_cmu.c gecko_sdk_4.4.6/platform/emlib/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DHFXO_FREQ=48000000' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame/config" -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame/autogen" -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFM32GG/Include" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.4.6/platform/emlib/src/em_cmu.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.4.6/platform/emlib/src/em_core.o: /home/bendi/SimplicityStudio/SDKs/gecko_sdk/platform/emlib/src/em_core.c gecko_sdk_4.4.6/platform/emlib/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DHFXO_FREQ=48000000' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame/config" -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame/autogen" -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFM32GG/Include" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.4.6/platform/emlib/src/em_core.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.4.6/platform/emlib/src/em_emu.o: /home/bendi/SimplicityStudio/SDKs/gecko_sdk/platform/emlib/src/em_emu.c gecko_sdk_4.4.6/platform/emlib/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DHFXO_FREQ=48000000' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame/config" -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame/autogen" -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFM32GG/Include" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.4.6/platform/emlib/src/em_emu.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.4.6/platform/emlib/src/em_gpio.o: /home/bendi/SimplicityStudio/SDKs/gecko_sdk/platform/emlib/src/em_gpio.c gecko_sdk_4.4.6/platform/emlib/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DHFXO_FREQ=48000000' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame/config" -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame/autogen" -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFM32GG/Include" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.4.6/platform/emlib/src/em_gpio.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.4.6/platform/emlib/src/em_lcd.o: /home/bendi/SimplicityStudio/SDKs/gecko_sdk/platform/emlib/src/em_lcd.c gecko_sdk_4.4.6/platform/emlib/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DHFXO_FREQ=48000000' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame/config" -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame/autogen" -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFM32GG/Include" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.4.6/platform/emlib/src/em_lcd.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.4.6/platform/emlib/src/em_msc.o: /home/bendi/SimplicityStudio/SDKs/gecko_sdk/platform/emlib/src/em_msc.c gecko_sdk_4.4.6/platform/emlib/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DHFXO_FREQ=48000000' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame/config" -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame/autogen" -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFM32GG/Include" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.4.6/platform/emlib/src/em_msc.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.4.6/platform/emlib/src/em_system.o: /home/bendi/SimplicityStudio/SDKs/gecko_sdk/platform/emlib/src/em_system.c gecko_sdk_4.4.6/platform/emlib/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DHFXO_FREQ=48000000' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame/config" -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame/autogen" -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFM32GG/Include" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.4.6/platform/emlib/src/em_system.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.4.6/platform/emlib/src/em_usart.o: /home/bendi/SimplicityStudio/SDKs/gecko_sdk/platform/emlib/src/em_usart.c gecko_sdk_4.4.6/platform/emlib/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DHFXO_FREQ=48000000' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame/config" -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame/autogen" -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFM32GG/Include" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.4.6/platform/emlib/src/em_usart.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


