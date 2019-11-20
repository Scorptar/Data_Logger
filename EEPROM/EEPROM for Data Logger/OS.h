#ifndef __CALLBACK_H
#define __CALLBACK_H

//D�finit le nombre maximal de callback de type Chrono
#define	MAX_CALLBACKS		10
#define MAXBUFUSART0		4

// PROTOTYPE DES FONCTIONS EXTERNES
//**********************************************************
//********** FONCTIONS POUR LE MOTEUR OS *******************
//**********************************************************

//Initialisation des Callbacks
void Callbacks_Init(void);

//Enregistrer des fonctions callback li�es au temps
//Retourne un ID associ� � l'enregistrement
unsigned char Callbacks_Record_Timer(void(*pt_Function)(void), unsigned int Time); 

//Retirer des fonctions callback li�es au temps, prend l'ID du CallBack comme argument
char Callbacks_Remove_Timer(unsigned char IDCB);

//Enregistrer des fonctions callback li�es � l'USART
void Callbacks_Record_Usart0_RX(void(*ptFonction)(volatile char*));

//Retirer des fonctions callback li�es � l'USART
void Callbacks_Remove_Usart0_RX(void);

//D�marrage de la boucle principale
void OS_Start(void);

//State MAchine
unsigned char StateMachine(char state, unsigned char stimuli);

#endif //__CALLBACK_H
