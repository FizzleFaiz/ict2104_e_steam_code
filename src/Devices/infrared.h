/*
 * infrared.h
 *
 *  Created on: 24 Oct 2019
 *      Author: kx
 */

#ifndef INFRARED_H_
#define INFRARED_H_
#include "msp.h"
#include <Hardware/GPIO_Driver.h>

#define INPUT_PORT     GPIO_PORT_P5
#define INPUT_PIN      GPIO_PIN5
void infraredinit(void);
void infrareddetect(void);
void infrarednodetect(void);





#endif /* INFRARED_H_ */
