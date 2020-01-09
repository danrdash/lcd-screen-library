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


 int main(void)
 {
	
	 /* Replace with your application code */
	 DataDir_Control |=  1<<LightSwitch | 1<<RegisterSelect | 1<<ReadWrite; //set relevant bits as inputs

	 
	 Send_Command(0x01); // clear screen
	 _delay_ms(20);
	 
	 _delay_us(50);
	 Send_Command(0x38); //Initialize 8 bit mode
	 _delay_ms(10);
	
	 _delay_us(50);
	 Send_Command(0b00001111); // cursor and display on
	 _delay_ms(50);
	 Send_Character('A');
	 _delay_ms(50);
	 Send_Command(0x01);
	 _delay_ms(50);
	 Send_String("Happy Christmas                                <3");
	 _delay_ms(50);
	 Send_Command(0x01); // clear screen
	 _delay_ms(50);
	 Send_String("First Line");
	 _delay_ms(50);
	 CursorSet(0,1);
	 _delay_us(37);
	 Send_String("Second Line");
	 _delay_us(50);
	 Send_Command(0x01);
	 _delay_ms(50);
 }


