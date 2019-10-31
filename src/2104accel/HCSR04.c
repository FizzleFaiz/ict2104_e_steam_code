/********************************************************************/
/* Project: Ultrasonice based Distance Meter with LCD Display       */
/* Microcontroller: MSP430G2231 on MSP-EXP430G2 Launchpad           */
/* Ultrasonic Ranging Module: HC-SR04                               */
/* 16x2 LCD Display: 1602K27-00                                     */
/********************************************************************/
/********************************************************************/
/* uC and Ultrasonic sensor Connections
    P1.4 - Trigger
    P1.5 - Echo     */
/********************************************************************/
/* uC and LCD Connections
    TP1 - Vcc (+5v)
    TP3 - Vss (Gnd)
    P2.2 - EN
    P2.3 - RS
    P2.4 - D4
    P2.5 - D5
    P2.6 - D6
    P2.7 - D7
    Gnd  - RW
    Gnd  - Vee/Vdd - Connect to Gnd through a 1K Resistor
            - this value determines contrast -
            - i.e. without resistor all dots always visible, whereas
            - higher resistor means dots not at all displayed.
    Gnd  - K (LED-)
    Vcc  - A (LED+) +5V - For Backlight
    Clock: 1MHz                                                     */
/********************************************************************/
/*
#include <msp.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// uC GPIO Port assignment

// Peripheral pin assignments
#define US_TRIG         BIT0
#define US_ECHO         BIT2

#define PWM_PERIOD 3000
unsigned int meas1;
unsigned int meas2;

unsigned int seconds;
unsigned int distance;
//unsigned long sensor;
unsigned int i = 0;



/* Timer A0 Capture Interrupt routine
 P1.1 (echo) causes this routine to be called */
/*
void PORT5_IRQHandler(void){


    if(P5IFG & BIT2)
    {
        if ((BIT2 & P5OUT) == BIT2) {            // read P3.6 Output
             seconds = 1;
             printf("GREEN LED ON    ");
             P1OUT |= BIT0;                      // ON P1.0 LED
        } else {
             printf("GREEN LED OFF   ");
             P1OUT &= ~BIT0;                // OFF P1.0 LED
        }

//      sensor = i / 2;
//      distance = sensor/29;
//      printf("signalInteruppt %d\n", seconds);

    }
//       printf("signalafterInteruppt %d\n", seconds);
       //seconds = 0;
       P5IFG = ~BIT2;

}
void trigger() {
    P5OUT |= US_TRIG;
    __delay_cycles(10);
    P5OUT &= ~US_TRIG;
    __delay_cycles(50000);             // 0.5sec measurement cycle
    TIMER_A0->CTL |= TIMER_A_CTL_CLR;
    __enable_interrupt();
}


void main(void)
{
       WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;       // stop watchdog timer

       TIMER_A0->CTL = TIMER_A_CTL_SSEL__SMCLK|
                             TIMER_A_CTL_MC_1 |
                             TIMER_A_CTL_CLR |
                             TIMER_A_CTL_IE;

       P1DIR |= BIT0;                  // Set P1.0 to output direction
  //     P2DIR |= BIT0 + BIT1 + BIT2;    // Set P2.0 to output direction

       P5DIR |= US_TRIG;
       P5DIR &= ~US_ECHO;
       P5OUT &= ~US_TRIG;            // keep trigger at low


       P5IE |= US_ECHO;
       P5IES |= US_ECHO;
       P5IFG = 0;

      //Enable global interrupt
       //   __enable_interrupt();

          //NVIC->ISER[0] |= 1 << ((TA1_0_IRQn) & 31);   //TA1_0_IRQn
          NVIC->ISER[1] |= 1 << (PORT5_IRQn & 31);
          //        measuring the distance
      /*     P5OUT ^= US_TRIG;                 // assert
           __delay_cycles(10);                 //10us wide
           P5OUT = ~US_TRIG;                 // deassert(low)
           __delay_cycles(60000);            // 60ms measurement cycle
           __delay_cycles(50000);             // 0.5sec measurement cycle

           //Enable global interrupt
            __enable_interrupt();*/
/*          trigger();

           while(1)
           {
              if((P5OUT & BIT2)==BIT2)
                  i++;
              else if((P5OUT & BIT2)==0)
                  seconds = 0;
              printf("signalIWhile %d\n", seconds);
              printf("counter %d\n", i);
            }
}*/
#include <msp.h>
#include <stdio.h>




unsigned int distance;
unsigned long duration;
unsigned int up_counter = 0;


void main(void)
{
  WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;       // stop watchdog timer

  TIMER_A0->CTL = TIMER_A_CTL_SSEL__SMCLK|
                      TIMER_A_CTL_MC_1 |
                      TIMER_A_CTL_CLR |
                      TIMER_A_CTL_IE;

  P1DIR |= BIT0;                  // Set P1.0 to output direction
  P2DIR |= BIT2;                  // Set P1.0 to output direction
  P5DIR |= BIT0;
  P5DIR &= ~BIT2;

  //P5IFG = 0x00;
  P5IE |= BIT2;
  P5IES |= BIT2;
  P5IFG = 0;
  NVIC->ISER[1] |= 1 << (PORT5_IRQn & 31);
  __enable_interrupt();


  TA0CCR0 = 60000;        // measure at 60 ms
  setTrigger();
  while (1) {
  }
}

void setTrigger() {
    P5OUT |= BIT0;
    __delay_cycles(10);    // 10microsecond delay gap
    P5OUT &= ~BIT0;
    TIMER_A0->CTL |= TIMER_A_CTL_CLR;
}

void PORT5_IRQHandler(void){
    if(P5IFG & BIT2)
    {
      duration = TA0R / 2;          // time duration for pulse sent and received/2
      distance = duration/29;
      //printf("TA0R: %d, Sensor: %d\n",TA0R, sensor);
      printf("distance: %d cm\n", distance);
      if(distance < 100)
      {
          up_counter++;
          if(up_counter >= 10){
              P1OUT |= BIT0;                      // ON P1.0 LED
              if(up_counter >= 100){
                  printf("Intruder Alert!\n");
                  P2OUT |= BIT2;
                  up_counter = 0;
              }
          }
      }else{
          P1OUT &= ~BIT0;
          P2OUT &= ~BIT2;
      }
      __delay_cycles(50000);
      setTrigger();
    }
      P5IFG &= ~BIT2;
}

