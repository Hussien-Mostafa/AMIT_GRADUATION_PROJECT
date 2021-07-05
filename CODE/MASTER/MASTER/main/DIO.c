
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REGISTERS.h"
#include "DIO.h"


//INPUT , OUTPUT
void DIO_SetPin_Direction(U8 PORTID, U8 PINID, U8 DIRECTION)
{
	if(DIRECTION==OUTPUT)
	{
		switch (PORTID)
		{
			case portA:     SET_BIT(DDRA_REG, PINID);     break;
			case portB:     SET_BIT(DDRB_REG, PINID);     break;						
			case portC:     SET_BIT(DDRC_REG, PINID);     break;					
			case portD:     SET_BIT(DDRD_REG, PINID);     break;
		}
	}
	else if(DIRECTION== INPUT)
	{
		switch (PORTID)
		{
			case portA:  CLR_BIT(DDRA_REG, PINID);  break;
			case portB:  CLR_BIT(DDRB_REG, PINID);  break;
			case portC:  CLR_BIT(DDRC_REG, PINID);  break;
			case portD:  CLR_BIT(DDRD_REG, PINID);  break;
		}
		
	}
}

void DIO_SetPort_Direction(U8 PORTID, U8 DIRECTION)
{
	switch (PORTID)
	{
		case portA: DDRA_REG = DIRECTION; break;
		case portB: DDRB_REG = DIRECTION; break;
		case portC: DDRC_REG = DIRECTION; break;
		case portD: DDRD_REG = DIRECTION; break;
	}
}

//OUTPUT= HIGH, LOW
void DIO_SetPin_Value(U8 PORTID, U8 PINID, U8 VALUE)
{
	if (VALUE== HIGH)
	{
		switch (PORTID)
		{
			case portA: SET_BIT(PORTA_REG, PINID); break;
			case portB: SET_BIT(PORTB_REG, PINID); break;
			case portC: SET_BIT(PORTC_REG, PINID); break;
			case portD: SET_BIT(PORTD_REG, PINID); break;
		}
	}
		else if (VALUE == LOW)
		{
			switch (PORTID)
			{
				case portA:  CLR_BIT(PORTA_REG, PINID); break;
				case portB:  CLR_BIT(PORTB_REG, PINID); break;
				case portC:  CLR_BIT(PORTC_REG, PINID);  break;
				case portD:  CLR_BIT(PORTD_REG, PINID);  break;
			}
		}
	}

void DIO_SetPort_Value(U8 PORTID , U8 DIRECTION)
{
	switch (PORTID)
	{
		case portA: PORTA_REG = DIRECTION; break;
		case portB: PORTB_REG = DIRECTION; break;
		case portC: PORTC_REG = DIRECTION; break;
		case portD: PORTD_REG = DIRECTION; break;
	}
}

//INPUT= HIGH, LOW
U8 DIO_U8GetPin_Value(U8 PORTID, U8 PINID)
{
	U8 local_u8data= 0xFF;
	switch (PORTID)
	{
		case portA: local_u8data= GET_BIT(PINA_REG, PINID); break;		
		case portB: local_u8data= GET_BIT(PINB_REG, PINID); break;		
		case portC: local_u8data= GET_BIT(PINC_REG, PINID); break;	
		case portD: local_u8data= GET_BIT(PIND_REG, PINID); break;
	}
	return local_u8data;
}

