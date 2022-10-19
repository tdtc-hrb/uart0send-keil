/****************************************Copyright (c)****************************************************
**                                 http://www.PowerAVR.com
**								   http://www.PowerMCU.com
**--------------File Info---------------------------------------------------------------------------------
** File name:           uart.h
** Last modified Date:  2010-05-12
** Last Version:        V1.00
** Descriptions:        
**
**--------------------------------------------------------------------------------------------------------
** Created by:          PowerAVR
** Created date:        2010-05-10
** Version:             V1.00
** Descriptions:        ��дʾ������
**
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/
#ifndef __UART_H
#define __UART_H

void UART0_Init (uint32_t baud);
int  UART0_SendByte (int ucData);
int  UART0_GetChar (void);
void UART0_SendString (unsigned char *s); 
void UART2_Init (void);
int  UART2_SendByte (int ucData);
int  UART2_GetChar (void);
void UART2_SendString (unsigned char *s);
void UART0_SendChar(uint16_t disp);  

#endif
