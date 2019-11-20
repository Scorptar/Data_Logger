//INCLUDE
#include "TIMERS.h"
#include "Main.h"
#include <avr/io.h>

//DECLARATION DES VARIABLES GLOGALES

//PROTOTYPE FONCTIONS INTERNES

//CONTENU FONCTIONS EXTERNES

// TIMER0
void TIMER0_Init_1ms(void)
{
	#if defined (_1MHZ)
		// fréquence horloge = 1000000 hz
		// Utilisation du TIMER 0, comptage sur 8 bits
		// Si diviseur par 8 --> 1000000/8 = 125 Khz
		// Une période = 8µS
		// Si je compte jusque 125 --> 125 X 8 = 1 ms
		TCCR0A = 0x00; // 
		//TCCR0B |= (0<<CS02)|(1<<CS01)|(0<<CS00);
		CLR_BIT(TCCR0B,CS02);
		SET_BIT(TCCR0B,CS01);
		CLR_BIT(TCCR0B,CS00);
		// Valeur initiale du compteur = 256 - 125 = 131
		TCNT0 = 131;
		// Autorisation de l'interruption en cas d'overflow
		//TIMSK0 = (1<<TOIE0);
		SET_BIT(TIMSK0,TOIE0);
	#elif defined (_8MHZ)	
		// fréquence horloge = 8000000 hz
		// Utilisation du TIMER 0, comptage sur 8 bits
		// Si diviseur par 64 --> 8000000/64 = 125 Khz
		// Une période = 8µS
		// Si je compte jusque 125 --> 125 X 8 = 1 ms
		TCCR0A = 0x00;
		//TCCR0B |= (0<<CS02)|(1<<CS01)|(1<<CS00);
		CLR_BIT(TCCR0B,CS02);
		SET_BIT(TCCR0B,CS01);
		SET_BIT(TCCR0B,CS00);
		// Valeur initiale du compteur = 256 - 125 = 131
		TCNT0 = 131;
		// Autorisation de l'interruption en cas d'overflow
		//TIMSK0 = (1<<TOIE0);
		SET_BIT(TIMSK0,TOIE0);
	#endif
}


// TIMER1
void TIMER1_Init_1ms(void)
{
	//En mode compteur le registre TCCR1A = 0x00
	//Si diviseur par 1 -> 1000000/1 = 1000 Khz
	// Une période = 1µS
	// Si je compte jusque 1000 --> 1000 X 1 = 1 ms
	
	/*
	// MODE OVERFLOW
	// (TCCR1B) : WGM13 =0 |WGM12 = 0  (TCCR1A) : WGM11 = 0 | WGM10 =0
	CLR_BIT(TCCR1B, WGM13);
	CLR_BIT(TCCR1B, WGM12);
	CLR_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1A, WGM10);
	
	//No prescaler
	// (TCCR1B) : CS12 = 0 | CS11 = 0 | CS10 = 0
	CLR_BIT(TCCR1B, CS12);
	CLR_BIT(TCCR1B, CS11);
	SET_BIT(TCCR1B, CS10);
	
	// Valeur initiale du compteur = 65536 - 1000 = 64536
	TCNT1H = 0xFC;
	TCNT1L = 0x17;
	// Autorisation de l'interruption en cas d'overflow
	TIMSK1 |= (1<<TOIE1);
	*/
		
	// MODE CTC
	// (TCCR1B) : WGM13 =0 | WGM12 = 1  (TCCR1A) : WGM11 = 0 | WGM10 = 0
	CLR_BIT(TCCR1B, WGM13);
	SET_BIT(TCCR1B, WGM12);
	CLR_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1A, WGM10);
	// No prescaler
	//TCCR1B |= (0<<CS12)|(0<<CS11)|(1<<CS10);
	CLR_BIT(TCCR1B, CS12);
	CLR_BIT(TCCR1B, CS11);
	SET_BIT(TCCR1B, CS10);
	// Valeur limite du timer = 1000
	//OCR1A = 1000;
	OCR1AH = 0x03;
	OCR1AL = 0xE8;
	// Valeur initiale du compteur = 0
	//TCNT1 = 0;
	TCNT1H = 0x00;
	TCNT1L = 0x00;
	// Autorisation interruption si valeur timer >= valeur limite
	//TIMSK1 |= (1<<OCIE1A);
	SET_BIT(TIMSK1,OCIE1A);
}


void TIMER1_Counter1_Init_500MS_MAX(void)
{
	//En mode compteur le registre TCCR1A = 0x00
	//Si diviseur par 8 -> 1000000/8 -- un tic = 8µS
	//Dynamique max = 8µS *65536 = 524.288 mS
	
	// MODE OVERFLOW
	// (TCCR1B) : WGM13 =0 |WGM12 = 0  (TCCR1A) : WGM11 = 0 | WGM10 =0
	CLR_BIT(TCCR1B, WGM13);
	CLR_BIT(TCCR1B, WGM12);
	CLR_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1A, WGM10);
	
	//prescaler /8
	// (TCCR1B) : CS12 = 0 | CS11 = 1 | CS10 = 0
	
	
	//Compteur Off lors de l'initialisation
	CLR_BIT(TCCR1B,CS12);
	CLR_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B, CS10);
	
	// Valeur initiale du compteur = 0
	TCNT1H = 0x00;
	TCNT1L = 0x00;
}

void Start_TIMER1_Counter1_500MS_MAX(void) // Démarrage horloge 8µs (prescaler = /8)
{
	// Valeur initiale du compteur = 0
	TCNT1H = 0x00;
	TCNT1L = 0x00;
	// Clock On
	SET_BIT(TCCR1B, CS11);
}

void Stop_TIMER1_Counter1_500MS_MAX(void)
{
	// Clock Off
	//CLR_BIT(TCCR1B, CS11);
	CLR_BIT(TCCR1B, CS11);
}

unsigned int Value_Timer1_Counter(void)
{
	return TCNT1;
}


//CONTENU FONCTIONS INTERNES
