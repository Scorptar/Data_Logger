#define RTC_ADDRESS 0b1101000		//Adresse du RTC_DS1307

// Adresse des données RTC
/*
#define SECONDE 				0x00
#define MINUTE					0x01
#define	HEURE					0x02
#define JOUR					0x03
#define DATE					0x04
#define MOIS					0x05
#define	ANNEE					0x06
#define CONTROL					0x07*/

enum {SECONDE,MINUTE,HEURE,JOUR,DATE,MOIS,ANNEE,CONTROL};



void setSeconde (unsigned char data);
void setMinute (unsigned char data);
void setHeure (unsigned char data);
void setJour (unsigned char data);
void setDate (unsigned char data);
void setMois (unsigned char data);
void setAnnee (unsigned char data);

void RTC_Clock_Set(unsigned char Sec, 
						   unsigned char Min, 
						   unsigned char Hrs,
						   unsigned char Day, 
						   unsigned char Date,
						   unsigned char Month, 
						   unsigned char Year);

void RTC_Clock_Read_All(void);

void RTC_Clock_Read_Byte(unsigned char Adr_Pointer);

unsigned char convertBCDtoChar(unsigned char AddressOfData, unsigned char Register_Data);

unsigned char convertchartoBCD(unsigned char addressofdata, unsigned char toconvert);