/*
 * keypad.c
 *
 *  Created on: 24 Oct 2019
 *      Author: kx
 */
#include "lcd16.h"
#include "keypad.h"
#define MAXLENGTH 6

char R1C1 = '1';
char R1C2 = '2';
char R1C3 = '3';
char R2C1 = '4';
char R2C2 = '5';
char R2C3 = '6';
char R3C1 = '7';
char R3C2 = '8';
char R3C3 = '9';
char R4C1 = '*';
char R4C2 = '0';
char R4C3 = '#';
char password[MAXLENGTH];

void insertpassword(char p){
    int i;
    for (i = 0; i < MAXLENGTH; i++)
    {
        //if ((password[i] == '\0') || (password[i] == ' '))
        if ((password[i] == '\0'))
        {
            password[i] = p;
            break;
        }
    }
}

void checkpassword(void){
    //if ((password[MAXLENGTH-1] != '\0') || (password[MAXLENGTH-1] != ' '))
    if ((password[MAXLENGTH-1] != '\0'))
    {
        //should check password first
        int i = 0;
        for (i = 0; i < MAXLENGTH; i++)
        {
            password[i] = ' ';
        }
        gotoXy(0,1);
        prints(password);
    }
}

void keypadrowinit(void){
    // set output PINs - rows
    //row 1
    P5DIR |= R1;
    //row 2
    P6DIR |= R2;
    //row 3
    P6DIR |= R3;
    //row 4
    P2DIR |= R4;
}

void keypadcolinit(void){
    // set input PINs - columns
    //col 1
    P5DIR &= ~C1;
    //col 2
    P3DIR &= ~C2;
    //col 3
    P3DIR &= ~C3;

    // Active High Inputs
    P5REN |= C1;
    P5OUT &= ~C1;

    P3REN |= C2;
    P3OUT &= ~C2;

    P3REN |= C3;
    P3OUT &= ~C3;
}

void keypadrowoutput(void){
    P5OUT |= R1;
    P6OUT |= R2;
    P6OUT |= R3;
    P2OUT |= R4;
}

void keypadcol1check(void){
        P5OUT &= ~R1;
        if((P5IN & C1)!=C1)
        {
            insertpassword(R1C1);
            P5OUT |= R1;
        }
        P6OUT &= ~R2;
        if((P5IN & C1)!=C1)
        {
            insertpassword(R2C1);
            P6OUT |= R2;
        }
        P6OUT &= ~R3;
        if((P5IN & C1)!=C1)
        {
            insertpassword(R3C1);
            P6OUT |= R3;
        }
        P2OUT &= ~R4;
        if((P5IN & C1)!=C1)
        {
            insertpassword(R4C1);
            P2OUT |= R4;
        }
        while((P5IN & C1)==C1);
}

void keypadcol2check(void){
        P5OUT &= ~R1;
        if((P3IN & C2)!=C2)
        {
            insertpassword(R1C2);
            P5OUT |= R1;
        }
        P6OUT &= ~R2;
        if((P3IN & C2)!=C2)
        {
            insertpassword(R2C2);
            P6OUT |= R2;
        }
        P6OUT &= ~R3;
        if((P3IN & C2)!=C2)
        {
            insertpassword(R3C2);
            P6OUT |= R3;
        }
        P2OUT &= ~R4;
        if((P3IN & C2)!=C2)
        {
            insertpassword(R4C2);
            P2OUT |= R4;
        }
        while((P3IN & C2)==C2);
}

void keypadcol3check(void){
        P5OUT &= ~R1;
        if((P3IN & C3)!=C3)
        {
            insertpassword(R1C3);
            P5OUT |= R1;
        }
        P6OUT &= ~R2;
        if((P3IN & C3)!=C3)
        {
            insertpassword(R2C3);
            P6OUT |= R2;
        }
        P6OUT &= ~R3;
        if((P3IN & C3)!=C3)
        {
            insertpassword(R3C3);
            P6OUT |= R3;
        }
        P2OUT &= ~R4;
        if((P3IN & C3)!=C3)
        {
            insertpassword(R4C3);
            P2OUT |= R4;
        }
        while((P3IN & C3)==C3);
}

void keypadinit(void){
    keypadrowinit();
    keypadcolinit();
}

void keypadpress(void){
    //refresh rows
    keypadrowoutput();

    if ((P5IN & C1) == C1)
    {
        keypadcol1check();
    }
    else if ((P3IN & C2) == C2)
    {
        keypadcol2check();
    }
    else if ((P3IN & C3) == C3)
    {
        keypadcol3check();
    }
    gotoXy(0,1); //prints at bottom line
    prints(password);
    //checkpassword();
}


