#ifndef HARDWARE_GPIO_DRIVER_H_
#define HARDWARE_GPIO_DRIVER_H_

#include <ti/devices/msp432p4xx/driverlib/rom.h>
#include <ti/devices/msp432p4xx/driverlib/rom_map.h>
#include <ti/devices/msp432p4xx/driverlib/gpio.h>

void GPIO_setAsInput(uint32_t GPIO_Port, uint16_t pins);            //PxDIR
void GPIO_setAsOutput(uint32_t GPIO_port, uint16_t pins);           //PxDIR
void GPIO_Output_High(uint32_t GPIO_Port, uint16_t pins);           //PxOUT
void GPIO_Output_Low(uint32_t GPIO_Port, uint16_t pins);            //PxOUT
void GPIO_Interrupt_Edge_High(uint32_t GPIO_Port, uint16_t pins);   //PxIES
void GPIO_Interrupt_Edge_Low(uint32_t GPIO_Port, uint16_t pins);    //PxIES
void GPIO_Interrupt_Enable(uint32_t GPIO_Port, uint16_t pins);      //PxIE
void GPIO_Interrupt_Disable(uint32_t GPIO_Port, uint16_t pins);     //PxIE
void GPIO_Clear_Interrupt_Flag(uint32_t GPIO_Port, uint16_t pins);  //PxIFG=0
void GPIO_setAsInput_PullDown(uint32_t GPIO_Port, uint16_t pins);   //PxREN = 1, PxOUT = 0
void GPIO_setAsInput_PullUp(uint32_t GPIO_Port, uint16_t pins);     //PxREN = 1, PxOUt = 1
uint32_t GPIO_getInterrupt_Status(uint32_t GPIO_Port, uint16_t pins);     //PxIFG(get)
uint32_t GPIO_getInputPin_Value(uint32_t GPIO_Port, uint16_t pins);
uint32_t GPIO_getEnabledInterrupt_Status(uint32_t GPIO_Port);


#endif /* HARDWARE_GPIO_DRIVER_H_ */
