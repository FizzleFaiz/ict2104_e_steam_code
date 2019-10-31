#include "msp.h"
#include <Hardware/CS_Driver.h>
#include <Devices/lcd16.h>
#include <Devices/keypad.h>
#include <Devices/relay.h>
#include <Devices/infrared.h>
#include <Devices/MSPIO.h>
#include <Devices/ESP8266.h>

void main(void)
{

	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

    P6DIR = BIT0+BIT1; //BIT0 - r/w, BIT1 - pin7 of LCD
    P4DIR = BIT0+BIT2+BIT3+BIT4+BIT5; //BIT0 - pin8 of LCD, BIT2 - pin9 of LCD, BIT3 - enable pin of LCD, BIT4 - pin10 of lcd, BIT5 - RS pin of LCD

    P6OUT=0; //set output to low
    P4OUT=0; //set output to low

    CS_Init();
    lcdinit();
    keypadinit();
    relayinit();
    infraredinit();
    ESP8266_init();

    MAP_Interrupt_enableMaster();
    NVIC->ISER[1]= 1<< ((PORT5_IRQn)&31);
    _enable_interrupts();

    prints("ENTER PASSWORD:"); // prints at top line by default

    while(1)
    {
        infrarednodetect();
        keypadpress();
        relayon();
    }
}

void PORT5_IRQHandler(void){
    if (~(P5IN & BIT5)){//when output is low (detected obstacle)
        //set delay and check if condition still true to lock solenoid
        infrareddetect();
        P5IFG &= ~BIT5;
    }

}
