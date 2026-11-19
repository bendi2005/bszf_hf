################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app.c \
../display.c \
../game.c \
../main.c \
../timing.c \
../uart_stuff.c 

OBJS += \
./app.o \
./display.o \
./game.o \
./main.o \
./timing.o \
./uart_stuff.o 

C_DEPS += \
./app.d \
./display.d \
./game.d \
./main.d \
./timing.d \
./uart_stuff.d 


# Each subdirectory must supply rules for building sources it contributes
app.o: ../app.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DHFXO_FREQ=48000000' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame/config" -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame/autogen" -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFM32GG/Include" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"app.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

display.o: ../display.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DHFXO_FREQ=48000000' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame/config" -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame/autogen" -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFM32GG/Include" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"display.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

game.o: ../game.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DHFXO_FREQ=48000000' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame/config" -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame/autogen" -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFM32GG/Include" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"game.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.o: ../main.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DHFXO_FREQ=48000000' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame/config" -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame/autogen" -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFM32GG/Include" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"main.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

timing.o: ../timing.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DHFXO_FREQ=48000000' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame/config" -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame/autogen" -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFM32GG/Include" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"timing.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

uart_stuff.o: ../uart_stuff.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DHFXO_FREQ=48000000' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame/config" -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame/autogen" -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFM32GG/Include" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"uart_stuff.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


