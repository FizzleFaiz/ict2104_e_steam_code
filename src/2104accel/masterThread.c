/*
 * Copyright (c) 2016-2019, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ======== mainThread ========
 */

#include "msp.h"
#include "accel.h"

#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>

/* Driver Header files */
#include <ti/drivers/I2C.h>

/* Driver configuration */
#include "ti_drivers_config.h"

#include <math.h>

I2C_Handle i2c;
I2C_Params i2cParams;
double x,y,z;
int errorCount;

void *mainThread(void *arg0)
{
    I2C_init();
    I2C_Params_init(&i2cParams);
    i2cParams.bitRate = I2C_100kHz;
    i2c = I2C_open(CONFIG_I2C_0, &i2cParams);

    P1DIR = BIT0; /* Set LED1.0 as output pin */
    P2DIR = BIT1; /* Set LED2.1 (GREEN) as output pin */

    /* Initialize MPU6050 Device */
    writeByte(); /* Clear sleep mode bit (6). Enable all sensors */

    while(1)
    {
        errorCount = 0;
        int16_t* accelData = readAccelData();
        x = (double)((accelData[0] * 1.0) / 2048.0);
        y = (double)((accelData[1] * 1.0) / 2048.0);
        z = (double)((accelData[2] * 1.0) / 2048.0);

        /* Print Accel values */
        //printf("ACCELEROMETER\t");
        //printf("X= %5d\t", accelData[0]);
        //printf("Y= %5d\t", accelData[1]);
        //printf("Z= %5d\n", accelData[2]);
        //printf("-----------------------------------------------------------------------\n");

        if ((x > -1.0 && x < 1.0) && (y > -1.0 && y < 1.0)){  /* Simulate if structural integrity upright */
                P1OUT = ~BIT0;
                P2OUT |= BIT1;  /* Stable indicator */
        }
/*        if ((x < -1.0 && x > 1.0) || (y < -1.0 && y > 1.0)){
            if (z > 5.6 && z < 6){
                P1OUT = ~BIT0;
                P2OUT |= BIT1;   Stable indicator
            }
        }*/
        else{
            P1OUT |= BIT0;   /* Damage indicator */
            P2OUT = ~BIT1;
        }
        delayMs(10000);
    }
    I2C_close(i2c);
}

void delayMs(int n){
    int i;

    TIMER32_1->LOAD = 3000 - 1; /* reload with number of clocks per millisecond */
    /* no prescaler, periodic wrapping mode, disable interrupt, 32-bit timer. */
    TIMER32_1->CONTROL = 0xC2;

    for(i = 0; i < n; i++) {
        while((TIMER32_1->RIS & 1) == 0); /* wait until the RAW_IFG is set */
        TIMER32_1->INTCLR = 0;            /* clear RAW_IFG flag */
    }
}
