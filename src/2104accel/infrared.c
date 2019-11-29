/*
 * infrared.c
 *
 *  Created on: 24 Oct 2019
 *      Author: kx
 */
#include "infrared.h"
#include "relay.h"
#include "keypad.h"
#include "lcd16.h"

/* RTOS header files */
#include <ti/sysbios/BIOS.h>

/* Driver configuration */
#include <ti/drivers/Board.h>

void infraredinit(void){
    //when no obstacle detected, output is high
    GPIO_Interrupt_Enable(INPUT_PORT, INPUT_PIN);         //P5IE |= BIT5;
    //set interrupt when there is high to low transition
    GPIO_Interrupt_Edge_High(INPUT_PORT, INPUT_PIN);      //P5IES |= BIT5;
    //clear interrupt flag
    GPIO_Clear_Interrupt_Flag(INPUT_PORT, INPUT_PIN);     //P5IFG = 0;
    //set as input pin
    GPIO_setAsInput(INPUT_PORT, INPUT_PIN);               //P5DIR &= ~BIT5;

    //used to demo only
    //P2DIR |= BIT0 + BIT1 + BIT2;
    //P1DIR = BIT0;
}

void infrarednodetect(void){

    relayoff();
}

void infrareddetect(void){
    //lock door if infrareddetected for more than 2seconds
    usleep(50);
    relayon();

}
