//FONCTIONS Hardware

//INCLUDE
#include <avr/io.h>
#include "Main.h"

//DECLARATION DES VARIABLES GLOGALES
//unsigned char Led;
unsigned char Relais;

//PROTOTYPE FONCTIONS INTERNES


//CONTENU FONCTIONS EXTERNES

void Init_Hardware(void)
{
	/* Configuration I/O */
	//LED en PD7 en mode Output
  	SET_BIT(DDRD,DDD7);
	// LED OFF au démarrage
	//Led = FALSE;
	CLR_BIT(PORTD,PD7);
	// RELAIS en PD6 en mode Output
	SET_BIT(DDRD,DDD6);
	// Contacts RELAIS ouverts au démarrage
	Relais = FALSE;
	CLR_BIT(PORTD,PD6);
	// Bouton poussoir en PD2 en mode Input avec pull up
	CLR_BIT(DDRD,DDD2);
	// Pull UP en PD2 enabled
	SET_BIT(PORTD,PD2);
	// Contact secondaire relais en PA6 en mode Input avec pull up
	CLR_BIT(DDRA,DDA6);
	// Pull UP en PD5 enabled
	SET_BIT(PORTA,PA6);
	// Interruption externe via INT0 de la broche PD2 enabled
	SET_BIT(EIMSK,INT0);
	// Interruption sur flanc descendant
	//(EICRA) ISC01 = 1 |ISC00 = 0
	SET_BIT(EICRA,ISC01);
	CLR_BIT(EICRA,ISC00);
	
	// Configuration clavier 5 touches
	// TOUCHES UP (PC1),DOWN (PC4), LEFT (PC5), RIGHT (PC2), ENTER (PC3)
	//Input Mode
	CLR_BIT(DDRC,DDC1);
	CLR_BIT(DDRC,DDC2);
	CLR_BIT(DDRC,DDC3);
	CLR_BIT(DDRC,DDC4);
	CLR_BIT(DDRC,DDC5);
	//enable pull up
	SET_BIT(PORTC,PC1);
	SET_BIT(PORTC,PC2);
	SET_BIT(PORTC,PC3);
	SET_BIT(PORTC,PC4);
	SET_BIT(PORTC,PC5);
	// enable int
	SET_BIT(PCICR,PCIE2);
	// enable mask
	SET_BIT(PCMSK2,PCINT17);  // UP
	SET_BIT(PCMSK2,PCINT18); // RIGHT
	SET_BIT(PCMSK2,PCINT19); // ENTER
	SET_BIT(PCMSK2,PCINT20); // DOWN
	SET_BIT(PCMSK2,PCINT21); // LEFT
	
		
	// FOR DEBUG OSCILLO
	// PA7 pour COM
	SET_BIT(DDRA,DDA7);
	CLR_BIT(PORTA, PORTA7);
}
//CONTENU FONCTIONS INTERNES
