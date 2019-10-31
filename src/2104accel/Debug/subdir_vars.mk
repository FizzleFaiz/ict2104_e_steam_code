################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
../MSP_EXP432P401R_TIRTOS.cmd 

SYSCFG_SRCS += \
../i2cmasterexample1.syscfg 

C_SRCS += \
../I2C.c \
../accel.c \
./syscfg/ti_drivers_config.c \
../main_tirtos.c \
../masterThread.c \
../masterThread2(copy).c 

GEN_FILES += \
./syscfg/ti_drivers_config.c 

GEN_MISC_DIRS += \
./syscfg/ 

C_DEPS += \
./I2C.d \
./accel.d \
./syscfg/ti_drivers_config.d \
./main_tirtos.d \
./masterThread.d \
./masterThread2(copy).d 

OBJS += \
./I2C.obj \
./accel.obj \
./syscfg/ti_drivers_config.obj \
./main_tirtos.obj \
./masterThread.obj \
./masterThread2(copy).obj 

GEN_MISC_FILES += \
./syscfg/ti_drivers_config.h \
./syscfg/syscfg_c.rov.xs 

GEN_MISC_DIRS__QUOTED += \
"syscfg\" 

OBJS__QUOTED += \
"I2C.obj" \
"accel.obj" \
"syscfg\ti_drivers_config.obj" \
"main_tirtos.obj" \
"masterThread.obj" \
"masterThread2(copy).obj" 

GEN_MISC_FILES__QUOTED += \
"syscfg\ti_drivers_config.h" \
"syscfg\syscfg_c.rov.xs" 

C_DEPS__QUOTED += \
"I2C.d" \
"accel.d" \
"syscfg\ti_drivers_config.d" \
"main_tirtos.d" \
"masterThread.d" \
"masterThread2(copy).d" 

GEN_FILES__QUOTED += \
"syscfg\ti_drivers_config.c" 

C_SRCS__QUOTED += \
"../I2C.c" \
"../accel.c" \
"./syscfg/ti_drivers_config.c" \
"../main_tirtos.c" \
"../masterThread.c" \
"../masterThread2(copy).c" 

SYSCFG_SRCS__QUOTED += \
"../i2cmasterexample1.syscfg" 


