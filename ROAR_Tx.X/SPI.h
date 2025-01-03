/*
 * SPI communication
 * Author: eDanielSR
 * Comments:
 * Revision history: 08/12/24
 */

#include <xc.h>
#define _XTAL_FREQ 48000000UL

//Clock frequency
#define SPI_Clock_4  0
#define SPI_Clock_16 1
#define SPI_Clock_64 2
#define SPI_TMR2     3
#define SPI_Slave_R5 4
#define SPI_Slave_IO 5

//Work mode
#define MODO_1  '1'
#define MODO_2  '2'
#define MODO_3  '3'
#define MODO_4  '4'

//Data rw
#define DATO_Mitad 0
#define DATO_Fin   1

void SPI_Init_Master(char reloj, char modo, char smp);
void SPI_Init_Slave(char reloj, char modo);
void SPI_Tx(char dato);
char SPI_Rx();