/**********************************************************************/
/** Author : Sahar Hassan Nooh ****************************************/
/** Date   : 4 feb  2021       ****************************************/
/** Version:v01                ****************************************/
/**********************************************************************/

 * GPIO_program.c
 *
 *  Created on: Feb 3, 2021
 *      Author: Boon
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

/*void	DIO_voidSetPinDirection(port,pin,mode);*/
void	DIO_voidSetPinDirection(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8Mode)
{
	/*		Range Check							*/
	if( (Copy_u8PortID<3) && (Copy_u8PinID<16) )
	{
		switch(Copy_u8PortID)
		{
			case DIO_U8_PORTA:
				/*		LOW PORT				*/
				if( Copy_u8PinID < 8 )
				{
				/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
					GPIOA_CRL &= ~((u32)(0b1111)<<(Copy_u8PinID * 4));
					GPIOA_CRL |=  ((u32)(Copy_u8Mode)<<(Copy_u8PinID * 4));
				}
				/*		HIGH PORT				*/
				else
				{
					Copy_u8PinID -= 8 ;
				/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
					GPIOA_CRH &= ~((u32)(0b1111)<<(Copy_u8PinID * 4));
					GPIOA_CRH |=  ((u32)(Copy_u8Mode)<<(Copy_u8PinID * 4));
				}
				break;
			case DIO_U8_PORTB:
				if( Copy_u8PinID < 8 )
				{
				/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
					GPIOB_CRL &= ~((u32)(0b1111)<<(Copy_u8PinID * 4));
					GPIOB_CRL |=  ((u32)(Copy_u8Mode)<<(Copy_u8PinID * 4));
				}
				/*		HIGH PORT				*/
				else
				{
					Copy_u8PinID -= 8 ;
				/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
					GPIOB_CRH &= ~((u32)(0b1111)<<(Copy_u8PinID * 4));
					GPIOB_CRH |=  ((u32)(Copy_u8Mode)<<(Copy_u8PinID * 4));
				}
				break;
			case DIO_U8_PORTC:
				if( Copy_u8PinID < 8 )
				{
				/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
					GPIOC_CRL &= ~((u32)(0b1111)<<(Copy_u8PinID * 4));
					GPIOC_CRL |=  ((u32)(Copy_u8Mode)<<(Copy_u8PinID * 4));
				}
				/*		HIGH PORT				*/
				else
				{
					Copy_u8PinID -= 8 ;
				/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
					GPIOC_CRH &= ~((u32)(0b1111)<<(Copy_u8PinID * 4));
					GPIOC_CRH |=  ((u32)(Copy_u8Mode)<<(Copy_u8PinID * 4));
				}
				break;
		}
	}else{/*	Return ERROR	*/}

}
/*		if Pin is Output (High or Low)	*/
void	DIO_voidSetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8Value)
{
	/*		Range Check							*/
	if( (Copy_u8PortID<3) && (Copy_u8PinID<16) )
	{
		switch(Copy_u8PortID)
		{
			case DIO_U8_PORTA:
				switch(Copy_u8Value)
				{
					case DIO_U8_HIGH:	SET_BIT(GPIOA_ODR , Copy_u8PinID);	break;
					case DIO_U8_LOW	:	CLR_BIT(GPIOA_ODR , Copy_u8PinID);	break;
					default:;	/*		Return ERROR		*/
				}
				break;
			case DIO_U8_PORTB:
				switch(Copy_u8Value)
				{
					case DIO_U8_HIGH:	SET_BIT(GPIOB_ODR , Copy_u8PinID);	break;
					case DIO_U8_LOW	:	CLR_BIT(GPIOB_ODR , Copy_u8PinID);	break;
					default:;	/*		Return ERROR		*/
				}
				break;
			case DIO_U8_PORTC:
				switch(Copy_u8Value)
				{
					case DIO_U8_HIGH:	SET_BIT(GPIOC_ODR , Copy_u8PinID);	break;
					case DIO_U8_LOW	:	CLR_BIT(GPIOC_ODR , Copy_u8PinID);	break;
					default:;	/*		Return ERROR		*/
				}
				break;
	}
	}else{/*	Return ERROR	*/}
}
/*		if Pin is Input (Return High or Low)	*/
u8		DIO_u8GetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID)
{
	u8 Local_u8Value = 0XFF;
	/*		Range Check							*/
	if( (Copy_u8PortID<3) && (Copy_u8PinID<16) )
	{

		switch(Copy_u8PortID)
		{
			case DIO_U8_PORTA:	Local_u8Value = GET_BIT(GPIOA_IDR , Copy_u8PinID);	break;
			case DIO_U8_PORTB:	Local_u8Value = GET_BIT(GPIOB_IDR , Copy_u8PinID);	break;
			case DIO_U8_PORTC:	Local_u8Value = GET_BIT(GPIOC_IDR , Copy_u8PinID);	break;

		}
	}else{/*	Return ERROR	*/}

	return Local_u8Value;
}
void DIO_VidSetPortDirection ( u8 Copy_u8Port , u8 Copy_u8Position , u8 Copy_u8Mode   )
{
	switch( Copy_u8Port ){

		case DIO_U8_PORTA:

			if      ( Copy_u8Position == LOW  ) { GPIOA_CRL = ( 0x11111111 * Copy_u8Mode ) ; }
			else if ( Copy_u8Position == HIGH ) { GPIOA_CRH = ( 0x11111111 * Copy_u8Mode ) ; }

			break;
		case DIO_U8_PORTB:

			if      ( Copy_u8Position == LOW  ) {GPIOB_CRL = ( 0x11111111 * Copy_u8Mode ) ; }
			else if ( Copy_u8Position == HIGH ) {GPIOB_CRH = ( 0x11111111 * Copy_u8Mode ) ; }

			break;
		case DIO_U8_PORTC:

			if      ( Copy_u8Position == LOW  )  {GPIOC_CRL = ( 0x11111111 * Copy_u8Mode ) ; }
			else if ( Copy_u8Position == HIGH )  {GPIOC_CRH = ( 0x11111111 * Copy_u8Mode ) ; }

			break;

		}
}
/*		if Pin is Output (High or Low)	*/
void DIO_VidSetPortValue     ( u8 Copy_u8Port , u8 Copy_u8Position , u16 Copy_u8Value )
{
	switch( Copy_u8Port ){

		case DIO_U8_PORTA :

			if      ( Copy_u8Position == LOW  ){ GPIOA_ODR = (GPIOA_ODR& 0xFF00 ) | ( (u8)Copy_u8Value ) ; }
			else if ( Copy_u8Position == HIGH ){ GPIOA_ODR = (GPIOA_ODR& 0xFF00 ) | (     Copy_u8Value ) ; }

			break;
		case DIO_U8_PORTB:

				if      ( Copy_u8Position == LOW  ){ GPIOB_ODR = (GPIOB_ODR& 0xFF00 ) | ( (u8)Copy_u8Value ) ; }
				else if ( Copy_u8Position == HIGH ){ GPIOB_ODR = (GPIOB_ODR& 0xFF00 ) | (     Copy_u8Value ) ; }

			break;
		case DIO_U8_PORTC:

				if      ( Copy_u8Position == LOW  ){ GPIOC_ODR = (GPIOC_ODR& 0xFF00 ) | ( (u8)Copy_u8Value ) ; }
				else if ( Copy_u8Position == HIGH ){ GPIOC_ODR = (GPIOC_ODR& 0xFF00 ) | (     Copy_u8Value ) ; }

			break;

		}


}
/*		SET PORT VALUE												*/
u16  DIO_u16GetPortValue      ( u8 Copy_u8Port , u8 Copy_u8Position      )
{
	u16 LOC_u16Result = 0;

		switch( Copy_u8Port ){

		case DIO_U8_PORTA:

			LOC_u16Result =GPIOA_IDR;
			if      ( Copy_u8Position == LOW  ){ LOC_u16Result &= 0x00FF ; }
			else if ( Copy_u8Position == HIGH ){ LOC_u16Result &= 0xFF00 ; }

			break;
		case DIO_U8_PORTB:

			LOC_u16Result = GPIOB_IDR;
			if      ( Copy_u8Position == LOW  ){ LOC_u16Result &= 0x00FF ; }
			else if ( Copy_u8Position == HIGH ){ LOC_u16Result &= 0xFF00 ; }

			break;
		case DIO_U8_PORTC:

			LOC_u16Result =GPIOA_IDR;
			if      ( Copy_u8Position == LOW  ){ LOC_u16Result &= 0x00FF ; }
			else if ( Copy_u8Position == HIGH ){ LOC_u16Result &= 0xFF00 ; }

			break;

		}

		return LOC_u16Result ;


}



