/*
 * lcdlib.h
 *
 * Created: 1/9/2020 10:31:52 PM
 *  Author: Dan
 */ 


#ifndef LCDLIB_H_
#define LCDLIB_H_

#include <util/delay.h>
#define Data6LSB		PORTD
#define DataControl		PORTB
#define DataDir_Data	DDRD
#define DataDir_Control DDRB
#define LightSwitch		4
#define ReadWrite		3
#define RegisterSelect	2

void Sned_Character(unsigned char character);
void Send_Command(unsigned char command);
void EnableSetup(void);
void Check_Busy(void);
void Read_DDRAM(void);
void Send_String(char *String);
void CursorSet(uint8_t x, uint8_t y);



#endif /* LCDLIB_H_ */