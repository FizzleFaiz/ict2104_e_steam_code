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
../accel.c \
./syscfg/ti_drivers_config.c \
../infrared.c \
../irThread.c \
../keypad.c \
../lcd16.c \
../main_tirtos.c \
../masterThread.c \
../relay.c 

GEN_FILES += \
./syscfg/ti_drivers_config.c 

GEN_MISC_DIRS += \
./syscfg/ 

C_DEPS += \
./accel.d \
./syscfg/ti_drivers_config.d \
./infrared.d \
./irThread.d \
./keypad.d \
./lcd16.d \
./main_tirtos.d \
./masterThread.d \
./relay.d 

OBJS += \
./accel.obj \
./syscfg/ti_drivers_config.obj \
./infrared.obj \
./irThread.obj \
./keypad.obj \
./lcd16.obj \
./main_tirtos.obj \
./masterThread.obj \
./relay.obj 

GEN_MISC_FILES += \
./syscfg/ti_drivers_config.h \
./syscfg/syscfg_c.rov.xs 

GEN_MISC_DIRS__QUOTED += \
"syscfg\" 

OBJS__QUOTED += \
"accel.obj" \
"syscfg\ti_drivers_config.obj" \
"infrared.obj" \
"irThread.obj" \
"keypad.obj" \
"lcd16.obj" \
"main_tirtos.obj" \
"masterThread.obj" \
"relay.obj" 

GEN_MISC_FILES__QUOTED += \
"syscfg\ti_drivers_config.h" \
"syscfg\syscfg_c.rov.xs" 

C_DEPS__QUOTED += \
"accel.d" \
"syscfg\ti_drivers_config.d" \
"infrared.d" \
"irThread.d" \
"keypad.d" \
"lcd16.d" \
"main_tirtos.d" \
"masterThread.d" \
"relay.d" 

GEN_FILES__QUOTED += \
"syscfg\ti_drivers_config.c" 

C_SRCS__QUOTED += \
"../accel.c" \
"./syscfg/ti_drivers_config.c" \
"../infrared.c" \
"../irThread.c" \
"../keypad.c" \
"../lcd16.c" \
"../main_tirtos.c" \
"../masterThread.c" \
"../relay.c" 

SYSCFG_SRCS__QUOTED += \
"../i2cmasterexample1.syscfg" 


