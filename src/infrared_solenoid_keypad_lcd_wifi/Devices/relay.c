/*
 * relay.c
 *
 *  Created on: 24 Oct 2019
 *      Author: kx
 */
#include "relay.h"

void relayinit(void){
    P6DIR |= BIT4;
}

void relayon(void){
    P6OUT |= BIT4;
}

void relayoff(void){
    P6OUT &= ~BIT4;
}

