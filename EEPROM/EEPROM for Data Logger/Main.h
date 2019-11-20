// Main.h

#ifndef _main_h_
#define _main_h_

//****************************************
//  CONSIGNES ET OBJECTIFS DU PROGRAMME
//****************************************

/*
Schéma proteus : 
*/
// INCLUDE (si applicable)

// DEFINE 

// Fréquence µC
//#define _1MHZ
#define _8MHZ

// Gestion registre par bit unique
#define SET_BIT(port,bit)  (port |= (1<<bit))   //set bit in port
#define CLR_BIT(port,bit)  (port &= ~(1<<bit))  //clear bit in port
#define TOGGLE_IO(port,bit) (port = (1<<bit))   //toggle

#define TRUE				1
#define FALSE				0

#define V_MIN	0
#define V_MAX	5


#ifndef NULL
#define NULL	0
#endif

enum {NONE,UP, DOWN, LEFT, ENTER, RIGHT};	// Used with the button variable
	
// STATE MACHINE
#define ST_TXT_ADC_DAC	1	



//DECLARATION DES FONCTIONS
//CALLBACK
void Switch_LED(void);



//STATE MACHINE

//AUTRES





#endif /* _main.h */
