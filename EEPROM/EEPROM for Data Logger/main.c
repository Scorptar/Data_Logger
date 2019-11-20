
// INCLUDE
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Main.h"
#include "OS.h"
#include "Hardware.h"
#include "USART.h"
#include "lcd.h"
#include "TIMERS.h"
#include "ftoa.h"
#include "SPI.h"
#include <stdlib.h>  // fonction itoa()


// DIVERS
char String[10];						// Tampon pour la fonction itoa

// Callbacks
unsigned char IDCB_Led = 0; 			// Identificateur Callback Clignote_LED


//****************** fonction principale *****************
int main (void)
{
 	//Initialisation hardware 
	Init_Hardware();
	
	// Initialisation des Callbacks
	Callbacks_Init();
 	IDCB_Led = Callbacks_Record_Timer(Switch_LED, 500);
	//Callbacks_Record_Usart0_RX(USART0_RX);
	
	//Initilisation LCD
	lcd_init(LCD_DISP_ON); lcd_clrscr(); 
	
	//Initialisation SPI  
	// Ne pas oublier de configurer le CS du MCP4921 dans Hardware.c !!
	SPI_MasterInit();
		
	// Lancement OS (Boucle infinie)
	OS_Start();
	//N'arrive jamais ici
	return 0; 
}



//CALLBACK
//**************** Switch LED ************************************
//  Signalisation par clignotement de la LED  pendant 500 ms 
//****************************************************************
void Switch_LED(void)
{
	TOGGLE_IO(PIND,PIND7);
}

//****************USART0_RX*************************
// Appelé quand on a reçu un message du terminal PC
//**************************************************
void USART0_RX(volatile char *Trame_USART0)
{
	
}

//STATE MACHINE


//AUTRES FONCTIONS

