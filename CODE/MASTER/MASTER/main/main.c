/*
 *  MASTER
 *  Author: HUSSIEN MOSTAFA
 */ 

#include "ATMEGA32_REGISTERS.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI.h"
#include "UART.h"
#include "LCD.h"
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
	
		LCD_Init();
		SPI_Master_Init();
		UART_Init();
		
		_delay_ms(10);
		LCD_Write_Command(0x80);//the LCD command will be Force cursor to the beginning ( 1st line)
		LCD_Write_Word("   WELCOME.   ");
		_delay_ms(20000);
		LCD_Clear_Screen();//the LCD command will be the clear LCD screen
		_delay_ms(10);
		
		LCD_Write_Command(0x80);//the LCD command will be Force cursor to the beginning ( 1st line)
		LCD_Write_Word("CHOOSE FROM THE");
		LCD_Write_Command(0xc0);//the LCD command will be Force cursor to the beginning ( 2st line)
		LCD_Write_Word("FOLLOWING MENUE");
		_delay_ms(40000);
		LCD_Clear_Screen();//the LCD command will be the clear LCD screen
		_delay_ms(10);
		

		
		
		
		
			
    while(1)
    {
		
		LCD_Write_Command(0x80);//the LCD command will be Force cursor to the beginning ( 1st line)
		LCD_Write_Word("1)ROOM LIGHTS. ");
		LCD_Write_Command(0xc0);//the LCD command will be Force cursor to the beginning ( 2st line)
		LCD_Write_Word("2)HOME DEVICES. ");
		
        switch (UART_Recieve())
        {
			
			case '1': // if the user choose lights
			LCD_Clear_Screen();//the LCD command will be the clear LCD screen
			_delay_ms(10);
			
			LCD_Write_Command(0x80);//the LCD command will be Force cursor to the beginning ( 1st line)
	        LCD_Write_Word("1)ROOM 1   ");
	        LCD_Write_Command(0xc0);//the LCD command will be Force cursor to the beginning ( 2st line)
         	LCD_Write_Word("2)ROOM 2   ");
			
			switch (UART_Recieve())
			{
				
				case '1':// if the user choose room1
				{
					
				LCD_Clear_Screen();//the LCD command will be the clear LCD screen
				_delay_ms(10);
				
				LCD_Write_Command(0x80);//the LCD command will be Force cursor to the beginning ( 1st line)
				LCD_Write_Word("1) ON   ");
				LCD_Write_Command(0xc0);//the LCD command will be Force cursor to the beginning ( 2st line)
				LCD_Write_Word("2) OFF  ");
				
			   	switch (UART_Recieve())
				{                   	
			         case '1':// if the user choose light on room1
				     {
				      LCD_Clear_Screen();//the LCD command will be the clear LCD screen
				      _delay_ms(10);
				      SPI_Send_Data(ROOM1_LIGHT_ON);
				      
				     }break;

				     case '2':// if the user choose light off room1
				     {
			          LCD_Clear_Screen();//the LCD command will be the clear LCD screen
				      _delay_ms(10);
				      SPI_Send_Data(ROOM1_LIGHT_OFF);
                	  
				     }break;
				
			    }				
				
			    }break;
				
				
			    case '2':// if the user choose room2
			    {
					
			    LCD_Clear_Screen();//the LCD command will be the clear LCD screen
			   	_delay_ms(10);
				
			   	LCD_Write_Command(0x80);//the LCD command will be Force cursor to the beginning ( 1st line)
			   	LCD_Write_Word("1) ON   ");
			   	LCD_Write_Command(0xc0);//the LCD command will be Force cursor to the beginning ( 2st line)
			  	LCD_Write_Word("2) OFF  ");
				
			   	switch (UART_Recieve())
			   	{
				   	case '1':// if the user choose light on room2
				   	{
					   	LCD_Clear_Screen();//the LCD command will be the clear LCD screen
					   	_delay_ms(10);
					   	SPI_Send_Data(ROOM2_LIGHT_ON);
					   	
				   	}break;

				   	case '2':// if the user choose light off room2
				   	{
					   	LCD_Clear_Screen();//the LCD command will be the clear LCD screen
					   	_delay_ms(10);
					   	SPI_Send_Data(ROOM2_LIGHT_OFF);
					   	
				   	}break;
			   	}
			    }			    				

		    	}break;
				break;
				
				
				
				
				
				
				
			case '2': // if the user choose devices
			LCD_Clear_Screen();//the LCD command will be the clear LCD screen
			_delay_ms(10);
			
			LCD_Write_Command(0x80);//the LCD command will be Force cursor to the beginning ( 1st line)
			LCD_Write_Word("1)TV   ");
			LCD_Write_Command(0xc0);//the LCD command will be Force cursor to the beginning ( 2st line)
			LCD_Write_Word("2)AIR CONDITIONER");
			
			switch (UART_Recieve())
			{
				
				case '1':// if the user choose TV
				{
					
					LCD_Clear_Screen();//the LCD command will be the clear LCD screen
					_delay_ms(10);
					
					LCD_Write_Command(0x80);//the LCD command will be Force cursor to the beginning ( 1st line)
					LCD_Write_Word("1) ON   ");
					LCD_Write_Command(0xc0);//the LCD command will be Force cursor to the beginning ( 2st line)
					LCD_Write_Word("2) OFF  ");
					
					switch (UART_Recieve())
					{
						case 1:// if the user choose  on TV
						{
							LCD_Clear_Screen();//the LCD command will be the clear LCD screen
							_delay_ms(10);
							SPI_Send_Data(TV_ONN);
							
						}break;

						case 2:// if the user choose off TV
						{
							LCD_Clear_Screen();//the LCD command will be the clear LCD screen
							_delay_ms(10);
							SPI_Send_Data(TV_OF);
							
						}break;
					}
					
				}break;
				
				
				case '2':// if the user choose air conditioner
				{
					
					LCD_Clear_Screen();//the LCD command will be the clear LCD screen
					_delay_ms(10);
					
					LCD_Write_Command(0x80);//the LCD command will be Force cursor to the beginning ( 1st line)
					LCD_Write_Word("1) ON   ");
					LCD_Write_Command(0xc0);//the LCD command will be Force cursor to the beginning ( 2st line)
					LCD_Write_Word("2) OFF  ");
					
					switch (UART_Recieve())
					{
						case '1':// if the user choose on air conditioner
						{
							LCD_Clear_Screen();//the LCD command will be the clear LCD screen
							_delay_ms(10);
							SPI_Send_Data(AIR_CONDITIONER_ONN);
							
						}break;

						case '2':// if the user choose off air conditioner
						{
							LCD_Clear_Screen();//the LCD command will be the clear LCD screen
							_delay_ms(10);
							SPI_Send_Data(AIR_CONDITIONER_OF);
							
						}break;
					}

				}break;
				break;
					
					
			
				
        }
    }
}
}












































































