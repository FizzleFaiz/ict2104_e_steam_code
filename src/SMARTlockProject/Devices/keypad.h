/*
 * keypad.h
 *
 *  Created on: 24 Oct 2019
 *      Author: kx
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "msp.h"
#include <Hardware/GPIO_Driver.h>

#define R1_PORT GPIO_PORT_P1
#define R1_PIN  GPIO_PIN7
#define R2_PORT GPIO_PORT_P5
#define R2_PIN  GPIO_PIN0
#define R3_PORT GPIO_PORT_P5
#define R3_PIN  GPIO_PIN2
#define R4_PORT GPIO_PORT_P3
#define R4_PIN  GPIO_PIN6
#define C1_PORT GPIO_PORT_P2
#define C1_PIN  GPIO_PIN3
#define C2_PORT GPIO_PORT_P5
#define C2_PIN  GPIO_PIN1
#define C3_PORT GPIO_PORT_P3
#define C3_PIN  GPIO_PIN5
#define MAXLENGTH 6
char password[MAXLENGTH];
uint32_t GPIO_STATUS;

void keypadinit(void);
void keypadrowinit(void);
void keypadcolinit(void);
void keypadrowoutput(void);
void keypadpress(void);
void keypadcolcheck(uint32_t status, uint16_t INPUT_PIN, char R1, char R2, char R3, char R4);
//void keypadcol1check(void);
//void keypadcol2check(void);
//void keypadcol3check(void);
void checkpassword(void);
void insertpassword(char p);



#endif /* KEYPAD_H_ */
