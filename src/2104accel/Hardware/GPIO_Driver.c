#include "GPIO_Driver.h"

void GPIO_setAsOutput(uint32_t GPIO_Port, uint16_t pins)
{
    MAP_GPIO_setAsOutputPin(GPIO_Port, pins);
}

void GPIO_setAsInput(uint32_t GPIO_Port, uint16_t pins)
{
    MAP_GPIO_setAsInputPin(GPIO_Port, pins);
}

void GPIO_Output_High(uint32_t GPIO_Port, uint16_t pins)
{
    MAP_GPIO_setOutputHighOnPin(GPIO_Port, pins);
}

void GPIO_Output_Low(uint32_t GPIO_Port, uint16_t pins)
{
    MAP_GPIO_setOutputLowOnPin(GPIO_Port, pins);
}

void GPIO_Interrupt_Edge_High(uint32_t GPIO_Port, uint16_t pins)
{
   MAP_GPIO_interruptEdgeSelect(GPIO_Port, pins,0);
}

void GPIO_Interrupt_Edge_Low(uint32_t GPIO_Port, uint16_t pins)
{
   MAP_GPIO_interruptEdgeSelect(GPIO_Port, pins,1);
}

void GPIO_Interrupt_Enable(uint32_t GPIO_Port, uint16_t pins)
{
    MAP_GPIO_enableInterrupt(GPIO_Port, pins);
}

void GPIO_Interrupt_Disable(uint32_t GPIO_Port, uint16_t pins)
{
    MAP_GPIO_disableInterrupt(GPIO_Port, pins);
}

void GPIO_Clear_Interrupt_Flag(uint32_t GPIO_Port, uint16_t pins)
{
    MAP_GPIO_clearInterruptFlag(GPIO_Port, pins);
}

void GPIO_setAsInput_PullDown(uint32_t GPIO_Port, uint16_t pins)
{
    MAP_GPIO_setAsInputPinWithPullDownResistor(GPIO_Port, pins);
}

void GPIO_setAsInput_PullUp(uint32_t GPIO_Port, uint16_t pins)
{
    MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_Port, pins);
}

uint32_t GPIO_getInterrupt_Status(uint32_t GPIO_Port, uint16_t pins)
{
    return MAP_GPIO_getInterruptStatus(GPIO_Port, pins);
}

uint32_t GPIO_getEnabledInterrupt_Status(uint32_t GPIO_Port)
{
    return MAP_GPIO_getEnabledInterruptStatus(GPIO_Port);
}

uint32_t GPIO_getInputPin_Value(uint32_t GPIO_Port, uint16_t pins)
{
    return MAP_GPIO_getInputPinValue(GPIO_Port, pins);
}
