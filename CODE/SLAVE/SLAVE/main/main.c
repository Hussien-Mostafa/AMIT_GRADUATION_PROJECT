/*
 *  MASTER
 *  Author: HUSSIEN MOSTAFA
 */ 

#include "ATMEGA32_REGISTERS.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI.h"
#include "LED.h"
#include <util/delay.h>

#define    ROOM1_LIGHT_ON           1
#define    ROOM1_LIGHT_OFF          2
#define    ROOM2_LIGHT_ON           3
#define    ROOM2_LIGHT_OFF          4
#define    TV_ONN                   5
#define    TV_OF                    6
#define    AIR_CONDITIONER_ONN      7
#define    AIR_CONDITIONER_OF       8


int main(void)
{
	
	SPI_Slave_Init();
	LED1_INIT();
	LED2_INIT();
	TV_INIT();
	AIR_CONDITIONER_INIT();
	
    while(1)
    {
		switch(SPI_Receive_Data())
		{
			case ROOM1_LIGHT_ON       : LED1_ON() ;                 break;
			case ROOM1_LIGHT_OFF      : LED1_OFF();                 break;
			
			case ROOM2_LIGHT_ON       : LED2_ON() ;                 break;
			case ROOM2_LIGHT_OFF      : LED2_OFF();                 break;
			
			case TV_ONN               : TV_ON()   ;                 break;
			case TV_OF                : TV_OFF()  ;                 break;
			
			case AIR_CONDITIONER_ONN  : AIR_CONDITIONER_ON();       break;
			case AIR_CONDITIONER_OF   : AIR_CONDITIONER_OFF();      break;
		}

    }
}