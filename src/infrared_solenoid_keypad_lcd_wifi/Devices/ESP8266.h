#ifndef DEVICES_ESP8266_H_
#define DEVICES_ESP8266_H_

#include <string.h>
#include <stdlib.h>
#include <Hardware/GPIO_Driver.h>
#include <Devices/MSPIO.h>

/* VCC = 3.3V
 * GND = GND
 * TX = P3.2
 * RX = P3.3
 * RST = P6.1
 * CH_PD = 3.3V */


/*We are connecting to api.themoviedb.org, ESP8266 can resolve DNS, pretty cool huh!*/
char HTTP_WebPage[] = "api.themoviedb.org";
/*HTTP is TCP port 80*/
char Port[] = "80";
/*Data that will be sent to the HTTP server. This will allow us to query movie data. Get an api key from api.themoviedb.org*/
char HTTP_Request[] = "GET /3/search/movie?api_key=yourkey&query=a+beautiful+mind HTTP/1.0\r\n\r\n";
/*Subtract one to account for the null character*/
uint32_t HTTP_Request_Size = sizeof(HTTP_Request) - 1;
char ssid[]= "Kaix";
char ssidPassword[]= "mybirthday";
char CWMODE = '3'; //1 for station, 2 for AP, 3 for both station and AP

#define ESP8266_BUFFER_SIZE     2048
#define ESP8266_RECEIVE_TRIES   10

#define TCP                     0
#define UDP                     1

bool ESP8266_CheckConnection(void);
bool ESP8266_CwMode(char mode);
bool ESP8266_AvailableAPs(void);
bool ESP8266_ConnectToAP(char *SSID, char *Password);
bool ESP8266_EstablishConnection(char ID, uint8_t type, char *address, char *port);
bool ESP8266_EnableMultipleConnections(bool Enable);
bool ESP8266_SendData(char ID, char *Data, uint32_t DataSize);

void ESP8266_init(void);
void ESP8266_SendATCommand(char *ATcommand);
void ESP8266_Terminal(void);
char *ESP8266_GetBuffer(void);
void ESP8266_HardReset(void);

/* UART Configuration Parameter. These are the configuration parameters to
 * make the eUSCI A UART module to operate with a 115200 baud rate. These
 * values were calculated using the online calculator that TI provides
 * at:
 * http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSP430BaudRateConverter/index.html
 */
eUSCI_UART_ConfigV1 UART0Config =
{
     EUSCI_A_UART_CLOCKSOURCE_SMCLK,
     13,
     0,
     37,
     EUSCI_A_UART_NO_PARITY,
     EUSCI_A_UART_LSB_FIRST,
     EUSCI_A_UART_ONE_STOP_BIT,
     EUSCI_A_UART_MODE,
     EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION
};

/* UART Configuration Parameter. These are the configuration parameters to
 * make the eUSCI A UART module to operate with a 115200 baud rate. These
 * values were calculated using the online calculator that TI provides
 * at:
 * http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSP430BaudRateConverter/index.html
 */
eUSCI_UART_ConfigV1 UART2Config =
{
     EUSCI_A_UART_CLOCKSOURCE_SMCLK,
     13,
     0,
     37,
     EUSCI_A_UART_NO_PARITY,
     EUSCI_A_UART_LSB_FIRST,
     EUSCI_A_UART_ONE_STOP_BIT,
     EUSCI_A_UART_MODE,
     EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION
};

#endif /* DEVICES_ESP8266_H_ */
