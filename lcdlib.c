
/*
 * lcdLib.c
 *
 * Created: 1/9/2020 10:31:11 PM
 * Author : Dan
 */ 
#include "lcdlib.h"
#include <avr/io.h>

#include <stdio.h>
#include <stdlib.h>

char firstColumnPositions[2] = {0,40};
	
	
void Send_String(char *String)
{
	while(*String>0)
	{
		Send_Character(*String++);
		_delay_ms(50);
	}
}

void CursorSet(uint8_t x, uint8_t y)
{
	Send_Command(0x80 + firstColumnPositions[y]+ x);
}
void Read_DDRAM(void)
{
	volatile unsigned char DataBits = Data6LSB>>2 | DataControl<<6;
	Check_Busy();
	DataDir_Data &= 0b00000011; // 6 Lsbs turned low inputs
	DataDir_Control &= 0b11111100; // 2 msbs of data turned low  inputs
	DataDir_Control|= (1<<RegisterSelect|1<<ReadWrite);
	EnableSetup();
	DataBits = Data6LSB>>2 | DataControl<<6;

	// TURN ALL DATA DIRECTION TO OUPUTS //
	DataDir_Data |= 0b11111100;
	DataDir_Control |= 0b00000011;
	
}
void Check_Busy(void)
{
	volatile unsigned char DataBits = Data6LSB>>2 | DataControl<<6;
	DataDir_Data &= 0b00000011; // 6 Lsbs turned low inputs
	DataDir_Control &= 0b11111100; // 2 msbs of data turned low  inputs
	DataControl |= 1<<ReadWrite;
	DataControl &= ~(1<<RegisterSelect);
	int i =0;
	while(DataBits  >= 0x80 )
	{
		
		EnableSetup();
		DataBits = Data6LSB>>2 | DataControl<<6;
	}
	// TURN ALL DATA DIRECTION TO OUPUTS //
	DataDir_Data |= 0b11111100;
	DataDir_Control |= 0b00000011;
	
}
void EnableSetup(void)
{
	volatile unsigned char isRSon=0, isRWon=0, DataBits;
	DataControl |= 1<<LightSwitch; //turn on enable
	asm volatile ("nop");
	asm volatile ("nop");
	asm volatile ("nop");
	asm volatile ("nop");
	asm volatile ("nop");
	DataControl &= ~(1<<LightSwitch); //turn off enable
}
void Send_Command(unsigned char command)
{
	volatile unsigned char temp = command;
	volatile unsigned char DataBits= 0x00, buffer=0x00;
	Check_Busy();
	Data6LSB|= temp<<2 & 0b11111100;
	temp = command;
	buffer = temp>>6 & 0b00000011; // all zeroes, and 2 MSBS of command, in 2LSBS of this temporary variable
	DataControl|= buffer;
	DataControl &=~(1<<ReadWrite|1<<RegisterSelect);
	DataBits = Data6LSB>>2 | DataControl<<6; //shifting didn't change the value of the variables shifted
	
	// ENABLE SETUP //
	EnableSetup();
	// ENABLE SETUP
	//Nullify data bits//
	Data6LSB&= 0b00000011;
	DataControl&= 0b11111100;
	DataBits = Data6LSB>>2 | DataControl<<6;
}

void Send_Character(unsigned char character)
{
	volatile unsigned char temp = character;
	volatile unsigned char DataBits= 0x00, buffer=0x00;
	Check_Busy();
	Data6LSB|= temp<<2 & 0b11111100;
	temp = character;
	buffer = temp>>6 & 0b00000011; // all zeroes, and 2 MSBS of command, in 2LSBS of this temporary variable
	DataControl|= buffer;
	DataControl &= ~(1<<ReadWrite);
	DataControl |= 1<<RegisterSelect;
	DataBits = Data6LSB>>2 | DataControl<<6; //shifting didn't change the value of the variables shifted

	// ENABLE SETUP //
	EnableSetup();
	// ENABLE SETUP
	Data6LSB&= 0b00000011;
	DataControl&= 0b11111100;
	DataBits = Data6LSB>>2 | DataControl<<6;
}

