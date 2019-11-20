// TIMERS.h
#ifndef _TIMERS_H_
#define _TIMERS_H_

//DEFINE

//PROTOTYPE FONCTIONS EXTERNES
void TIMER0_Init_1ms(void);
void TIMER1_Init_1ms(void);
void TIMER1_Counter1_Init_500MS_MAX(void);
void Start_TIMER1_Counter1_500MS_MAX(void); // Démarrage horloge 8µs (prescaler = /8)
void Stop_TIMER1_Counter1_500MS_MAX(void);
unsigned int Value_Timer1_Counter(void);

#endif /* _TIMERS_H */
