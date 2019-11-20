// USART.h

#ifndef _USART_H_
#define _USART_H_

//INCLUDE

//DEFINE

//PROTOTYPE FONCTIONS EXTERNES
void Usart0_Tx(char data);
void Usart0_Tx_String(char *String);
void USART0_Init_9600_INT_ON_RX(void);
void USART0_Init_9600(void);
void USART0_Init_115200_INT_ON_RX(void);

#endif /* _USART_H */
