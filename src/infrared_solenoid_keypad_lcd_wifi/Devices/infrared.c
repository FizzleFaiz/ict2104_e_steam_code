/*
 * infrared.c
 *
 *  Created on: 24 Oct 2019
 *      Author: kx
 */
#include "infrared.h"

void infraredinit(void){
    //when no obstacle detected, output is high
    P5IE |= BIT5;
    //set interrupt when there is high to low transition
    P5IES |= BIT5;
    P5IFG = 0;
    P5DIR &= ~BIT5;

    //used to demo only
    P2DIR |= BIT0 + BIT1 + BIT2;
}

void infrareddetect(void){
    P2OUT |= BIT0 + BIT1 + BIT2;
}

void infrarednodetect(void){
    P2OUT |= BIT2;
    P2OUT &= ~BIT0;
    P2OUT &= ~BIT1;
}
