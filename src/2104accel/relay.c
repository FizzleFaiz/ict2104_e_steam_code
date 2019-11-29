/*
 * relay.c
 *
 *  Created on: 24 Oct 2019
 *      Author: kx
 */
#include "relay.h"

/* RTOS header files */
#include <ti/sysbios/BIOS.h>

/* Driver configuration */
#include <ti/drivers/Board.h>

void relayinit(void){
    GPIO_setAsOutput(OUTPUT_PORT, OUTPUT_PIN);
}

void relayon(void){
    GPIO_Output_High(OUTPUT_PORT, OUTPUT_PIN);
}

void relayoff(void){
    GPIO_Output_Low(OUTPUT_PORT, OUTPUT_PIN);
}

