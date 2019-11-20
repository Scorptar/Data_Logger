# Data_Logger
Data Logger for Arduino 1284P 8Mhz. With the microcontroller, it controls the measures of several sensors.

Sub-functions :
- HMI : 
	- State machine
	- Convivial menu
	- DS1307 clock configuration
	- Measures frequence configuration
	- Measure selection
	- Data sending to EEPROM through USART terminal
- T° and humidity measures : 
	- Sht11 integrated circuit use
	- 1-link communication (custom I2C)
	- Proteus simulation
- Light Click luminosity measure + soil measure + pH measure : 
	- Luminosity sensor consisting of an analog. interface with photodiode + DAC MCP3201 (SPI)
	- Proteus simulation for Luminosity measure
	- Soil measure in dirt with a simple resistance measure (analog interface + DAC)
	- pH measure directly gives an analog value (digital convertion with an internal DAC)
- External EEPROM for data saving : EEPROM 24LC512 (I2C) + Proteus Simulation
- FM / RS485 communication between Data_Logger and a remote microcontroller :
	- USART communication with Radiometrix FR emitter/receptor
	- Radiometrix CTRL124 decoder/encoder utilisation (max rate : 40 kbps)
	- Automated data sending to the remote microcontroller
	- At the receptor (remote microcontroller) : directly send it to a PC USART terminal
	- Same with RS485 link (using ADM485 CI)
	
	
