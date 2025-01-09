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
#include "pwm_soft.h"
#include "adc_lib.h"
#include <stdio.h>

//Macros
#define SS LATAbits.LA5 

//Arrays
int control_data [7] ={0,0,0,0,0,0,0};

//Variables and functions
char DATA_LCD[16];
int data = 0;
int mapping (float min_in, float max_in, float min_out, float max_out, int read);
int dof1 = 0, x = 0;
int dof2 = 0, y = 0;
int z = 0;

void main()
{   
    init_LCD();
    init_ADC(AN0_AN01);
    init_LCD();
    PWM_Init();
    PWM_Init_Ports();
    TRISBbits.RB1 = 0;
    
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
        dof1 = read_ADC(0);
        dof2 = read_ADC(1);
        
        z = mapping(0,1023,-250,250,dof1);
        x = mapping(0,1023,-250,250,dof2);
        
        z = (z < 30 && z > -30) ? (z = 0) : (z = z);      //Filter
        x = (x < 30 && x > -30) ? (x = 0) : (x = x);
        
        //Data send:
        
        SS = 0;
        SPI_Tx(z);
        __delay_ms(5);
        SS = 1;
        __delay_ms(5);
    }
}

int mapping (float min_in, float max_in, float min_out, float max_out, int read){
    int y = 0; float m; float b;
    m = (float)((max_out - min_out) / (max_in - min_in));
    b = (float)((min_out) - (m * min_in));
    y = ((m) * read) + b;
    return y;
}