/*
 * keypad.c
 *
 *  Created on: 24 Oct 2019
 *      Author: kx
 */
#include "keypad.h"
#include "relay.h"
#include "infrared.h"

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

char str[] = "123456";

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
    //if password correct, run relay,
        //if password incorrect, print incorrect and reset password to 0
        //if password is reverse order, send alarm
        //if ((password[MAXLENGTH-1] != '\0') || (password[MAXLENGTH-1] != ' '))

    //password fully populated
    if ((password[MAXLENGTH-1] != '\0'))
        {
            //should check password first
            int i = 0;
            int errCheck = 0;
            int length = MAXLENGTH;
            int reverseCheck = 1;

            for (i = 0; i < MAXLENGTH; i++)
            {
                if(!(password[i] == str[--length])){
                    reverseCheck = 0;
                }

                if(password[i] != str[i]){
                    errCheck = 1;
                }

            }
            if (reverseCheck){
                gotoXy(0,1);
                prints("success reverse");
                gotoXy(0,1);
                prints("                 ");
            }
            else if (errCheck == 1){
                gotoXy(0,1);
                prints("Wrong Password!");
                gotoXy(0,1);
                prints("                 ");
            }
            else{
                //unlock door
                gotoXy(0,1);
                prints("Unlocked");
                gotoXy(0,1);
                prints("                 ");
                infrareddetect();
            }
            clearPassword();
        }
    }
void clearPassword(void){
    int i = 0;
    for (i=0; i < MAXLENGTH; i++){
        password[i] = '\0';
    }
}

void keypadrowinit(void){
    // set output PINs - rows
    //row 1
    //P5DIR |= R1;
    GPIO_setAsOutput(R1_PORT, R1_PIN);
    //row 2
    //P6DIR |= R2;
    GPIO_setAsOutput(R2_PORT, R2_PIN);
    //row 3
    //P6DIR |= R3;
    GPIO_setAsOutput(R3_PORT, R3_PIN);
    //row 4
    //P2DIR |= R4;
    GPIO_setAsOutput(R4_PORT, R4_PIN);

    keypadrowoutput();
}

void keypadcolinit(void){
    // set input PINs - columns
    //col 1
    //P5DIR &= ~C1;
    //GPIO_setAsInput(C1_PORT, C1_PIN);
    //col 2
    //P3DIR &= ~C2;
    //GPIO_setAsInput(C2_PORT, C2_PIN);
    //col 3
    //P3DIR &= ~C3;
    //GPIO_setAsInput(C3_PORT, C3_PIN);

    // Active High Inputs
    //P5REN |= C1;
    //P5OUT &= ~C1;
    GPIO_setAsInput(C1_PORT,C1_PIN);
    GPIO_setAsInput_PullUp(C1_PORT, C1_PIN);
    GPIO_setAsInput_PullDown(C1_PORT, C1_PIN);

    //P3REN |= C2;
    //P3OUT &= ~C2;
    GPIO_setAsInput(C2_PORT,C2_PIN);
    GPIO_setAsInput_PullUp(C2_PORT, C2_PIN);
    GPIO_setAsInput_PullDown(C2_PORT, C2_PIN);
    //P3REN |= C3;
    //P3OUT &= ~C3;
    GPIO_setAsInput(C3_PORT,C3_PIN);
    GPIO_setAsInput_PullUp(C3_PORT, C3_PIN);
    GPIO_setAsInput_PullDown(C3_PORT, C3_PIN);
}

void keypadrowoutput(void){
    /*
        P5OUT |= R1;
        P6OUT |= R2;
        P6OUT |= R3;
        P2OUT |= R4;
        */
    GPIO_Output_High(R1_PORT, R1_PIN);
    GPIO_Output_High(R2_PORT, R2_PIN);
    GPIO_Output_High(R3_PORT, R3_PIN);
    GPIO_Output_High(R4_PORT, R4_PIN);
}


void keypadcolcheck(uint32_t KEYINPUT_PORT, uint16_t KEYINPUT_PIN, char R1, char R2, char R3, char R4)
{
    GPIO_Output_Low(R1_PORT, R1_PIN);
    GPIO_STATUS = GPIO_getInputPin_Value(KEYINPUT_PORT, KEYINPUT_PIN);
    if (!GPIO_STATUS)
    {
        insertpassword(R1);
    }
    GPIO_Output_High(R1_PORT, R1_PIN);
    GPIO_Output_Low(R2_PORT, R2_PIN);
    GPIO_STATUS = GPIO_getInputPin_Value(KEYINPUT_PORT, KEYINPUT_PIN);
    if (!GPIO_STATUS)
    {
        insertpassword(R2);
    }
    GPIO_Output_High(R2_PORT, R2_PIN);
    GPIO_Output_Low(R3_PORT, R3_PIN);
    GPIO_STATUS = GPIO_getInputPin_Value(KEYINPUT_PORT, KEYINPUT_PIN);
    if (!GPIO_STATUS)
    {
        insertpassword(R3);
    }
    GPIO_Output_High(R3_PORT, R3_PIN);
    GPIO_Output_Low(R4_PORT, R4_PIN);
    GPIO_STATUS = GPIO_getInputPin_Value(KEYINPUT_PORT, KEYINPUT_PIN);
    if (!GPIO_STATUS)
    {
        insertpassword(R4);
    }
    GPIO_Output_High(R4_PORT, R4_PIN);
    while(GPIO_STATUS)
    {
        GPIO_STATUS = GPIO_getInputPin_Value(KEYINPUT_PORT, KEYINPUT_PIN);
    }
}


void keypadinit(void){
    keypadrowinit();
    keypadcolinit();
}

void keypadpress(void){ //somehow PORT2.3 receive input 1, need to check what is active pull up.
    GPIO_STATUS = GPIO_getInputPin_Value(C1_PORT, C1_PIN);
    if (GPIO_STATUS)
    {
        keypadcolcheck(C1_PORT, C1_PIN, R1C1, R2C1, R3C1, R4C1);
    }
    GPIO_STATUS = GPIO_getInputPin_Value(C2_PORT, C2_PIN);
    if (GPIO_STATUS)
    {
        keypadcolcheck(C2_PORT, C2_PIN, R1C2, R2C2, R3C2, R4C2);
    }
    GPIO_STATUS = GPIO_getInputPin_Value(C3_PORT, C3_PIN);
    if (GPIO_STATUS)
    {
        keypadcolcheck(C3_PORT, C3_PIN, R1C3, R2C3, R3C3, R4C3);
    }
    gotoXy(0,1); //prints at bottom line
    prints(password);
    checkpassword();
}

//void keypadcol1check(void){
//        //P5OUT &= ~R1;
//        GPIO_Output_Low(R1_PORT, R1_PIN);
//        //if((P5IN & C1)!=C1)
//        if (!GPIO_getInputPin_Value(C1_PORT, C1_PIN))
//        {
//            insertpassword(R1C1);
//        }
//
//        //P5OUT |= R1;
//        GPIO_Output_High(R1_PORT, R1_PIN);
//        //P6OUT &= ~R2;
//        GPIO_Output_Low(R2_PORT, R2_PIN);
//        //if((P5IN & C1)!=C1)
//        if (!GPIO_getInputPin_Value(C1_PORT, C1_PIN))
//        {
//            insertpassword(R2C1);
//        }
//        //P6OUT |= R2;
//        GPIO_Output_High(R2_PORT, R2_PIN);
//        //P6OUT &= ~R3;
//        GPIO_Output_Low(R3_PORT, R3_PIN);
//        //if((P5IN & C1)!=C1)
//        if (!GPIO_getInputPin_Value(C1_PORT, C1_PIN))
//        {
//            insertpassword(R3C1);
//        }
//        //P6OUT |= R3;
//        GPIO_Output_High(R3_PORT, R3_PIN);
//        //P2OUT &= ~R4;
//        GPIO_Output_Low(R4_PORT, R4_PIN);
//        //if((P5IN & C1)!=C1)
//        if (!GPIO_getInputPin_Value(C1_PORT, C1_PIN))
//        {
//            insertpassword(R4C1);
//        }
//        //P2OUT |= R4;
//        GPIO_Output_High(R4_PORT, R4_PIN);
//        while(GPIO_getInputPin_Value(C1_PORT, C1_PIN));
//}
//
//void keypadcol2check(void){
//        //P5OUT &= ~R1;
//        GPIO_Output_Low(R1_PORT, R1_PIN);
//        //if((P3IN & C2)!=C2)
//        if (!GPIO_getInputPin_Value(C2_PORT, C2_PIN))
//        {
//            insertpassword(R1C2);
//        }
//        //P5OUT |= R1;
//        GPIO_Output_High(R1_PORT, R1_PIN);
//        //P6OUT &= ~R2;
//        GPIO_Output_Low(R2_PORT, R2_PIN);
//        //if((P3IN & C2)!=C2)
//        if (!GPIO_getInputPin_Value(C2_PORT, C2_PIN))
//        {
//            insertpassword(R2C2);
//        }
//        //P6OUT |= R2;
//        GPIO_Output_High(R2_PORT, R2_PIN);
//        //P6OUT &= ~R3;
//        GPIO_Output_Low(R3_PORT, R3_PIN);
//        //if((P3IN & C2)!=C2)
//        if (!GPIO_getInputPin_Value(C2_PORT, C2_PIN))
//        {
//            insertpassword(R3C2);
//        }
//        //P6OUT |= R3;
//        GPIO_Output_High(R3_PORT, R3_PIN);
//        //P2OUT &= ~R4;
//        GPIO_Output_Low(R4_PORT, R4_PIN);
//        //if((P3IN & C2)!=C2)
//        if (!GPIO_getInputPin_Value(C2_PORT, C2_PIN))
//        {
//            insertpassword(R4C2);
//        }
//        //P2OUT |= R4;
//        GPIO_Output_High(R4_PORT, R4_PIN);
//        while(GPIO_getInputPin_Value(C2_PORT, C2_PIN));
//}
//
//void keypadcol3check(void){
//        //P5OUT &= ~R1;
//        GPIO_Output_Low(R1_PORT, R1_PIN);
//        //if((P3IN & C3)!=C3)
//        if (!GPIO_getInputPin_Value(C3_PORT, C3_PIN))
//        {
//            insertpassword(R1C3);
//        }
//        //P5OUT |= R1;
//        GPIO_Output_High(R1_PORT, R1_PIN);
//        //P6OUT &= ~R2;
//        GPIO_Output_Low(R2_PORT, R2_PIN);
//        //if((P3IN & C3)!=C3)
//        if (!GPIO_getInputPin_Value(C3_PORT, C3_PIN))
//        {
//            insertpassword(R2C3);
//        }
//        //P6OUT |= R2;
//        GPIO_Output_High(R2_PORT, R2_PIN);
//        //P6OUT &= ~R3;
//        GPIO_Output_Low(R3_PORT, R3_PIN);
//        //if((P3IN & C3)!=C3)
//        if (!GPIO_getInputPin_Value(C3_PORT, C3_PIN))
//        {
//            insertpassword(R3C3);
//        }
//        //P6OUT |= R3;
//        GPIO_Output_High(R3_PORT, R3_PIN);
//        //P2OUT &= ~R4;
//        GPIO_Output_Low(R4_PORT, R4_PIN);
//        //if((P3IN & C3)!=C3)
//        if (!GPIO_getInputPin_Value(C3_PORT, C3_PIN))
//        {
//            insertpassword(R4C3);
//        }
//        //P2OUT |= R4;
//        GPIO_Output_High(R4_PORT, R4_PIN);
//        while(GPIO_getInputPin_Value(C3_PORT, C3_PIN));
//}


