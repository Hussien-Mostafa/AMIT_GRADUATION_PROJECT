

#include "ATMEGA32_REGISTERS.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO.h"
#include "SPI.h"


void SPI_Master_Init(void)
{

	DIO_SetPin_Direction(portB,PIN4,OUTPUT);  //  SS pin output
	DIO_SetPin_Direction(portB,PIN5,OUTPUT);  //  MOSI pin output
	DIO_SetPin_Direction(portB,PIN6,INPUT );   //  MISO pin input
	DIO_SetPin_Direction(portB,PIN7,OUTPUT);  //  SCK pin output

	SPCR = 0x53;

}
void SPI_Slave_Init(void)
{

	DIO_SetPin_Direction(portB,PIN4,INPUT );  //  SS pin output
	DIO_SetPin_Direction(portB,PIN5,INPUT );  //  MOSI pin output
	DIO_SetPin_Direction(portB,PIN6,OUTPUT);  //  MISO pin input
	DIO_SetPin_Direction(portB,PIN7,INPUT );  //  SCK pin output

	SPCR = 0x40;

}

void SPI_Send_Data(U8 Data)
{
	DIO_SetPin_Value(portB,PIN4,LOW);
	SPDR = Data;               // Send Data
	while(GET_BIT(SPSR,7)==0); //wait until SPI interrupt flag = 1 ( Data sent )
}

U8 SPI_Receive_Data(void)
{
	while(GET_BIT(SPSR,7)==0);//wait until SPI interrupt flag = 1 ( Data sent )
	return SPDR ;
}

