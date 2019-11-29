# ict2104_e_steam_code

## Introduction

We are group P2F E_Steam working on the SMART door lock project. 

### Integrated Components 

* LCD 
* Keypad
* Solenoid
* Infrared
* MPU-6050
* Relay

#### Unintegrated Components

* Ultrasonic Sensor HC-SR04
* Wi-Fi ESP8266

#### Components Not Implemented
* Serial Camera Module OV528 LCF-23M
* RFID MFRC522

## How to Start Development
### Prerequisites
* Code Composer v9 ([download here](http://software-dl.ti.com/ccs/esd/documents/ccs_downloads.html))


* MSP-EXP432P401R



### Setup
* `git clone` [here](https://github.com/FizzleFaiz/ict2104_e_steam_code/tree/master/src/2104accel)
* Configure project properties
    * **ARM Linker** 
    * -m"${ProjName}.map" -i"${INHERITED_LIBRARY_PATH}" -i"${COM_TI_SIMPLELINK_MSP432_SDK_INSTALL_DIR}/source" -i"${COM_TI_SIMPLELINK_MSP432_SDK_INSTALL_DIR}/kernel/tirtos/packages" -i"${CG_TOOL_ROOT}/lib" --diag_wrap=off --display_error_number --warn_sections --xml_link_info="${ProjName}_linkInfo.xml" --rom_model
    * **ARM Compiler**
    * -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="${INHERITED_INCLUDE_PATH}" --include_path="C:/ti/ccs/ccs_base/arm/include" --include_path="${PROJECT_ROOT}" --include_path="${PROJECT_ROOT}/${ConfigName}" --include_path="${COM_TI_SIMPLELINK_MSP432_SDK_INSTALL_DIR}/source" --include_path="${COM_TI_SIMPLELINK_MSP432_SDK_INSTALL_DIR}/source/third_party/CMSIS/Include" --include_path="${COM_TI_SIMPLELINK_MSP432_SDK_INSTALL_DIR}/source/ti/posix/ccs" --include_path="${CG_TOOL_ROOT}/include" --advice:power=none --define=${INHERITED_SYMBOLS} --define=_MSP432P401R_ -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on
    * **Include Options**
    * ![Image of Include Options](https://github.com/FizzleFaiz/ict2104_e_steam_code/blob/master/Include%20Options.jpeg)


## Authors

Displayed below are the list of students who have contributed to the development of the project from start to finish.

 Student Name | GitHub Username
--------------|----------------
Muhammad Faiz Bin Rahmat| FizzleFaiz
Muhammad Hafiz Bin Rosli| mrdhaffy
Pravinraj S/O Subramaniam | SilverBeardRJ
Chia Kai Xiang| 1802133


## Disclaimer
Codes in this [folder](https://github.com/FizzleFaiz/ict2104_e_steam_code/tree/master/src/2104accel) are able to work together. However, codes that belong in this 
[Working-Not-Integrated](https://github.com/FizzleFaiz/ict2104_e_steam_code/tree/master/src/2104accel/Working-Not_Integrated) can work individually but cannot be integrated into the main project.
