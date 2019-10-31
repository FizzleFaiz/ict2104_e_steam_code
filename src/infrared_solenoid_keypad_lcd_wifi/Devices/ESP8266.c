#include "ESP8266.h"

#define RESET_PIN       GPIO_PIN1
#define RESET_PORT      GPIO_PORT_P6
#define AT              "AT\r\n"
#define AT_RST          "AT+RST\r\n"
#define AT_GMR          "AT+GMR\r\n"
#define AT_GSLP         "AT+GSLP\r\n"
#define ATE             "ATE\r\n"
#define AT_CWMODE       "AT+CWMODE"
#define AT_CWMODECUR    "AT+CWMODE_CUR"
#define AT_CWMODEDEF    "AT+CWMODE_DEF"
#define AT_CWJAP        "AT+CWJAP"
#define AT_CWJAPFLASH   "AT+CWJAP_DEF"
#define AT_CWJAPCURRENT "AT+CWJAP_CUR"
#define AT_CWLAP        "AT+CWLAP\r\n"
#define AT_CWQAP        "AT+CWQAP\r\n"
#define AT_CWLIF        "AT+CWLIF\r\n"
#define AT_CWDHCP       "AT+CWDHCP\r\n"
#define AT_CIPSTAMAC    "AT+CIPSTAMAC\r\n"
#define AT_CIPAPMAC     "AT+CIPAPMAC\r\n"
#define AT_CIPSTA       "AT+CIPSTA\r\n"
#define AT_CIPAP        "AT+CIPAP"
#define AT_CIPSTATUS    "AT+CIPSTATUS\r\n"
#define AT_CIPSTART     "AT+CIPSTART"
#define AT_CIPSEND      "AT+CIPSEND"
#define AT_CIPCLOSE     "AT+CIPSEND\r\n"
#define AT_CIFSR        "AT+CIFSR\r\n"
#define AT_CIPMUX       "AT+CIPMUX"
#define AT_CIPSERVER    "AT+CIPSTO\r\n"
#define AT_CIPMODE      "AT+CIPMODE\r\n"
#define AT_CIPSTO       "AT+CIPSTO\r\n"
#define AT_CIUPDATE     "AT+CIUPDATE\r\n"
#define IPD             "+IPD\r\n"

char ESP8266_Buffer[ESP8266_BUFFER_SIZE];

bool ESP8266_WaitForAnswer(uint32_t Tries)
{
    uint32_t c;
    uint32_t i = 0;

    while(Tries)
    {
        if(UART_Available(EUSCI_A2_BASE)){
            while(UART_Available(EUSCI_A2_BASE)){
                UART_Read(EUSCI_A2_BASE, (uint8_t*)&c, 1);

                if(i > ESP8266_BUFFER_SIZE)
                {
                    return false;
                }
                else
                {
                    ESP8266_Buffer[i++] = c;
                }
            }

            ESP8266_Buffer[i++] = 0;
            return true;
        }
        Tries--;
        __delay_cycles(2400);
    }

    return false;
}

bool ESP8266_CheckBuffer(void){
    if(!ESP8266_WaitForAnswer(ESP8266_RECEIVE_TRIES))
    {
        return false;
    }

    if(strstr(ESP8266_Buffer, "OK") == NULL)
    {
        return false;
    }

    return true;
}

bool ESP8266_CheckConnection(void)
{
    MSPrintf(EUSCI_A2_BASE, AT);
    __delay_cycles(12000);
    return ESP8266_CheckBuffer();
}
bool ESP8266_CwMode(char mode)
{
    /*enable station/ap/both mode for ESP8266*/
    MSPrintf(EUSCI_A2_BASE, "%s=%c\r\n",AT_CWMODECUR,mode);
    __delay_cycles(120000);
    return ESP8266_CheckBuffer();
}

bool ESP8266_AvailableAPs(void)
{
    MSPrintf(EUSCI_A2_BASE, AT_CWLAP);
    __delay_cycles(48000000);
    return ESP8266_CheckBuffer();
}

bool ESP8266_ConnectToAP(char *SSID, char *Password)
{
    MSPrintf(EUSCI_A0_BASE, "%s=\"%s\",\"%s\"\r\n", AT_CWJAP, SSID, Password);
    MSPrintf(EUSCI_A2_BASE, "%s=\"%s\",\"%s\"\r\n", AT_CWJAP, SSID, Password);

    __delay_cycles(48000000);
    return ESP8266_CheckBuffer();
}

bool ESP8266_EnableMultipleConnections(bool Enable)
{
    char c;

    switch(Enable)
    {
    case 0:
        c = '0';
        break;
    case 1:
        c = '1';
        break;
    }

    MSPrintf(EUSCI_A2_BASE, "%s=%c\r\n", AT_CIPMUX, c);

    __delay_cycles(12000000);
    return ESP8266_CheckBuffer();
}

bool ESP8266_EstablishConnection(char ID, uint8_t type, char *address, char *port)
{
    char ct[3];

    switch(type)
    {
    case TCP:
        ct[0] = 'T';
        ct[1] = 'C';
        ct[2] = 'P';
        break;
    case UDP:
        ct[0] = 'U';
        ct[1] = 'D';
        ct[2] = 'P';
        break;
    }

    MSPrintf(EUSCI_A2_BASE, "%s=%c,\"%s\",\"%s\",%s\r\n", AT_CIPSTART, ID, ct, address, port);

    __delay_cycles(24000000);
    return ESP8266_CheckBuffer();
}

bool ESP8266_SendData(char ID, char *Data, uint32_t DataSize)
{
    char size[5];

    ltoa(DataSize, size);
    MSPrintf(EUSCI_A2_BASE, "%s=%c,%s\r\n", AT_CIPSEND, ID, size);

    __delay_cycles(24000000);
    if(!ESP8266_WaitForAnswer(ESP8266_RECEIVE_TRIES))
    {
        return false;
    }

    if(strstr(ESP8266_Buffer, ">") == NULL)
    {
        return false;
    }

    MSPrintf(EUSCI_A2_BASE, Data);

    __delay_cycles(48000000);
    return ESP8266_CheckBuffer();
}

void ESP8266_init(void){
    UART_Init(EUSCI_A0_BASE, UART0Config);
    UART_Init(EUSCI_A2_BASE, UART2Config);
    GPIO_Init(GPIO_PORT_P6, GPIO_PIN1);
    /*Pointer to ESP8266 global buffer*/
    char *ESP8266_Data = ESP8266_GetBuffer();
    /*Hard Reset ESP8266*/
    ESP8266_HardReset();
    __delay_cycles(48000000);
    /*flush reset data, we do this because a lot of data received cannot be printed*/
    UART_Flush(EUSCI_A2_BASE);
    if(!ESP8266_CheckConnection())
        {
            MSPrintf(EUSCI_A0_BASE, "Failed MSP432 UART connection\r\n");
            /*Trap MSP432 if failed connection*/
            while(1);
        }

        MSPrintf(EUSCI_A0_BASE, "Nice! We are connected to the MSP432\r\n\r\n");

    //    MSPrintf(EUSCI_A0_BASE, "Checking available Access Points\r\n\r\n");

        if(!ESP8266_CwMode(CWMODE))
        {
            MSPrintf(EUSCI_A0_BASE, "Failed MSP432 CWMODE setting\r\n");
            while(1);
        }

    //    /*Check available Access Points*/
    //    if(!ESP8266_AvailableAPs())
    //    {
    //        MSPrintf(EUSCI_A0_BASE, "Failed to obtain Access Points\n\r ERROR: %s \r\n", ESP8266_Data);        /*Trap MSP432 if failed to obtain access points*/
    //        while(1);
    //    }
    //
    //    /*Print received Access Points Data to console*/
    //   MSPrintf(EUSCI_A0_BASE, "Got it! Here are the available Access Points: %s\r\n\r\n", ESP8266_Data);

        /*Connect to Access Point if necessary here*/
        if(!ESP8266_ConnectToAP(ssid, ssidPassword))
        {
           /*Trap MSP432 we are not connected*/
           MSPrintf(EUSCI_A0_BASE, "Failed to connect to AP\r\n");
           while(1);
        }


        /*Enable multiple connections, up to 4 according to the internet*/
        if(!ESP8266_EnableMultipleConnections(true))
        {
            MSPrintf(EUSCI_A0_BASE, "Failed to set multiple connections\r\n");
            while(1);
        }

        MSPrintf(EUSCI_A0_BASE, "Multiple connections enabled\r\n\r\n");

        /*Try to establish TCP connection to a HTTP server*/
        if(!ESP8266_EstablishConnection('0', TCP, HTTP_WebPage, Port))
        {
            MSPrintf(EUSCI_A0_BASE, "Failed to connect to: %s\r\nERROR: %s\r\n", HTTP_WebPage, ESP8266_Data);
            while(1);
        }

        MSPrintf(EUSCI_A0_BASE, "Connected to: %s\r\n\r\n", HTTP_WebPage);

        /*Query data to connected HTTP server, in order to do this look for an API and request a key*/
        if(!ESP8266_SendData('0', HTTP_Request, HTTP_Request_Size))
        {
            MSPrintf(EUSCI_A0_BASE, "Failed to send: %s to %s \r\nError: %s\r\n", HTTP_Request, HTTP_WebPage, ESP8266_Data);
            while(1);
        }

        /*We succesfully sent the data to the HTTP server, we are now going to receive a lot of data from the ESP8266 (or depending
         * on what information you are querying, CHANGE ESP8266 BUFFER SIZE AND UARTA2 BUFFER SIZE, OTHERWISE YOU WILL LOSS DATA!!!!!).*/
        MSPrintf(EUSCI_A0_BASE, "Data sent: %s to %s\r\n\r\nESP8266 Data Received: %s\r\n", HTTP_Request, HTTP_WebPage, ESP8266_Data);

}


void ESP8266_Terminal(void)
{
    while(1)
    {
        MSPgets(EUSCI_A0_BASE, ESP8266_Buffer, 128);
        MSPrintf(EUSCI_A2_BASE, ESP8266_Buffer);

        __delay_cycles(48000000);
        if(!ESP8266_WaitForAnswer(ESP8266_RECEIVE_TRIES))
        {
            MSPrintf(EUSCI_A0_BASE, "ESP8266 receive timeout error\r\n");
        }
        else
        {
            MSPrintf(EUSCI_A0_BASE, ESP8266_Buffer);
        }

    }
}

char *ESP8266_GetBuffer(void)
{
    return ESP8266_Buffer;
}

void ESP8266_HardReset(void)
{
    GPIO_Low(RESET_PORT, RESET_PIN);

    __delay_cycles(24000000);

    GPIO_High(RESET_PORT, RESET_PIN);
}
