/*
 * keypad.h
 *
 *  Created on: 24 Oct 2019
 *      Author: kx
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "msp.h"
#include "lcd16.h"
#include <Hardware/GPIO_Driver.h>

#define R1_PORT GPIO_PORT_P4
#define R1_PIN  GPIO_PIN6
#define R2_PORT GPIO_PORT_P1
#define R2_PIN  GPIO_PIN5
#define R3_PORT GPIO_PORT_P4
#define R3_PIN  GPIO_PIN3
#define R4_PORT GPIO_PORT_P4
#define R4_PIN  GPIO_PIN1
#define C1_PORT GPIO_PORT_P3
#define C1_PIN  GPIO_PIN3
#define C2_PORT GPIO_PORT_P3
#define C2_PIN  GPIO_PIN2
#define C3_PORT GPIO_PORT_P6
#define C3_PIN  GPIO_PIN0
#define MAXLENGTH 6
char password[MAXLENGTH];
uint32_t GPIO_STATUS;

void keypadinit(void);
void keypadrowinit(void);
void keypadcolinit(void);
void keypadrowoutput(void);
void keypadpress(void);
void keypadcolcheck(uint32_t KEYINPUT_PORT, uint16_t KEYINPUT_PIN, char R1, char R2, char R3, char R4);
void checkpassword(void);
void insertpassword(char p);
void clearPassword(void);



#endif /* KEYPAD_H_ */
