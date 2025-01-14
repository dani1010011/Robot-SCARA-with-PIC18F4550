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
#include "pwm_soft.h"
#include <stdio.h>

//Variables
  int dato = 0;

void main()
{
    PWM_Init();
    PWM_Init_Ports();
    
    SPI_Init_Slave(SPI_Slave_R5, MODO_1);
    __delay_ms(100);
    
    while(1){
        /*
        if(dato == 8){
            PWM_CH4_Duty(100);
            LATDbits.LD1 = 1;
        }else if(dato == 4){
            PWM_CH4_Duty(100);
            LATDbits.LD1 = 0;
        }else{
            PWM_CH4_Duty(100);
            LATDbits.LD1 = 1;
        }
        */
        //SPI data read:
        dato = SPI_Rx();
        __delay_ms(5);
    }
    
}

