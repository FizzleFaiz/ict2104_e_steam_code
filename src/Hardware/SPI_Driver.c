#include <Hardware/SPI_Driver.h>
#include <Hardware/GPIO_Driver.h>



void spi_master_init(uint32_t SPI_Master, eUSCI_SPI_MasterConfig SPIMasterConfig)
{

    //Set CLK, MISO, MOSI
    switch(SPI_Master)
    {
        case EUSCI_B3_SPI_BASE:
            //Set CS
            GPIO_setAsOutput(CS_PORT, CS_PIN);
            GPIO_Output_Low(CS_PORT, CS_PIN);

            /* Configuring SPI in 3-wire master mode & enabling it & interrupts */
            GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P10,  GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);
            MAP_SPI_initMaster(SPI_Master, &SPIMasterConfig);
            MAP_SPI_disableModule(SPI_Master);
            MAP_SPI_enableInterrupt(SPI_Master, EUSCI_B_SPI_RECEIVE_INTERRUPT);
            MAP_Interrupt_enableInterrupt(INT_EUSCIB3);
            MAP_Interrupt_enableSleepOnIsrExit();
            /* Delaying waiting for the module to initialize */
            for(delayInt = 0;delayInt<100;delayInt++){}
            break;
        /*Add more UART modules initialization modules here*/
        default:
            break;
    }
}

uint8_t spi_transmit(uint32_t SPI_Master,uint8_t data)
{
    MAP_SPI_enableModule(SPI_Master); //start eUSCI
	MAP_GPIO_setOutputHighOnPin(CS_PORT, CS_PIN); //start CS
	while (!(SPI_getInterruptStatus(SPI_Master,EUSCI_B_SPI_TRANSMIT_INTERRUPT)));//only false when interrupt status is set, UCxTXBUF is ready for new data
	SPI_transmitData(SPI_Master, data);

	while (!(SPI_getInterruptStatus(SPI_Master, EUSCI_B_SPI_RECEIVE_INTERRUPT)));//when interrupt is set, finished TX/RX operation
	return SPI_receiveData(SPI_Master);
}

