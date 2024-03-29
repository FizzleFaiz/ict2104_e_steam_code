///*
// * ov528.h
// *
// *  Created on: 28 Nov 2019
// *      Author: kx
// */
//
//#ifndef DEVICES_OV528_H_
//#define DEVICES_OV528_H_
//#include "Hardware/UART_Driver.h"
//// Command Set
//#define OV528_CMD_INIT     0x01
//#define OV528_CMD_GET_PIC  0x04
//#define OV528_CMD_SNAPSHOT 0x05
//#define OV528_CMD_PKT_SZ   0x06
//#define OV528_CMD_BAUD     0x07
//#define OV528_CMD_RESET    0x08
//#define OV528_CMD_PW_OFF   0x09
//#define OV528_CMD_DATA     0x0a
//#define OV528_CMD_SYNC     0x0d
//#define OV528_CMD_ACK      0x0e
//#define OV528_CMD_NAK      0x0f
//
//
//// JPEG Resolution (OV528_CMD_INIT)
//#define OV528_SIZE_80_60  0x01  // 80x60
//#define OV528_SIZE_OCIF   0x03  // 160x120
//#define OV528_SIZE_CIF    0x05  // 320x240
//#define OV528_SIZE_QVGA   0x05  // 320x240
//#define OV528_SIZE_VGA    0x07  // 640x480
//
//// Picture Type (OV528_CMD_GET_PIC, OV528_CMD_DATA)
//#define OV528_PIC_TYPE_SNAPSHOT     0x01
//#define OV528_PIC_TYPE_PREVIEW      0x02
//#define OV528_PIC_TYPE_JPEG_PREVIEW 0x05
//
//// (OV528_CMD_SNAPSHOT)
//#define OV528_SNAPSHOT_COMPRESSED 0x00
//
//typedef void (*SIZE_FUN)(void* ctx, uint32_t sz);
//typedef void (*WRITE_FUN)(void* ctx, uint8_t *buf, uint16_t len);
//
//#endif /* DEVICES_OV528_H_ */
