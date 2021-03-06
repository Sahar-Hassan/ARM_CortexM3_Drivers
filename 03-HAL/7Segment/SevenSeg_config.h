/**********************************************************************/
/** Author :Sahar Hassan Nooh *****************************************/
/** Date   :4 feb  2021        ****************************************/
/** Version:v01 *******************************************************/
/**********************************************************************/
#ifndef SEVENSEG_CONFIG_H_
#define SEVENSEG_CONFIG_H_

/* Choose between 1-COMMON_CATHODE
 *                2-COMMON_ANODE
 */
#define      SSEG_COMMON_TYPE     COMMON_CATHODE

/* Choose number of Segments u want to use 1- 1
 *                                         2- 2
 *
 */
#define      SSEG_NUMBERS         1

/******************************        IN CASE 2 SSEG                    *****************************/
/* In case 2 Seven segment choose which ports*/
/* Choose Which Part of the Port 1-LOW
 *                               2-HIGH
 */
#define      SSEG1_PORT         DIO_U8_PORTA
#define      SSEG1_PART            LOW
#define      SSEG2_PORT         DIO_U8_PORTB
#define      SSEG2_PART            HIGH



/********************************    IN CASE 1 SSEG                    **************************/
/* Choose Which Port 1- DIO_U8_PORTA
 *                   2- DIO_U8_PORTB
 *                   3- DIO_U8_PORTC
 */
/* Choose Which Part of the Port 1-LOW
 *                               2-HIGH
 */
#define      SSEG_PORT            DIO_U8_PORTB
#define      SSEG_PART            HIGH


#endif /* SEVENSEG_CONFIG_H_*/
