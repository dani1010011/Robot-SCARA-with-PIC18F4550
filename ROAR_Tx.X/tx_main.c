/*
 * Robot arm Transmissor
 * File:   tx_main.c
 * Author: tpdaniel
 *
 * Created on 15 de diciembre de 2024, 07:40 PM
 */

#define _XTAL_FREQ 48000000UL
#include "18F4550.h"
#include <xc.h>
#include "SPI.h"
#include "lcd_lib.h"
#include <stdio.h>

//Macros
#define SS LATAbits.LA5 

//Variables
char DATA_LCD[16];
int data = 0;

void main()
{   
    init_LCD();
    //Banner:
        sprintf(DATA_LCD,">> ROBOT ARM");
        set_Cursor_LCD(1,2);
        writeString_LCD(DATA_LCD);
        sprintf(DATA_LCD,"CONTROLLER <<");
        set_Cursor_LCD(2,1);
        writeString_LCD(DATA_LCD);
        __delay_ms(1000);
        clear_LCD();
        
     //SPI START:
    SPI_Init_Master(SPI_Clock_4, MODO_1, DATO_Mitad);
    __delay_ms(100);
   
    while(1){
        //Data send:
        SS = 0;
        SPI_Tx(data);
        __delay_ms(5);
        SS = 1;
        __delay_ms(5);
    }
}

