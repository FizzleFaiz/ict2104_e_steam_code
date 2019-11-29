//
//
//#include <msp.h>
//#include <stdio.h>
//
//unsigned int distance;
//unsigned long duration;
//unsigned int up_counter = 0;
//
//
//void main(void){
//    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;       // stop watchdog timer
//
//      TIMER_A0->CTL = TIMER_A_CTL_SSEL__SMCLK|
//                          TIMER_A_CTL_MC_1 |
//                          TIMER_A_CTL_CLR |
//                          TIMER_A_CTL_IE;
//
//      P1DIR |= BIT0;                  // Set P1.0 to output direction
//      P2DIR |= BIT2;                  // Set P1.0 to output direction
//      P5DIR |= BIT0;                  // Set P5.0 to input direction
//      P5DIR &= ~BIT2;                 // Set P5.2 to output direction
//
//      //P5IFG = 0x00;
//      P5IE |= BIT2;                   //enable interrupt for P5.2
//      P5IES |= BIT2;
//      P5IFG = 0;
//      NVIC->ISER[1] |= 1 << (PORT5_IRQn & 31);
//      // enable global interrupts
//      __enable_interrupt();
//
//
//      TA0CCR0 = 60000;        // measure at 60 ms
//      setTimer();             // activate timer and transmit signal
//      while (1) {
//      }
//}
//
//void setTimer() {
//    P5OUT |= BIT0;         //trigger pin to hgh
//    __delay_cycles(10);    // 10microsecond delay gap
//    P5OUT &= ~BIT0;         // trigger pin to low
//    TIMER_A0->CTL |= TIMER_A_CTL_CLR;
//}
//
//void PORT5_IRQHandler(void){
//    if(P5IFG & BIT2)
//    {
//      duration = TA0R / 2;          // time duration for pulse sent and received/2
//      distance = duration/291;       // divide by 29ms for 1cm as speed of sound is 343m/s
//
//      if(distance < 10)
//      {
//          up_counter++;                           // to simulate the time taken to light up the blue LED
//          if(up_counter >= 10){
//              P1OUT |= BIT0;                      // ON P1.0 LED to detect presence
//              if(up_counter >= 100){
//
//                  P2OUT |= BIT2;                    // ON P2.2 LED to send signal to camera and activate P2.2 LED
//                  up_counter = 0;
//              }
//          }
//      }else{
//          P1OUT &= ~BIT0;                        // OFF P1.0 LED
//          P2OUT &= ~BIT2;                        // OFF P2.2 LED
//          up_counter = 0;
//      }
//      __delay_cycles(50000);
//       setTimer();
//    }
//      P5IFG &= ~BIT2;                           //reset flag
//}
