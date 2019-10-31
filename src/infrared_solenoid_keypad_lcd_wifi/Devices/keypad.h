/*
 * keypad.h
 *
 *  Created on: 24 Oct 2019
 *      Author: kx
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "msp.h"
#define R1 BIT6
#define R2 BIT6
#define R3 BIT7
#define R4 BIT3
#define C1 BIT1
#define C2 BIT5
#define C3 BIT7


void keypadinit(void);
void keypadrowinit(void);
void keypadcolinit(void);
void keypadrowoutput(void);
void keypadpress(void);
void keypadcol1check(void);
void keypadcol2check(void);
void keypadcol3check(void);
void checkpassword(void);
void insertpassword(char p);



#endif /* KEYPAD_H_ */
