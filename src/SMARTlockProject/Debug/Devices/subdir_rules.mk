################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Devices/%.obj: ../Devices/%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs901/ccs/tools/compiler/ti-cgt-arm_18.12.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/ccs901/ccs/ccs_base/arm/include" --include_path="C:/ti/simplelink_msp432p4_sdk_3_30_00_13/source" --include_path="C:/ti/ccs901/ccs/ccs_base/arm/include/CMSIS" --include_path="C:/Users/kx/workspace_v9/SMARTlockProject" --include_path="C:/ti/ccs901/ccs/tools/compiler/ti-cgt-arm_18.12.1.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Devices/$(basename $(<F)).d_raw" --obj_directory="Devices" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


