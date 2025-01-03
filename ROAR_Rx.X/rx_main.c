/*
 * Robot Arm Receptor
 * File:   rx_main.c
 * Author: tpdaniel
 *
 * Created on 15 de diciembre de 2024, 07:39 PM
 */

#define _XTAL_FREQ 48000000UL
#include "18F4550.h"
#include <xc.h>
#include "SPI.h"
#include <stdio.h>

//Macros

//Variables

void main()
{
    char dato;
    SPI_Init_Slave(SPI_Slave_R5, MODO_1);
    __delay_ms(100);
    
    while(1){
        //SPI data read:
        dato = SPI_Rx();
        __delay_ms(5);   
    }
    
}

