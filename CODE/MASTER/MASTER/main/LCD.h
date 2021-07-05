
#ifndef LCD_INT_H_
#define LCD_INT_H_

#include "STD_TYPES.h"

void LCD_Init(void);
void LCD_Write_Command(U8 Command);
void LCD_Write_Data(U8 Data);
void LCD_Write_Word(U8 * Word);
void LCD_Clear_Screen(void);


#endif /* LCD_INT_H_ */
