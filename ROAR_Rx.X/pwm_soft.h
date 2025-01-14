/* #include "pwm_soft.h"
*
* Creada por: Ing. Abiezer Hernandez O.
* Fecha de creacion: 20/01/2021
* Electronica y Circuitos
*
*/

#include <xc.h>
#define _XTAL_FREQ 48000000
/*
#define PWM_CHANNEL_0       LATBbits.LB0
#define PWM_CHANNEL_0_DIR   TRISBbits.RB0

#define PWM_CHANNEL_1       LATBbits.LB1
#define PMW_CHANNEL_1_DIR   TRISBbits.RB1

#define PWM_CHANNEL_2       LATBbits.LB2
#define PWM_CHANNEL_2_DIR   TRISBbits.RB2

#define PWM_CHANNEL_3       LATBbits.LB3
#define PMW_CHANNEL_3_DIR   TRISBbits.RB3
*/
#define PWM_CHANNEL_4       LATDbits.LD0
#define PMW_CHANNEL_4_DIR   TRISDbits.RD0
/*
#define PWM_CHANNEL_5       LATDbits.LD1
#define PMW_CHANNEL_5_DIR   TRISDbits.RD1

#define PWM_CHANNEL_6       LATDbits.LD2
#define PMW_CHANNEL_6_DIR   TRISDbits.RD2

#define PWM_CHANNEL_7       LATDbits.LD3
#define PMW_CHANNEL_7_DIR   TRISDbits.RD3

#define PWM_CHANNEL_8       LATEbits.LE0
#define PMW_CHANNEL_8_DIR   TRISEbits.RE0

#define PWM_CHANNEL_9       LATEbits.LE1
#define PMW_CHANNEL_9_DIR   TRISEbits.RE1
*/
#define PWM_SOFTWARE

void PWM_Init(void);
void PWM_Init_Ports(void);

#ifdef PWM_CHANNEL_0
void PWM_CH0_Duty(int duty);
#endif

#ifdef PWM_CHANNEL_1
void PWM_CH1_Duty(int duty);
#endif

#ifdef PWM_CHANNEL_2
void PWM_CH2_Duty(int duty);
#endif

#ifdef PWM_CHANNEL_3
void PWM_CH3_Duty(int duty);
#endif

#ifdef PWM_CHANNEL_4
void PWM_CH4_Duty(int duty);
#endif

#ifdef PWM_CHANNEL_5
void PWM_CH5_Duty(int duty);
#endif

#ifdef PWM_CHANNEL_6
void PWM_CH6_Duty(int duty);
#endif

#ifdef PWM_CHANNEL_7
void PWM_CH7_Duty(int duty);
#endif

#ifdef PWM_CHANNEL_8
void PWM_CH8_Duty(int duty);
#endif

#ifdef PWM_CHANNEL_9
void PWM_CH9_Duty(int duty);
#endif

#ifdef PWM_PORTB
void PWM_PORTB_Duty(int duty);
#endif

#ifdef PWM_PORTD
void PWM_PORTD_Duty(int duty);
#endif