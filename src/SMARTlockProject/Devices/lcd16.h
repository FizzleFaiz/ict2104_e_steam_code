#ifndef MSP_EXP432P401R_LCD16X2_LCD16_H_
#define MSP_EXP432P401R_LCD16X2_LCD16_H_


#include "msp.h"
#include <Hardware/GPIO_Driver.h>

//#define  RW BIT0
#define RESET_PORT      GPIO_PORT_P5
#define RESET_PIN       GPIO_PIN7
#define READ_PORT       GPIO_PORT_P3
#define READ_PIN        GPIO_PIN0
#define ENABLE_PORT     GPIO_PORT_P2
#define ENABLE_PIN      GPIO_PIN5
#define OUTPUT_PORT4    GPIO_PORT_P5
#define OUTPUT_PIN4     GPIO_PIN6
#define OUTPUT_PORT5    GPIO_PORT_P2
#define OUTPUT_PIN5     GPIO_PIN4
#define OUTPUT_PORT6    GPIO_PORT_P2
#define OUTPUT_PIN6     GPIO_PIN6
#define OUTPUT_PORT7    GPIO_PORT_P2
#define OUTPUT_PIN7     GPIO_PIN7

void waitlcd(unsigned int x);

void lcdinit(void);
void integerToLcd(unsigned int integer );
void lcdData(unsigned char l);
void prints(char *s);
void gotoXy(unsigned char  x,unsigned char y);

#endif /* MSP_EXP430F5529LP_LCD16X2_LCD16_H_ */
