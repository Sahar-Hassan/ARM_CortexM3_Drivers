/*
 * KeyPad_program.c
 *
 *  Created on: Feb 7, 2021
 *      Author: Sarah
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"

#include "KeyPad_interface.h"
#include "KeyPad_config.h"


static const u8 Keys[4][4]={{'7','8','9','/'},
					   	    {'4','5','6','*'},
						    {'1','2','3','-'},
						    {'c','0','=','+'}};

 
static const u8 HexKeys[4][4]={{'7','8','9','F'},
					   	       {'4','5','6','E'},
						       {'1','2','3','B'},
						       {'c','0','=','A'}};
						       {'c','0','=','A'}};


/**********************************************************************/
/** Author :Sahar Hassan Nooh *****************************************/
/** Date   :7 feb  2021        ****************************************/
/** Version:v01 *******************************************************/
/**********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
 #include "GPIO_interface.h"

u8 KeyPad_u8GetKey(void)
{
	u8 Local_u8row,Local_u8col,Local_u8key = KEY_DEFAULT ;

	DIO_voidSetPinValue(KEYPAD_PORT, FIRST_OUTPUT  , HIGH);
	DIO_voidSetPinValue(KEYPAD_PORT, FIRST_OUTPUT+1, HIGH);
	DIO_voidSetPinValue(KEYPAD_PORT, FIRST_OUTPUT+2, HIGH);
	DIO_voidSetPinValue(KEYPAD_PORT, FIRST_OUTPUT+3, HIGH);


	for (Local_u8row = 0 ; Local_u8row <4 ; Local_u8row++)
	{
		DIO_voidSetPinValue(KEYPAD_PORT, FIRST_OUTPUT+Local_u8row , LOW);

		for (Local_u8col = 0 ; Local_u8col < 4 ; Local_u8col ++)
		{
			if(!DIO_u8GetPinValue(KEYPAD_PORT, FIRST_INPUT+Local_u8col))
			{
			Local_u8key = Keys[Local_u8row][Local_u8col];
			while(!DIO_u8GetPinValue(KEYPAD_PORT, FIRST_INPUT+Local_u8col));
			}
		}
		DIO_voidSetPinValue(KEYPAD_PORT, FIRST_OUTPUT+Local_u8row, HIGH);
	}
	return Local_u8key;
}
