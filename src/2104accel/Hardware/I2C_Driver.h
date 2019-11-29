/*
 * I2C.h
 *
 *  Created on: 27 Oct 2019
 *      Author: hafiz
 */

#ifndef I2C_DRIVER_H_
#define I2C_DRIVER_H_

#include <ti/drivers/I2C.h>

void writeI2C(I2C_Handle i2c, uint8_t regAddr, uint8_t value);
uint8_t* readI2C(I2C_Handle i2c, uint8_t regAddr, uint8_t value);

#endif /* I2C_DRIVER_H_ */
