#include "adc_lib.h"

//Inicialización del ADC:
void init_ADC(char Puertos_ADC){
    //Configuración del Módulo ADC:
    ADCON1 = Puertos_ADC;
    ADCON0 = 0x00;
    ADCON2 = 0x8F;  //1 0 001 111
}

unsigned int read_ADC(unsigned char canal){
    if (canal>13){      //Max numero de canales PIC
        return 0;
    }else{
        ADCON0 = 0x00;
        ADCON0bits.CHS = canal;
        
        //Proceso de conversion ADC
        ADCON0bits.ADON = 1;
        ADCON0bits.GO_DONE = 1;
        while(ADCON0bits.GO_DONE == 1);
        ADCON0bits.ADON = 0;
        return ADRES;
    }
}