#ifndef _DWIN_H_
#define _DWIN_H_

#include <stdint.h>

uint8_t* Sent_To_LCD(uint16_t Address, uint16_t Data);
uint16_t get_address(uint8_t Recieved_Paket[9]);
uint16_t get_value(uint8_t Recieved_Paket[9]);


#endif