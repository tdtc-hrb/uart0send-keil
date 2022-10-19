/****************************************Copyright (c)****************************************************
**                                 http://www.PowerAVR.com
**								   http://www.PowerMCU.com
**--------------File Info---------------------------------------------------------------------------------
** File name:           main.c
** Last modified Date:  2010-05-12
** Last Version:        V1.00
** Descriptions:        The main() function example template
**
**--------------------------------------------------------------------------------------------------------
** Created by:          PowerAVR
** Created date:        2010-05-10
** Version:             V1.00
** Descriptions:        sample
**
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/
#include "LPC17xx.h"
#include "uart.h"

const uint32_t led_mask[] = { 1UL<<0, 1UL<<1, 1UL<<2, 1UL<<3, 1UL<<4, 1UL<<5, 1UL<<6, 1UL<<7, 1UL<<8 };

#define BEEP (1UL << 7)
#define BEEP_INIT LPC_GPIO0->FIODIR |= BEEP
#define BEEP_ON LPC_GPIO0->FIOCLR |= BEEP
#define BEEP_OFF LPC_GPIO0->FIOSET |= BEEP

/*********************************************************************************************************
** Function name:       Delay
** Descriptions:        software delay
** input parameters:    ulTime
** output parameters:   no
** Returned value:      no
*********************************************************************************************************/
void Delay (uint32_t Time)
{
    uint32_t i;
    
    i = 0;
    while (Time--) {
        for (i = 0; i < 5000; i++);
    }
}
void ledOff(uint8_t led)
{   
	LPC_GPIO2->FIOSET |= led_mask[led];
}

void ledOn(uint8_t led)
{
	LPC_GPIO2->FIOCLR |= led_mask[led];
}


int main(void)
{
	uint8_t k;
	SystemInit();
	UART0_Init(9600);
	//UART2_Init();
	LPC_GPIO2->FIODIR = 0x000001ff;               /* LEDs PORT2 are Output */
	// GPIO0
	LPC_GPIO0->FIODIR = 0x0000;
	
	for (k = 0; k < 10; k++)
	{
	  ledOff(k);
	} 
			
    while (1) 
	{
		BEEP_OFF;
		Delay(1500);
		BEEP_ON;
		/*
	    ledOn(9);
		UART0_SendString("LandTiger LPC17XX board.\n");	    
		Delay(1500);
		ledOff(9);
		Delay(1500);
		ledOn(9);
		UART0_SendString("http://www.csun.co.jp\n");
		Delay(1500);
		ledOff(9);
		Delay(1500);
		ledOn(9);
	    UART0_SendString("TEL 044-571-3089\n");
		Delay(1500);
		ledOff(9);
		Delay(1500);
		UART0_SendString("LandTiger UART test.\n");
	    ledOn(9);
		Delay(1500);
		ledOff(9);
		Delay(1500);
		ledOn(9);
		UART0_SendString("http://www.csun.co.jp\n");
		Delay(1500);
		ledOff(9);
		Delay(1500);
			*/
    }
	
}
