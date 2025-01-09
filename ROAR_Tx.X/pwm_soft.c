/* #include "pwm_soft.h"
*
* Creada por: Ing. Abiezer Hernandez O.
* Fecha de creacion: 20/01/2021
* Electronica y Circuitos
*
*/

#include "pwm_soft.h"

unsigned int contador;
int pwm_value[10];

#ifdef PWM_SOFTWARE
void __interrupt() INT_TMR0()
{
    if(INTCONbits.TMR0IF)
    {
        contador = contador + 7;
        if(contador > 256){
            contador = 0;
        }
        #ifdef PWM_CHANNEL_0
        if(contador < pwm_value[0]){PWM_CHANNEL_0 = 1;} else{PWM_CHANNEL_0 = 0;}     // Pulsos para el canal 0
        #endif

        #ifdef PWM_CHANNEL_1
        if(contador < pwm_value[1]){PWM_CHANNEL_1 = 1;} else{PWM_CHANNEL_1 = 0;}    // Pulsos para el canal 1
        #endif

        #ifdef PWM_CHANNEL_2
        if(contador < pwm_value[2]){PWM_CHANNEL_2 = 1;} else{PWM_CHANNEL_2 = 0;}    // Pulsos para el canal 2
        #endif

        #ifdef PWM_CHANNEL_3
        if(contador < pwm_value[3]){PWM_CHANNEL_3 = 1;} else{PWM_CHANNEL_3 = 0;}    // Pulsos para el canal 3
        #endif

        #ifdef PWM_CHANNEL_4
        if(contador < pwm_value[4]){PWM_CHANNEL_4 = 1;} else{PWM_CHANNEL_4 = 0;}    // Pulsos para el canal 4
        #endif

        #ifdef PWM_CHANNEL_5
        if(contador < pwm_value[5]){PWM_CHANNEL_5 = 1;} else{PWM_CHANNEL_5 = 0;}    // Pulsos para el canal 5
        #endif

        #ifdef PWM_CHANNEL_6
        if(contador < pwm_value[6]){PWM_CHANNEL_6 = 1;} else{PWM_CHANNEL_6 = 0;}    // Pulsos para el canal 6
        #endif

        #ifdef PWM_CHANNEL_7
        if(contador < pwm_value[7]){PWM_CHANNEL_7 = 1;} else{PWM_CHANNEL_7 = 0;}    // Pulsos para el canal 7
        #endif

        #ifdef PWM_CHANNEL_8
        if(contador < pwm_value[8]){PWM_CHANNEL_8 = 1;} else{PWM_CHANNEL_8 = 0;}    // Pulsos para el canal 8
        #endif

        #ifdef PWM_CHANNEL_9
        if(contador < pwm_value[9]){PWM_CHANNEL_9 = 1;} else{PWM_CHANNEL_9 = 0;}    // Pulsos para el canal 9
        #endif

        TMR0 = 0;
        INTCONbits.TMR0IF = 0;
    }
}
#endif

void PWM_Init(void)
{
    INTCONbits.GIE = 0;         // Deshabilita las interrupciones globales
    INTCONbits.PEIE = 0;        // Deshabilita las interrupciones de perifericos
    RCONbits.IPEN = 1;          // Habilita alta prioridad de interrupciones
    INTCON2bits.TMR0IP = 1;     // Alta prioridad para interrupcion del Timer 0
    INTCONbits.TMR0IF = 0;      // Flag del Timer 0 apagada
    INTCONbits.TMR0IE = 1;      // Habilita la interrupcion del Timer 0
    T0CON = 0x48;               // Configuracion del Timer 0
    INTCONbits.TMR0IF = 1;      // Flag del Timer 0 encendida
    INTCONbits.GIE = 1;         // Habilita las interrupciones globales
    INTCONbits.PEIE = 1;        // Habilita las interrupciones de perifericos
    T0CONbits.TMR0ON = 1;       // Enciende el Timer 0
    TMR0 = 0;                   // Carga 0 al Timer 0
}

void PWM_Init_Ports(void)
{
    #ifdef PWM_CHANNEL_0
    PWM_CHANNEL_0_DIR = 0;
    PWM_CHANNEL_0 = 0;
    #endif
    #ifdef PWM_CHANNEL_1
    PMW_CHANNEL_1_DIR = 0;
    PWM_CHANNEL_1 = 0;
    #endif
    #ifdef PWM_CHANNEL_2
    PWM_CHANNEL_2_DIR = 0;
    PWM_CHANNEL_2 = 0;
    #endif
    #ifdef PWM_CHANNEL_3
    PMW_CHANNEL_3_DIR = 0;
    PWM_CHANNEL_3 = 0;
    #endif
    #ifdef PWM_CHANNEL_4
    PMW_CHANNEL_4_DIR = 0;
    PWM_CHANNEL_4 = 0;
    #endif
    #ifdef PWM_CHANNEL_5
    PMW_CHANNEL_5_DIR = 0;
    PWM_CHANNEL_5 = 0;
    #endif
    #ifdef PWM_CHANNEL_6
    PMW_CHANNEL_6_DIR = 0;
    PWM_CHANNEL_6 = 0;
    #endif
    #ifdef PWM_CHANNEL_7
    PMW_CHANNEL_7_DIR = 0;
    PWM_CHANNEL_7 = 0;
    #endif
    #ifdef PWM_CHANNEL_8
    PMW_CHANNEL_8_DIR = 0;
    PWM_CHANNEL_8 = 0;
    #endif
    #ifdef PWM_CHANNEL_9
    PMW_CHANNEL_9_DIR = 0;
    PWM_CHANNEL_9 = 0;
    #endif
}

#ifdef PWM_CHANNEL_0
void PWM_CH0_Duty(int duty)
{
   pwm_value[0] = duty;
}
#endif

#ifdef PWM_CHANNEL_1
void PWM_CH1_Duty(int duty)
{
   pwm_value[1] = duty;
}
#endif

#ifdef PWM_CHANNEL_2
void PWM_CH2_Duty(int duty)
{
   pwm_value[2] = duty;
}
#endif

#ifdef PWM_CHANNEL_3
void PWM_CH3_Duty(int duty)
{
   pwm_value[3] = duty;
}
#endif

#ifdef PWM_CHANNEL_4
void PWM_CH4_Duty(int duty)
{
   pwm_value[4] = duty;
}
#endif

#ifdef PWM_CHANNEL_5
void PWM_CH5_Duty(int duty)
{
   pwm_value[5] = duty;
}
#endif

#ifdef PWM_CHANNEL_6
void PWM_CH6_Duty(int duty)
{
   pwm_value[6] = duty;
}
#endif

#ifdef PWM_CHANNEL_7
void PWM_CH7_Duty(int duty)
{
   pwm_value[7] = duty;
}
#endif

#ifdef PWM_CHANNEL_8
void PWM_CH8_Duty(int duty)
{
   pwm_value[8] = duty;
}
#endif

#ifdef PWM_CHANNEL_9
void PWM_CH9_Duty(int duty)
{
   pwm_value[9] = duty;
}
#endif