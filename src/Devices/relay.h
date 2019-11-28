/*
 * relay.h
 *
 *  Created on: 24 Oct 2019
 *      Author: kx
 */

#ifndef RELAY_H_
#define RELAY_H_
#include "msp.h"
#include <Hardware/GPIO_Driver.h>

#define OUTPUT_PORT GPIO_PORT_P3
#define OUTPUT_PIN GPIO_PIN7

void relayinit(void);
void relayon(void);
void relayoff(void);



#endif /* RELAY_H_ */
