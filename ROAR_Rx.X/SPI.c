#include "SPI.h"


void SPI_Init_Master(char reloj, char modo, char smp){
    
    //Digital Ports
    ADCON1 = 0x0F;
    
    //Port config
    TRISBbits.RB0 = 1;      //RB0 -> SDI
    TRISBbits.RB1 = 0;      //RB1 -> SCK
    TRISAbits.RA5 = 0;      //RA5 -> SS
    TRISCbits.RC7 = 0;      //RC7 -> SDO
    
    //Clock config
    SSPCON1bits.SSPM = reloj;
    /* Enable SSP port and set TRIS regiter. Sets SPI port as Master and sets Clock 
    Frequency: 0000: Fosc/4
               0001: Fosc/16
               0010: Fosc/64
               0011: TMR2/2   */
    
    //Wave Form, work mode
    if (modo == '1'){
        SSPCON1bits.CKP = 1;
        SSPSTATbits.CKE = 1;
    }
    else if(modo == '2'){
        SSPCON1bits.CKP = 0;
        SSPSTATbits.CKE = 1;
    }
    else if(modo == '3'){
        SSPCON1bits.CKP = 1;
        SSPSTATbits.CKE = 0;
    }
    else if(modo == '4'){
        SSPCON1bits.CKP = 0;
        SSPSTATbits.CKE = 0;
    }
    
    //Data sample
    SSPSTATbits.SMP = smp;
            //Master mode: (1: sample at end) (0: sample at middle)
            //Slave mode: must be cleared
    //MSSP Enable
    SSPCON1bits.SSPEN = 1;
            // 1 = Enables serial port and configures SCK, SDO, SDI and SS as serial port pins
            // 0 = Disables serial port and configures these pins as I/O port pins
}

void SPI_Init_Slave(char reloj, char modo){
    
    //Digital ports
    ADCON1 = 0x0F;
    
    //Port config
    TRISBbits.RB0 = 1;      //RB0 -> SDI
    TRISBbits.RB1 = 1;      //RB1 -> SCK
    TRISAbits.RA5 = 1;      //RA5 -> SS
    TRISCbits.RC7 = 0;      //RC7 -> SDO
    
    //Clock
    SSPCON1bits.SSPM = reloj;
    /*In slave mode:
        0101: SCK pin, noSS disabled
        0100: SCK pin, noSS enabled
     */ 
     
    //Wave form, work mode
    if (modo == '1'){
        SSPCON1bits.CKP = 1;
        SSPSTATbits.CKE = 1;
    }
    else if(modo == '2'){
        SSPCON1bits.CKP = 0;
        SSPSTATbits.CKE = 1;
    }
    else if(modo == '3'){
        SSPCON1bits.CKP = 1;
        SSPSTATbits.CKE = 0;
    }
    else if(modo == '4'){
        SSPCON1bits.CKP = 0;
        SSPSTATbits.CKE = 0;
    }
    
    //MSSP Enable
    SSPCON1bits.SSPEN = 1;
            // 1 = Enables serial port and configures SCK, SDO, SDI and SS as serial port pins
            // 0 = Disables serial port and configures these pins as I/O port pins
}

void SPI_Tx(char dato){ 
    SSPBUF = dato;
        //We write a byte on the SSP buffer (Master mode) --> 
        //The byte is transfered to the SSPSR --> The SSPBUF is deleted
}

char SPI_Rx(){
    return SSPBUF;
        //We return the byte we received (Slave mode)
}
