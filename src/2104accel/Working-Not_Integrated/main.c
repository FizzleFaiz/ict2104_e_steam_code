//#include <Hardware/CS_Driver.h>
//#include <Devices/MSPIO.h>
//#include <Devices/ESP8266.h>
//
///* VCC = 3.3V
// * GND = GND
// * TX = P3.2
// * RX = P3.3
// * RST = P6.1
// * CH_PD = 3.3V */
//
//
///*We are connecting to api.themoviedb.org, ESP8266 can resolve DNS, pretty cool huh!*/
//char HTTP_WebPage[] = "172.30.138.56";
///*HTTP is TCP port 80*/
//char Port[] = "80";
///*Data that will be sent to the HTTP server. This will allow us to query movie data. Get an api key from api.themoviedb.org*/
//char HTTP_Request[] = "GET /team15_wifi_direct/index.php HTTP/1.0\r\n\r\n";
////char HTTP_Request[] = "GET /3/search/movie?api_key=yourkey&query=a+beautiful+mind HTTP/1.0\r\n\r\n";
///*Subtract one to account for the null character*/
//uint32_t HTTP_Request_Size = sizeof(HTTP_Request) - 1;
//char ssid[]= "Kaix";
//char ssidPassword[]= "mybirthday";
//char CWMODE = '3'; //1 for station, 2 for AP, 3 for both station and AP
//
//
///* UART Configuration Parameter. These are the configuration parameters to
// * make the eUSCI A UART module to operate with a 115200 baud rate. These
// * values were calculated using the online calculator that TI provides
// * at:
// * http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSP430BaudRateConverter/index.html
// */
//eUSCI_UART_ConfigV1 UART0Config =
//{
//     EUSCI_A_UART_CLOCKSOURCE_SMCLK,
//     13,
//     0,
//     37,
//     EUSCI_A_UART_NO_PARITY,
//     EUSCI_A_UART_LSB_FIRST,
//     EUSCI_A_UART_ONE_STOP_BIT,
//     EUSCI_A_UART_MODE,
//     EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION
//};
//
///* UART Configuration Parameter. These are the configuration parameters to
// * make the eUSCI A UART module to operate with a 115200 baud rate. These
// * values were calculated using the online calculator that TI provides
// * at:
// * http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSP430BaudRateConverter/index.html
// */
//eUSCI_UART_ConfigV1 UART2Config =
//{
//     EUSCI_A_UART_CLOCKSOURCE_SMCLK,
//     13,
//     0,
//     37,
//     EUSCI_A_UART_NO_PARITY,
//     EUSCI_A_UART_LSB_FIRST,
//     EUSCI_A_UART_ONE_STOP_BIT,
//     EUSCI_A_UART_MODE,
//     EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION
//};
//
//void main(void)
//{
//	MAP_WDT_A_holdTimer();
//
//    /*MSP432 Running at 24 MHz*/
//	CS_Init();
//
//	/*Initialize required hardware peripherals for the ESP8266*/
//	UART_Init(EUSCI_A0_BASE, UART0Config);
//	UART_Init(EUSCI_A2_BASE, UART2Config);
//    GPIO_Init(GPIO_PORT_P6, GPIO_PIN1);
//
//    MAP_Interrupt_enableMaster();
//
//    /*Pointer to ESP8266 global buffer*/
//    char *ESP8266_Data = ESP8266_GetBuffer();
//
//    /*Hard Reset ESP8266*/
//    ESP8266_HardReset();
//    __delay_cycles(48000000);
//    /*flush reset data, we do this because a lot of data received cannot be printed*/
//    UART_Flush(EUSCI_A2_BASE);
//
//    /*Check UART connection to MSP432*/
//    if(!ESP8266_CheckConnection())
//    {
//        MSPrintf(EUSCI_A0_BASE, "Failed MSP432 UART connection\r\n");
//        /*Trap MSP432 if failed connection*/
//        while(1);
//    }
//
//    MSPrintf(EUSCI_A0_BASE, "Nice! We are connected to the MSP432\r\n\r\n");
//
////    MSPrintf(EUSCI_A0_BASE, "Checking available Access Points\r\n\r\n");
//
//    if(!ESP8266_CwMode(CWMODE))
//    {
//        MSPrintf(EUSCI_A0_BASE, "Failed MSP432 CWMODE setting\r\n");
//        while(1);
//    }
//
//    /*Connect to Access Point if necessary here*/
//    if(!ESP8266_ConnectToAP(ssid, ssidPassword))
//    {
//       /*Trap MSP432 we are not connected*/
//       MSPrintf(EUSCI_A0_BASE, "Failed to connect to AP\r\n");
//       while(1);
//    }
//
//}
//
//
