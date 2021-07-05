
#include "STD_TYPES.h"
#include "DIO.h"
#include "ATMEGA32_REGISTERS.h"
#include "util/delay.h"
#include "LCD.h"


void LCD_Init(void)
{
	//RS B1
	DIO_SetPin_Direction(portB, PIN1, OUTPUT);
	//RW B2
	DIO_SetPin_Direction(portB, PIN2, OUTPUT);
	//E B3
	DIO_SetPin_Direction(portB, PIN3, OUTPUT);
	//data lines
	DIO_SetPin_Direction(portA, PIN4, OUTPUT);
	DIO_SetPin_Direction(portA, PIN5, OUTPUT);
	DIO_SetPin_Direction(portA, PIN6, OUTPUT);
	DIO_SetPin_Direction(portA, PIN7, OUTPUT);

	_delay_ms(100);

	
	LCD_Write_Command(0x02);//send for 4 bit initialization of LCD
	LCD_Write_Command(0x28);//2 line, 5*7 matrix in 4-bit mode
	LCD_Write_Command(0x0C);//display on, curser of
	LCD_Write_Command(0x06);//shift curser
	LCD_Write_Command(0x01);//clear Display
}

void LCD_Write_Command(U8 Command)
{
	//RS low
	DIO_SetPin_Value(portB, PIN1, LOW);
	//RW low
	DIO_SetPin_Value(portB, PIN2, LOW);
	//Sending highest nibble
	PORTA_REG=(PORTA_REG&0x0F)|(Command&0xF0);
	DIO_SetPin_Value(portB, PIN3, HIGH);
	_delay_ms(1);
	DIO_SetPin_Value(portB, PIN3, LOW);
	_delay_ms(5);


	PORTA_REG=(PORTA_REG&0x0F)|(Command<<4);
	DIO_SetPin_Value(portB, PIN3, HIGH);
	_delay_ms(1);
	DIO_SetPin_Value(portB, PIN3, LOW);
	_delay_ms(5);
}

void LCD_Write_Data(U8 Data)
{
	//RS low
	DIO_SetPin_Value(portB, PIN1, HIGH);
	//RW high
	DIO_SetPin_Value(portB, PIN2, LOW);
	//Sending Highest nibble
	PORTA_REG=(PORTA_REG&0x0F)|(Data&0xF0);
	DIO_SetPin_Value(portB, PIN3, HIGH);
	_delay_ms(1);
	DIO_SetPin_Value(portB, PIN3, LOW);
	_delay_ms(5);


	PORTA_REG=(PORTA_REG&0x0F)|(Data<<4);
	DIO_SetPin_Value(portB, PIN3, HIGH);
	_delay_ms(1);
	DIO_SetPin_Value(portB, PIN3, LOW);
	_delay_ms(5);
}

void LCD_Write_Word(U8 *Word)
{
	U8 index=0;
	while(Word[index]!='\0')
	{
		LCD_Write_Data(Word[index]);
		index++;
	}
}

void LCD_Clear_Screen(void)
{
	LCD_Write_Command(0x01);
}

