/*
 * I2C.c
 *
 *  Created on: 27 Oct 2019
 *      Author: hafiz
 *
 * REFERENCES:
 * http://www.ti.com/lit/ug/spruhd4m/spruhd4m.pdf
 * i2cmasterexample1.c from resource explorer
 *
 * PINS USED:
 * VCC - 3V3
 * GND - GND
 * SCL - P6.5
 * SDA - P6.4
 */

#include "I2C.h"

bool retVal = false;
I2C_Transaction i2cTransaction;
uint8_t txBuffer[10];
uint8_t rxBuffer[10];

void writeI2C(I2C_Handle i2c, uint8_t regAddr, uint8_t value){
    /*
     * regAddr:
     * 0x6B = PWR_MGMT_1
     *
     * Send SETSTATUS Cmd to Slave.
     * txBuffer[0] = 0x02; [SETSTATUS CMD]
     * txBuffer[1] = 'x'; Status byte to be overwritten
     */
    txBuffer[0] = regAddr;
    txBuffer[1] = value;
    i2cTransaction.slaveAddress = 0x68; /*MPU address 0x68*/
    i2cTransaction.writeBuf = txBuffer;
    i2cTransaction.writeCount = 2;
    i2cTransaction.readBuf = rxBuffer;
    i2cTransaction.readCount = 0;

    /* Re-try writing to slave till I2C_transfer returns true */
    do {
        retVal = I2C_transfer(i2c, &i2cTransaction);
    } while(!retVal);
}

uint8_t* readI2C(I2C_Handle i2c, uint8_t regAddr, uint8_t value){
    /*
     * regAddr:
     * 0x3B = ACCEL_XOUT_H
     *
     * Send GETSTATUS Cmd to Slave.
     * txBuffer[0] = 0x01; [GETSTATUS CMD]
     * rxBuffer[0] = status returned by slave
     */
    txBuffer[0] = regAddr; /*ACCELEROMETER register address*/
    i2cTransaction.slaveAddress = 0x68; /*MPU address 0x68*/
    i2cTransaction.writeCount = 1;
    i2cTransaction.writeBuf = txBuffer;
    i2cTransaction.readCount = value;
    i2cTransaction.readBuf = rxBuffer;

    /* Re-try writing to slave till I2C_transfer returns true */
    do {
        retVal = I2C_transfer(i2c, &i2cTransaction);
    } while(!retVal);

    return rxBuffer;
}
