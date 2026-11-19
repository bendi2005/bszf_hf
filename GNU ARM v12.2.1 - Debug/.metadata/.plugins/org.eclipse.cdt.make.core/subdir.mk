################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../.metadata/.plugins/org.eclipse.cdt.make.core/specs.cpp 

C_SRCS += \
../.metadata/.plugins/org.eclipse.cdt.make.core/specs.c 

OBJS += \
./.metadata/.plugins/org.eclipse.cdt.make.core/specs.o 

C_DEPS += \
./.metadata/.plugins/org.eclipse.cdt.make.core/specs.d 

CPP_DEPS += \
./.metadata/.plugins/org.eclipse.cdt.make.core/specs.d 


# Each subdirectory must supply rules for building sources it contributes
.metadata/.plugins/org.eclipse.cdt.make.core/specs.o: ../.metadata/.plugins/org.eclipse.cdt.make.core/specs.c .metadata/.plugins/org.eclipse.cdt.make.core/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DHFXO_FREQ=48000000' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame/config" -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame/autogen" -I"/home/bendi/SimplicityStudio/v5_workspace/bszf_hf/snakegame" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFM32GG/Include" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"/home/bendi/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF".metadata/.plugins/org.eclipse.cdt.make.core/specs.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

.metadata/.plugins/org.eclipse.cdt.make.core/specs.o: ../.metadata/.plugins/org.eclipse.cdt.make.core/specs.cpp .metadata/.plugins/org.eclipse.cdt.make.core/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C++ Compiler'
	arm-none-eabi-g++ -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c++11 -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -fno-rtti -fno-exceptions --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF".metadata/.plugins/org.eclipse.cdt.make.core/specs.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


