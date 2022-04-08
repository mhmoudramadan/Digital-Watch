/*
 * main.c
 *
 *  Created on: Apr 7, 2022
 *      Author: Dell
 */
#include"LIB/LSTD_TYPES.h"
#include"MCAL/MDIO/MDIO_Interface.h"
#include"MCAL/MEXTI/MEXTI_Config.h"
#include"MCAL/MEXTI/MEXTI_Interface.h"
#include"MCAL/MGIE/MGIE_Interface.h"
#include"MCAL/MTIMER1/MTIMER1_Interface.h"
#include"HAL/HCLCD/HCLCD_Config.h"
#include"HAL/HCLCD/HCLCD_Interface.h"

#define F_CPU 16000000UL
#include<util/delay.h>


uint8 global_uint8flag=0;
uint8 global_uint8SEC=0;
uint8 global_uint8MIN=0;
uint8 global_uint8HOUR=0;


void APP_VidTEXTI1(void)
{
	/*check for start condition*/
	global_uint8flag=1;
}
void APP_VidTEXTI0(void)
{
	/*check for reset condition*/
	global_uint8SEC=0;
	global_uint8MIN=0;
	global_uint8HOUR=0;
}
void APP_VidTOV(void)
{
		global_uint8SEC++;
		if(global_uint8SEC==60)
		{
			global_uint8SEC=0;
			global_uint8MIN+=1;
		}
		if(global_uint8MIN==60)
		{
			global_uint8MIN=0;
			global_uint8HOUR+=1;
		}
		if(global_uint8HOUR==24)
		{
			global_uint8SEC=0;
			global_uint8MIN=0;
			global_uint8HOUR=0;
		}
}

int main(void)
{
					/*Initialize LCD*/
	MDIO_Errorstate_SetPinDirection(HCLCD_ControlPort,RS_PIN,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(HCLCD_ControlPort,RW_PIN,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(HCLCD_ControlPort,E_PIN,PIN_OUTPUT);

	MDIO_Errorstate_SetPinDirection(HCLCD_DataPort,PIN4,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(HCLCD_DataPort,PIN5,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(HCLCD_DataPort,PIN6,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(HCLCD_DataPort,PIN7,PIN_OUTPUT);
				/*initialize LCD*/
	HAL_VidHCLCD_4BitModeInit();
	HAL_VidHCLCD_4BitModeSetPosition(1,0);
	HAL_VidHCLCD_4BitModeWriteString((uint8*)"stop Watch");
	HAL_VidHCLCD_4BitModeSetPosition(2,0);
	HAL_VidHCLCD_4BitModeWriteString((uint8*)"00:00:00");


	/*Set INT0,1 PIN*/
	MDIO_Errorstate_SetPinDirection(MDIO_PORTD,PIN3,PIN_INPUT);
	MDIO_Errorstate_SetPinDirection(MDIO_PORTD,PIN2,PIN_INPUT);
	/*Active Pull up resistor*/
	MDIO_Errorstate_SetPinValue(MDIO_PORTD,PIN2,PIN_HIGH);
	MDIO_Errorstate_SetPinValue(MDIO_PORTD,PIN3,PIN_HIGH);

		/*set Timer1-->CTC mode PreScaler-->256 to get interrupt every 1 sec*/
	MTIMER1_VidTimer1_CTC_SetCallBack(APP_VidTOV);
	MTIMER1_VidSetCTCRegister_CHA(62534);
	MTIMER1_VidInit();
		/*Start stop watch*/
	MEXTI1_VidSetCallBack(APP_VidTEXTI1);
		/*for reset stop watch*/
	MEXTI0_VidSetCallBack(APP_VidTEXTI0);

	/*Enable GIE - PIE  interrupt*/
	MGIE_Enable();
	MEXTI_VidInitEXTI0();
	MEXTI_VidInitEXTI1();

	while(1)
	{
				HAL_VidHCLCD_4BitModeSetPosition(2,6);
				HAL_VidHCLCD_4BitModeWriteNumber(global_uint8SEC);

				HAL_VidHCLCD_4BitModeSetPosition(2,4);
				HAL_VidHCLCD_4BitModeWriteNumber(global_uint8MIN);

				HAL_VidHCLCD_4BitModeSetPosition(2,1);
				HAL_VidHCLCD_4BitModeWriteNumber(global_uint8HOUR);


	}
	return 0;
}
