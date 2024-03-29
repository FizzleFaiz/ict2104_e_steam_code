//#ifndef _DEVICES_MFRC522_H_
//#define _DEVICES_MFRC522_H_
//
//#include <stdint.h>
//#include "Devices/mfrc522_cmd.h"
//#include "Devices/mfrc522_reg.h"
//#include "Hardware/SPI_Driver.h"
//
//#define CARD_FOUND		1
//#define CARD_NOT_FOUND	2
//#define ERROR			3
//
//#define MAX_LEN			16
//
////Card types
//#define Mifare_UltraLight 	0x4400
//#define Mifare_One_S50		0x0400
//#define Mifare_One_S70		0x0200
//#define Mifare_Pro_X		0x0800
//#define Mifare_DESFire		0x4403
//
//// Mifare_One card command word
//#define PICC_REQIDL          0x26               // find the antenna area does not enter hibernation
//#define PICC_REQALL          0x52               // find all the cards antenna area
//#define PICC_ANTICOLL        0x93               // anti-collision
//#define PICC_SElECTTAG       0x93               // election card
//#define PICC_AUTHENT1A       0x60               // authentication key A
//#define PICC_AUTHENT1B       0x61               // authentication key B
//#define PICC_READ            0x30               // Read Block
//#define PICC_WRITE           0xA0               // write block
//#define PICC_DECREMENT       0xC0               // debit
//#define PICC_INCREMENT       0xC1               // recharge
//#define PICC_RESTORE         0xC2               // transfer block data to the buffer
//#define PICC_TRANSFER        0xB0               // save the data in the buffer
//#define PICC_HALT            0x50               // Sleep
//
//void mfrc522_init();
//void mfrc522_reset();
//void mfrc522_write(uint8_t reg, uint8_t data);
//uint8_t mfrc522_read(uint8_t reg);
//uint8_t	mfrc522_request(uint8_t req_mode, uint8_t * tag_type);
//uint8_t mfrc522_to_card(uint8_t cmd, uint8_t *send_data, uint8_t send_data_len, uint8_t *back_data, uint32_t *back_data_len);
//uint8_t mfrc522_get_card_serial(uint8_t * serial_out);
//
//#endif
