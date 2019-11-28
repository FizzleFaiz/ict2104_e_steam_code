
#ifndef HARDWARE_SPI_DRIVER_H
#define HARDWARE_SPI_DRIVER_H

#include <ti/devices/msp432p4xx/driverlib/rom.h>
#include <ti/devices/msp432p4xx/driverlib/rom_map.h>
#include <ti/devices/msp432p4xx/driverlib/interrupt.h>
#include <ti/devices/msp432p4xx/driverlib/spi.h>
#include <ti/devices/msp432p4xx/driverlib/gpio.h>
#include <stdint.h>

#define CS_PORT         GPIO_PORT_P4
#define CS_PIN          GPIO_PIN3

int delayInt;

void spi_master_init(uint32_t SPI, eUSCI_SPI_MasterConfig SPIMasterConfig);
uint8_t spi_transmit(uint32_t SPI, uint8_t data);

#endif /* HARDWARE_SPI_DRIVER_H_ */
