/*
 * MEXTI_Program.c
 *
 *  Created on: Feb 4, 2022
 *      Author: Dell
 */
#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"
#include "MEXTI_Private.h"
#include "MEXTI_Interface.h"
#include "MEXTI_Config.h"

void (*CALLBACK)(void);

void MEXTI_VidInitEXTI0(void)
{
	/*Select sense control*/
#if SET_SENCECONTROL_EXTI0==MEXTI_RISING_EDGE
	SET_BIT(MCUCR,1);
	SET_BIT(MCUCR,0);
#elif SET_SENCECONTROL_EXTI0==MEXTI_FALLING_EDGE
	SET_BIT(MCUCR,1);
	CLR_BIT(MCUCR,0);
#elif SET_SENCECONTROL_EXTI0==MEXTI_ANYLOGICALCHANGE
	CLR_BIT(MCUCR,1);
	SET_BIT(MCUCR,0);

#elif SET_SENCECONTROL_EXTI0==MEXTI_LOW_LEVEL
	CLR_BIT(MCUCR,1);
	CLR_BIT(MCUCR,0);
#else
#error "Sense Control option of EXTI0 is not valid"

#endif
	/*Enable EXTI 0*/
	SET_BIT(GICR,6);

}
void MEXTI_VidInitEXTI1(void)
{
	/*Select Sense Control */
#if SET_SENCECONTROL_EXTI1==MEXTI_RISING_EDGE
	SET_BIT(MCUCR,3);
	SET_BIT(MCUCR,2);

#elif SET_SENCECONTROL_EXTI1==MEXTI_FALLING_EDGE
	SET_BIT(MCUCR,3);
	CLR_BIT(MCUCR,2);
#elif SET_SENCECONTROL_EXTI1==MEXTI_ANYLOGICALCHANGE

	CLR_BIT(MCUCR,3);
	SET_BIT(MCUCR,2);
#elif SET_SENCECONTROL_EXTI1==MEXTI_LOW_LEVEL
	CLR_BIT(MCUCR,3);
	CLR_BIT(MCUCR,2);
#else
#error "Sense Control option of EXTI1 is not valid"

#endif
	/* Enable EXTI 1*/
	SET_BIT(GICR,7);
}
void MEXTI_VidInitEXTI2(void)
{
	/*Select Sense Control */
	#if SET_SENCECONTROL_EXTI2==MEXTI_RISING_EDGE
		SET_BIT(MCUCSR,6);
	#elif SET_SENCECONTROL_EXTI2==MEXTI_FALLING_EDGE
		CLR_BIT(MCUCSR,6);
	#else
	#error "Sense Control option of EXTI2 is not valid"

	#endif
		/* Enable EXTI 2*/
		SET_BIT(GICR,5);

}
void MEXTI_VidSenseControlSelect(uint8 copy_uint8EXTI_ID,uint8 copy_uint8EXTI_SenseControl)
{
	switch (copy_uint8EXTI_ID)
	{
	case EXTI0:
		if(copy_uint8EXTI_SenseControl==MEXTI_RISING_EDGE)
		{
			SET_BIT(MCUCR,1);
			SET_BIT(MCUCR,0);
		}
		else if(copy_uint8EXTI_SenseControl==MEXTI_FALLING_EDGE)
		{
			SET_BIT(MCUCR,1);
			CLR_BIT(MCUCR,0);
		}
		else if(copy_uint8EXTI_SenseControl==MEXTI_ANYLOGICALCHANGE)
		{
			CLR_BIT(MCUCR,1);
			SET_BIT(MCUCR,0);
		}
		else if(copy_uint8EXTI_SenseControl==MEXTI_LOW_LEVEL)
		{
			CLR_BIT(MCUCR,1);
			CLR_BIT(MCUCR,0);
		}
		else
		{
			/*do nothing*/
		}
		break;

	case EXTI1:
		if(copy_uint8EXTI_SenseControl==MEXTI_RISING_EDGE)
		{
			SET_BIT(MCUCR,3);
			SET_BIT(MCUCR,2);
		}
		else if(copy_uint8EXTI_SenseControl==MEXTI_FALLING_EDGE)
		{
			SET_BIT(MCUCR,3);
			CLR_BIT(MCUCR,2);
		}
		else if(copy_uint8EXTI_SenseControl==MEXTI_ANYLOGICALCHANGE)
		{
			CLR_BIT(MCUCR,3);
			SET_BIT(MCUCR,2);
		}
		else if(copy_uint8EXTI_SenseControl==MEXTI_LOW_LEVEL)
		{
			CLR_BIT(MCUCR,3);
			CLR_BIT(MCUCR,2);
		}
		else
		{
			/*do nothing*/
		}
		break;

	case EXTI2:
		if(copy_uint8EXTI_SenseControl==MEXTI_RISING_EDGE)
		{
			SET_BIT(MCUCSR,6);
		}
		else if(copy_uint8EXTI_SenseControl==MEXTI_FALLING_EDGE)
		{
			CLR_BIT(MCUCSR,6);		}

		else
		{
			/*do nothing*/
		}
		break;
	}

}
void MEXTI0_VidSetCallBack(void (*PtrToFun)(void))
{
	CALLBACK=PtrToFun;
}
void MEXTI1_VidSetCallBack(void (*PtrToFun)(void))
{
	CALLBACK=PtrToFun;
}
void MEXTI2_VidSetCallBack(void (*PtrToFun)(void))
{
	CALLBACK=PtrToFun;
}
/*EXTI0*/
void __vector_1(void)   __attribute__((signal));
void __vector_1(void)
{
	CALLBACK();
}
/*EXTI 1 */
void __vector_2(void)   __attribute__((signal));
void __vector_2(void)
{
	CALLBACK();
}
/*EXTI2*/
void __vector_3(void)   __attribute__((signal));
void __vector_3(void)
{
	CALLBACK();
}
