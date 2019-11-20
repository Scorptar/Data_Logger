#include "DS1307.h"
#include "I2C_Master.h"
#include "USART.h"

//extern volatile unsigned char I2C_buf[I2C_BUFFER_SIZE];		//Transceiver buffer
unsigned char RTC_buf[ TWI_BUFFER_SIZE ];    // Transceiver buffer

extern unsigned char TWI_buf[ TWI_BUFFER_SIZE ]; 

unsigned char I2C_seconde;
unsigned char I2C_minute;
unsigned char I2C_heure;
unsigned char I2C_jour;
unsigned char I2C_date;
unsigned char I2C_mois;
unsigned char I2C_annee; 

char Day_Name[7][9]={"Dimanche","Lundi","Mardi","Mercredi","Jeudi","Vendredi","Samedi"};

//Initial clock set
void RTC_Clock_Set(unsigned char Sec, 
						   unsigned char Min, 
						   unsigned char Hrs,
						   unsigned char Day, 
						   unsigned char Date,
						   unsigned char Month, 
						   unsigned char Year)
{
	RTC_buf[0] = ((RTC_ADDRESS<<1)|0);		//Salve Address + W
	RTC_buf[1] = SECONDE;					//First Address of DS1307 register 
	RTC_buf[2] = convertchartoBCD(SECONDE, Sec);
	RTC_buf[3] = convertchartoBCD(MINUTE, Min);
	RTC_buf[4] = convertchartoBCD(HEURE, Hrs);
	RTC_buf[5] = convertchartoBCD(JOUR, Day);
	RTC_buf[6] = convertchartoBCD(DATE, Date);
	RTC_buf[7] = convertchartoBCD(MOIS, Month);
	RTC_buf[8] = convertchartoBCD(ANNEE, Year);
	TWI_Start_Transceiver_With_Data(RTC_buf, 9);
}

void RTC_Clock_Read_All(void)
{
	RTC_buf[0] = ((RTC_ADDRESS<<1)|0);		//Salve Address + W 
	RTC_buf[1] = 0x00;
	TWI_Start_Transceiver_With_Data(RTC_buf, 2);
	RTC_buf[0] = ((RTC_ADDRESS<<1)|1);		//Salve Address + R
	//TWI_Start_Transceiver_With_Data(RTC_buf, 8);
	TWI_Start_Transceiver_With_Data(RTC_buf, 9);
	while ( TWI_Transceiver_Busy() );             // Wait until TWI is ready for next transmission.
	//FOR DEBUG
	//Usart0_Tx_String_Lenght(TWI_buf, 8);
}

void RTC_Clock_Read_Byte(unsigned char Adr_Pointer)
{
	RTC_buf[0] = ((RTC_ADDRESS<<1)|0);		//Salve Address + W
	RTC_buf[1] = Adr_Pointer;
	TWI_Start_Transceiver_With_Data(RTC_buf, 2);
	RTC_buf[0] = ((RTC_ADDRESS<<1)|1);		//Salve Address + R
	TWI_Start_Transceiver_With_Data(RTC_buf, 2);
	//TWI_Start_Transceiver_With_Data(RTC_buf, 8);
	while ( TWI_Transceiver_Busy() );             // Wait until TWI is ready for next transmission.
	// FOR DEBUG
	//Usart0_Tx(TWI_buf[1]); 
}

// Conversion du BCD en décimal
unsigned char convertBCDtoChar(unsigned char AddressOfData, unsigned char Register_Data)
{
	unsigned char dizaine = 0;
	unsigned char unite = 0;
 	unsigned char valeur = 0;
	// Selon le type de donnée, 
	switch (AddressOfData)
	{
		case SECONDE :
			// Isolation des dizaines dans le BCD et shift de 4 bits pour le convertir en nombre de dizaine
			dizaine = ((Register_Data & 0b01110000)>> 4);
			// Isolation des unités dans le BCD
			unite = Register_Data & 0b00001111;
			// La valeur de retour est le nombre de dizaine multiplié par 10 auquel on ajoute les unités
			valeur = dizaine * 10 + unite;
			break;

		case MINUTE :
			dizaine = ((Register_Data & 0b01110000)>> 4);
			unite = Register_Data & 0b00001111;
			valeur = dizaine * 10 + unite;
			break;

		case HEURE :
			// Si on est en mode 12 ou 24h on isole un (12h) ou deux (24h) bits
			if((Register_Data & 0b01000000) != 0)
			{
				dizaine = ((Register_Data & 0b00010000)>> 4);
			}
			else
			{
				dizaine = ((Register_Data & 0b00110000)>> 4);
			}
			unite = Register_Data & 0b00001111;
			valeur = dizaine * 10 + unite;
			break;

		case JOUR :
			valeur = Register_Data;
			break;
		
		case DATE :
			dizaine = ((Register_Data & 0b00110000)>> 4);
			unite = Register_Data & 0b00001111;
			valeur = dizaine * 10 + unite;
			break;
		
		case MOIS :
			dizaine = ((Register_Data & 0b00010000)>> 4);
			unite = Register_Data & 0b00001111;
			valeur = dizaine * 10 + unite;
			break;

		case ANNEE :
			dizaine = ((Register_Data & 0b11110000)>> 4);
			unite = Register_Data & 0b00001111;
			valeur = dizaine * 10 + unite;
			break;
		default :
			valeur = Register_Data;
			break;
	}

	return valeur;
}

// Conversion d'un nombre en BCD
unsigned char convertchartoBCD(unsigned char addressofdata, unsigned char toconvert)
{
	unsigned char dizaine = 0;
	unsigned char unite = 0;
	unsigned char valeurretour = 0;
	
	// On récupère l'unité du nombre par un modulo
	unite = toconvert % 10;
	// On récupère la dizaine du nombre
	dizaine = toconvert/10;

	switch (addressofdata)
	{
		// Shift de 4 bits pour les dizaines et ajout des unites aux 4 derniers bits pour
		// les secondes, heures, minutes, dates, mois, année
		case SECONDE :
		case HEURE :
		case MINUTE :
		case DATE :
		case MOIS :
		case ANNEE :
		valeurretour = ((dizaine << 4) | (unite));
		break;

		// Dans les autres cas pas de modification de la donnée
		default :
		valeurretour = toconvert;
		break;
	}

	return valeurretour;
	

}