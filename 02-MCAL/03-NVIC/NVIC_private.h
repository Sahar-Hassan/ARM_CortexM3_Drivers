/**********************************************************************/
/** Author :Sahar Hassan Nooh *****************************************/
/** Date   :7 feb  2021        ****************************************/
/** Version:v01 *******************************************************/
/**********************************************************************/

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_
/*				Memory Mapped of NVIC Addresses			*/
#define 		NVIC_BASE_ADD		(0xE000E100)

#define 		NVIC_ISER0			*((u32 *)(NVIC_BASE_ADD+0x000) )/* Enable External interrupts from 0  to 31 */
#define 		NVIC_ISER1			*((u32 *)(NVIC_BASE_ADD+0x004) )/* Enable External interrupts from 32 to 63 */

#define 		NVIC_ICER0			*((u32 *)(NVIC_BASE_ADD+0x080) )/* Disable External interrupts from 0  to 31 */
#define 		NVIC_ICER1			*((u32 *)(NVIC_BASE_ADD+0x084) )/* Disable External interrupts from 32 to 63 */

#define 		NVIC_ISPR0			*((u32 *)(NVIC_BASE_ADD+0x100) )/* set pedding flags from 0  to 31*/
#define 		NVIC_ISPR1			*((u32 *)(NVIC_BASE_ADD+0x104) )/* set pedding flags from 32 to 63*/

#define 		NVIC_ICPR0			*((u32 *)(NVIC_BASE_ADD+0x180) )/* CLR pedding flags from 0  to 31*/
#define 		NVIC_ICPR1			*((u32 *)(NVIC_BASE_ADD+0x184) )/* CLR pedding flags from 32 to 63*/

#define 		NVIC_IABR0			*((volatile u32 *)(NVIC_BASE_ADD+0x200) )
#define 		NVIC_IABR1			*((volatile u32 *)(NVIC_BASE_ADD+0x204) )

#define 		NVIC_IPR			((u8 *)(NVIC_BASE_ADD + 0x300))


#define 		GROUPS_16_SUB_0		(0x05FA0300)
#define 		GROUPS_8_SUB_2		(0x05FA0400)
#define 		GROUPS_4_SUB_4		(0x05FA0500)
#define 		GROUPS_2_SUB_8		(0x05FA0600)
#define 		GROUPS_0_SUB_16		(0x05FA0700)



#endif /* NVIC_PRIVATE_H_ */
