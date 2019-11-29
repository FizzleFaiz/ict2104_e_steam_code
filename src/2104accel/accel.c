/*
 * accel.c (driver file)
 *
 *  Created on: 27 Oct 2019
 *      Author: hafiz
 *
 * REFERENCES:
 * https://pdf1.alldatasheet.com/datasheet-pdf/view/1132807/TDK/MPU-6050.html
 * https://forum.43oh.com/topic/9107-interface-msp432-with-mpu6050/
 * i2cmasterexample1.c from resource explorer
 * https://forum.arduino.cc/index.php?topic=312298.0
 * https://www.invensense.com/wp-content/uploads/2015/02/MPU-6000-Register-Map1.pdf
 * https://www.microchip.com/forums/m66323.aspx
 * https://courses.cs.washington.edu/courses/cse474/17wi/labs/l4/MPU6050BasicExample.ino
 *
 * PINS USED:
 * VCC - 3V3
 * GND - GND
 * SCL - P6.5
 * SDA - P6.4
 */

#include <hardware/I2C_Driver.h>
#include "msp.h"
#include "accel.h"

/* Driver Header files */
#include <ti/drivers/I2C.h>
/* Driver configuration */
#include "ti_drivers_config.h"

/* Set the default scale range of the accelerometer */
uint8_t AFS_SEL = 3; /* Full scale range 3. +-16g */

I2C_Handle i2c;

void writeByte(){
    writeI2C(i2c, 0x6B, 0x00); //0x6B = PWR_MGMT_1
}

int16_t* readAccelData(){
    usleep(50); //allow thread to sleep and run the other one for 50us
    uint8_t* accelRaw = readI2C(i2c, 0x3B, 6); //0x3B (ACCEL_XOUT_H), 6 values
    static int16_t accelData[3];
    /*16-bit 2’s complement value. Combine 2 8bit to 16bit data. Offset 2048 to +-16g.*/
    accelData[0] = (int16_t) ((accelRaw[0] << 8) | accelRaw[1]); /* X */
    accelData[1] = (int16_t) ((accelRaw[2] << 8) | accelRaw[3]); /* Y */
    accelData[2] = (int16_t) ((accelRaw[4] << 8) | accelRaw[5]); /* Z */
    return accelData;
}
