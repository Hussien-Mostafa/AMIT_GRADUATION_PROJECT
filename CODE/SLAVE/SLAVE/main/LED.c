

#include "ATMEGA32_REGISTERS.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "Led.h"

void LED1_INIT(void)
{
	DIO_SetPin_Direction(PORTA_REG, PIN0, OUTPUT);
}
void LED1_ON(void)
{
	DIO_SetPin_Value(PORTA_REG, PIN0, HIGH);
}
void LED1_OFF(void)
{
	DIO_SetPin_Value(PORTA_REG, PIN0, LOW);
}
void LED1_TOG(void)
{
	Toggle_BIT(PORTA_REG, PIN0);
}



void LED2_INIT(void)
{
	DIO_SetPin_Direction(PORTA_REG, PIN1, OUTPUT);
}
void LED2_ON(void)
{
	DIO_SetPin_Value(PORTA_REG, PIN1, HIGH);
}
void LED2_OFF(void)
{
	DIO_SetPin_Value(PORTA_REG, PIN1, LOW);
}
void LED2_TOG(void)
{
	Toggle_BIT(PORTA_REG, PIN1);
}



void TV_INIT(void)
{
	DIO_SetPin_Direction(PORTA_REG, PIN2, OUTPUT);
}
void TV_ON(void)
{
	DIO_SetPin_Value(PORTA_REG, PIN2, HIGH);
}
void TV_OFF(void)
{
	DIO_SetPin_Value(PORTA_REG, PIN2, LOW);
}



void AIR_CONDITIONER_INIT(void)
{
	DIO_SetPin_Direction(PORTA_REG, PIN3, OUTPUT);
}
void AIR_CONDITIONER_ON(void)
{
	DIO_SetPin_Value(PORTA_REG, PIN3, HIGH);
}
void AIR_CONDITIONER_OFF(void)
{
	DIO_SetPin_Value(PORTA_REG, PIN3, LOW);
}

