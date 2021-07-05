

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "STD_TYPES.h"

/*proto types*/

//INPUT , OUTPUT
void DIO_SetPin_Direction(U8 PORTID, U8 PINID, U8 DIRECTION);

//OUTPUT= HIGH, LOW
void DIO_SetPin_Value(U8 PORTID, U8 PINID, U8 VALUE);

//INPUT= HIGH, LOW
U8 DIO_U8GetPin_Value(U8 PORTID, U8 PINID);

void DIO_SetPort_Direction(U8 PORTID, U8 DIRECTION);

void DIO_SetPort_Value(U8 PORTID , U8 VALUE);

#define    portA         0
#define    portB         1
#define    portC         2
#define    portD         3
		   
		   
#define    PIN0          0
#define    PIN1          1
#define    PIN2          2
#define    PIN3          3
#define    PIN4          4
#define    PIN5          5
#define    PIN6          6
#define    PIN7          7
		   		      
#define    HIGH          1
#define    LOW           0
		   
#define    INPUT         0
#define    OUTPUT        1
		   


#endif