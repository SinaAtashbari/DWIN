#include "DWIN.h"

uint8_t* Sent_To_LCD(uint16_t Address, uint16_t Data)
{
    static uint8_t send_paket[8];
	
    send_paket[0] = 0x5A;
    send_paket[1] = 0xA5;
    send_paket[2] = 0x05;
    send_paket[3] = 0x82;
    send_paket[4] = (Address >> 8);
    send_paket[5] = (Address & 0xFF);
    send_paket[6] = (Data >> 8);
    send_paket[7] = (Data & 0xFF);  
    return send_paket;
}

uint16_t get_address(uint8_t Recieved_Paket[9])
{
	uint16_t add;
	if(Recieved_Paket[0]==0x5A && Recieved_Paket[1]==0xA5 && Recieved_Paket[2]==0x06 && Recieved_Paket[3]==0x83)
	{
		add = ( ( (uint16_t)Recieved_Paket[4] << 8 ) | Recieved_Paket[5]);
		return add ;
	}
	else
	{
		return 0XFFEE;
	}
	
}

uint16_t get_value(uint8_t Recieved_Paket[9])
{
	uint16_t val;
	if(Recieved_Paket[0]==0x5A && Recieved_Paket[1]==0xA5 && Recieved_Paket[2]==0x06 && Recieved_Paket[3]==0x83)
	{
		val= ( ( (uint16_t)Recieved_Paket[7] << 8 ) | Recieved_Paket[8]);
		return val;
	}
	else
	{
		return 0XEEFF;
	}

}

