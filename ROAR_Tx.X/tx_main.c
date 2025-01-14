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
/*
#define signalA PORTCbits.RC4
#define signalB PORTCbits.RC5
*/
#define encSwitch PORTCbits.RC0
//Arrays
int control_data [7] ={0,0,0,0,0,0,0};

//Variables and functions
char DATA_LCD[16];
int data = 0;
int mapping (float min_in, float max_in, float min_out, float max_out, int read);

int dof1 = 0, d1 = 0;
int dof2 = 0, d2 = 0;
int dof3 = 0, d3 = 0;
int dof4 = 0, d4 = 0;

int dir1 = 1;
/*
int previous =  0;
int current =   0;
 */
int counter =   0;

void freeMov (void);
void saveMov (void);
void loadMov (void);

void main()
{   
    //4 ADC CH
    ADCON1bits.PCFG =   0x0B;
    init_LCD();
    init_ADC(AN0_AN03);
    init_LCD();
    PWM_Init();
    PWM_Init_Ports();
    TRISBbits.RB1 = 0;
    /*
    //ENCODER INPUTS
    TRISCbits.RC5 = 1;
    TRISCbits.RC4 = 1;
    */
    TRISCbits.RC0 = 1;
    
    
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
    
    //previous =  signalA;
   
    while(1){
        /*
        //Encoder sensing
        current = signalA;
        if(current != previous && current ==1){
            if(signalB != current){
                (counter > 0) ? (counter--) : (counter = 2);  
            }else{
                (counter < 2) ? (counter++) : (counter = 0);             
            }
        }    
        previous = current;
        */
        //Menu
        switch (counter) {
            case 0:                      //FREE MOVEMENT
                sprintf(DATA_LCD,"MUEVE LIBREMENTE");
                set_Cursor_LCD(1,1);
                writeString_LCD(DATA_LCD);
                sprintf(DATA_LCD,"EL ROBOT");
                set_Cursor_LCD(2,4);
                writeString_LCD(DATA_LCD);
                if(encSwitch == 1){
                    while(encSwitch == 1);
                    freeMov();
                }
                break;
            case 1:
                sprintf(DATA_LCD,"MUEVE PARA");
                set_Cursor_LCD(1,3);
                writeString_LCD(DATA_LCD);
                sprintf(DATA_LCD,"GRABAR");
                set_Cursor_LCD(2,5);
                writeString_LCD(DATA_LCD);
                break;
            case 2:
                sprintf(DATA_LCD,"MOVIMIENTO");
                set_Cursor_LCD(1,3);
                writeString_LCD(DATA_LCD);
                sprintf(DATA_LCD,"GUARDADO");
                set_Cursor_LCD(2,4);
                writeString_LCD(DATA_LCD);
                break;
            default:
                sprintf(DATA_LCD,"ERROR");
                set_Cursor_LCD(1,2);
                writeString_LCD(DATA_LCD);
                sprintf(DATA_LCD,"MENU");
                set_Cursor_LCD(2,2);
                writeString_LCD(DATA_LCD);
                break;
        }
        clear_LCD();
        
    }
}

int mapping (float min_in, float max_in, float min_out, float max_out, int read){
    int y = 0; float m; float b;
    m = (float)((max_out - min_out) / (max_in - min_in));
    b = (float)((min_out) - (m * min_in));
    y = ((m) * read) + b;
    return y;
}

void freeMov (void){
    int flag = 0;
    
    while(flag == 0){
        if(encSwitch == 1){
            while(encSwitch == 1);
            flag ++;
        }
        
        dof1 = read_ADC(0);
        dof2 = read_ADC(1);
        dof3 = read_ADC(2);
        dof4 = read_ADC(3);
        
        d1 = mapping(0,1023,-250,250,dof1);
        d2 = mapping(0,1023,-250,250,dof2);
        d3 = mapping(0,1023,-250,250,dof3);
        d4 = mapping(0,1023,-250,250,dof4);
        
        d1 = (d1 < 30 && d1 > -30) ? (d1 = 0) : (d1 = 1);      //Filter
        d2 = (d2 < 30 && d2 > -30) ? (d2 = 0) : (d2 = 1);      //Filter
        d3 = (d3 < 30 && d3 > -30) ? (d3 = 0) : (d3 = 1);      //Filter
        d4 = (d4 < 30 && d4 > -30) ? (d4 = 0) : (d4 = 1);      //Filter
        
        //Data send:
        data = d1 + dir1;
        SS = 0;
        SPI_Tx(d1);
        __delay_ms(5);
        SS = 1;
        __delay_ms(5);
    }
}

void saveMov (void){
    int flag = 0;
    
    while(flag == 0){
        if(encSwitch == 1){
            while(encSwitch == 1);
            flag ++;
        }
        
    }
}

void loadMov (void){
    int flag = 0;
    
    while(flag == 0){
        if(encSwitch == 1){
            while(encSwitch == 1);
            flag ++;
        }
    }
}