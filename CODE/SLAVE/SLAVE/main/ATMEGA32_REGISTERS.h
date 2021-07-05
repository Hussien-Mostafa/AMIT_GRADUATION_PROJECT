


#ifndef ATMEGA32_REGISTERS_H_
#define ATMEGA32_REGISTERS_H_


/*****		Include Standard Data types		*****/

#include "STD_TYPES.h"



/**********		Define GPIO  REGs 		**********/



/*port A register addresses*/
#define PORTA_REG  (*(volatile U8*)(0x3B))
#define DDRA_REG   (*(volatile U8*)(0x3A))
#define PINA_REG   (*(volatile U8*)(0x39))

/*port B register addresses*/
#define PORTB_REG  (*(volatile U8*)(0x38))
#define DDRB_REG   (*(volatile U8*)(0x37))
#define PINB_REG   (*(volatile U8*)(0x36))

/*port C register addresses*/
#define PORTC_REG  (*(volatile U8*)(0x35))
#define DDRC_REG   (*(volatile U8*)(0x34))
#define PINC_REG   (*(volatile U8*)(0x33))

/*port D register addresses*/
#define PORTD_REG  (*(volatile U8*)(0x32))
#define DDRD_REG   (*(volatile U8*)(0x31))
#define PIND_REG   (*(volatile U8*)(0x30))


/**********		Define Interrupts REGs 	*********/

#define		SREG				*((volatile U8*)0x5F)
#define		GICR				*((volatile U8*)0x5B)
#define		GIFR				*((volatile U8*)0x5A)
#define		MCUCR				*((volatile U8*)0x55)
#define		MCUCSR				*((volatile U8*)0x54)


/*********		Define	Timer REGs  	**********/

#define		TCNT0				*((volatile U8*)0x52)   // TIMER & COUNTER 0
#define		TCCR0				*((volatile U8*)0x53)   // Timer/Counter Control
#define		TIFR				*((volatile U8*)0x58)   // Timer Interrupt Flag Register
#define		TIMSK				*((volatile U8*)0x59)	// Interrupt Mask Register
#define		OCR0				*((volatile U8*)0x5C)	// OutCompare Match Timer 0

/*** Timer 1 ***/

#define		TCCR1A				*((volatile U8*)0x4F)
#define		TCCR1B				*((volatile U8*)0x4E)
#define		TCNT1H				*((volatile U8*)0x4D)
#define		TCNT1L				*((volatile U8*)0x4C)
#define		OCR1AH				*((volatile U8*)0x4B)
#define		OCR1AL				*((volatile U8*)0x4A)
#define		OCR1BH				*((volatile U8*)0x49)
#define		OCR1BL				*((volatile U8*)0x48)
#define		ICR1H				*((volatile U8*)0x47)
#define		ICR1L				*((volatile U8*)0x46)

/*** Timer 2 ***/

#define		TCCR2				*((volatile U8*)0x45)
#define		TCNT2				*((volatile U8*)0x44)
#define		OCR2				*((volatile U8*)0x43)

#define  	WDTCR				*((volatile U8*)0x41)  //  WatchDog Timer

/**********	    USART Registers  **********/

#define		UDR					*((volatile U8*)0x2C)
#define		UCSRA				*((volatile U8*)0x2B)
#define		UCSRB				*((volatile U8*)0x2A)
#define		UCSRC				*((volatile U8*)0x40)
#define		UBRRL				*((volatile U8*)0x29)
#define		UBRRH				*((volatile U8*)0x40)



/***********	SPI Registers	***********/

#define		SPDR				*((volatile U8*)0x2F)
#define		SPSR				*((volatile U8*)0x2E)
#define		SPCR				*((volatile U8*)0x2D)

#define	SPR0			0	//	• Bit 0 - SPR0: SPI Clock Rate Select 0
#define SPR1			1	//	• Bit 1 - SPR1: SPI Clock Rate Select 1
#define	CPHA			2	//	• Bit 2 – CPHA: Clock Phase
#define	CPOL			3	//	• Bit 3 – CPOL: Clock Polarity
#define	MSTR			4	//	• Bit 4 – MSTR: Master/Slave Select
#define	DORD			5	//	• Bit 5 – DORD: Data Order
#define	SPE				6	//	• Bit 6 – SPE: SPI Enable
#define	SPIE			7	//	• Bit 7 – SPIE: SPI Interrupt Enable


#define	    SPIF	7	//	• Bit 7	- SPIF:	SPI Interrupt Flag






#endif /* ATMEGA32_REGISTERS_H_ */