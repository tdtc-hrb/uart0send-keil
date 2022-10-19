/****************************************Copyright (c)****************************************************
**                                 http://www.PowerAVR.com
**                                 http://www.PowerMCU.com
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
                                                                /* ------------------------ BEEP -------------------------- */
#define    BEEP         1UL << 7                                /* P0.7                                                     */
#define    BEEP_INIT()  LPC_GPIO0->FIODIR |= BEEP               /* beep init                                                */
#define    BEEP_OFF()   LPC_GPIO0->FIOSET |= BEEP               /* beep close                                               */
#define    BEEP_ON()    LPC_GPIO0->FIOCLR |= BEEP               /* beep open                                                */


#define    LED          1UL << 8                                 /* P2.8       */
#define    LED_INIT()   LPC_GPIO2->FIODIR |= LED                 /* LED INIT   */
#define    LED_OFF()    LPC_GPIO2->FIOSET |= LED                 /* LED OFF    */
#define    LED_ON()     LPC_GPIO2->FIOCLR |= LED                 /* LED ON     */

const uint32_t led_mask[] = { 1UL<<0, 1UL<<1, 1UL<<2, 1UL<<3, 1UL<<4, 1UL<<5, 1UL<<6, 1UL<<7, 1UL<<8 };

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
    // uint8_t k;
    SystemInit();
    UART0_Init(9600);
    //UART2_Init();
    
    // BEEP
    BEEP_INIT();
    BEEP_OFF();

    // LED
    LED_INIT();
    LED_OFF();

    /*
    LPC_GPIO2->FIODIR = 0x000001ff;               
    for (k = 0; k < 10; k++)
    {
      ledOff(k);
    } 
    */      
    while (1) 
    {
        BEEP_ON();

        // ledOn(9);
        LED_ON();
        UART0_SendString("I have worked with my foreign teacher in some parts for a long period,\n");       
        Delay(1500);
        // ledOff(9);
        LED_OFF();
        Delay(1000);
        // ledOn(9);
        LED_ON();
        UART0_SendString("so I have got my unique idea and apperception ability about coaching and");
        Delay(1500);
        // ledOff(9);
        LED_OFF();
        Delay(1000);
        // ledOn(9);
        LED_ON();
        UART0_SendString("interpretation.\n");
        Delay(1500);
        // ledOff(9);
        LED_OFF();
        Delay(1000);
        UART0_SendString("During this precious time, I'd like to give you a marvelous impression.\n");
        // ledOn(9);
        LED_ON();
        Delay(1500);
        // ledOff(9);
        LED_OFF();
        Delay(1000);

        // ledOn(9);
        LED_ON();
        UART0_SendString("I do approve and endorse New Oriental's achievement and\n");
        Delay(1500);
        // ledOff(9);
        LED_OFF();
        Delay(1000);

        // ledOn(9);
        LED_ON();
        UART0_SendString("the No.1 status in English language teaching.\n");
        Delay(1500);
        // ledOff(9);
        LED_OFF();
        Delay(1000);

        // ledOn(9);
        LED_ON();
        UART0_SendString("Joining you team and contributing my power is the wish\n");
        Delay(1500);
        // ledOff(9);
        LED_OFF();
        Delay(1000);

        // ledOn(9);
        LED_ON();
        UART0_SendString("and longing from my inner heart.\n");
        Delay(1500);
        // ledOff(9);
        LED_OFF();
        Delay(1000);

        // ledOn(9);
        LED_ON();
        UART0_SendString("Thank all interviewers.\n");
        Delay(1500);
        // ledOff(9);
        LED_OFF();
        Delay(10000);

        BEEP_OFF();
        Delay(6000);
        
    }
    
}
