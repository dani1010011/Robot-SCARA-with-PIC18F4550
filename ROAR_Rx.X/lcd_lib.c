#include "lcd_lib.h"

// Iniciar la LCD
void init_LCD(void){
    // Configuracion e inicializacion puertos
    LCD_DATA_CONF = 0x00;
    LCD_DATA = 0x00;
    
    // Configuración
    RS_CONF = 0;
    EN_CONF = 0;
    RS = 0;
    EN = 0;
    
    // Configuración LCD:
    // 1. Configuración de la pantalla LCD.
    RS = 0;
    LCD_DATA = 0b00111000;
    EN = 1;
    __delay_ms(50);
    EN = 0;
    
    // 2. Activar display.
    LCD_DATA = 0b00001100;
    EN = 1;
    __delay_ms(50);
    EN = 0;
    
    // 3. Limpiar la LCD.
    clear_LCD();
    
    // 4. Posicion inicial
    LCD_DATA = 0b00000010;
    EN = 1;
    __delay_ms(50);
    EN = 0;
    
    // Posición 1,1
    set_Cursor_LCD(1,1);
}

// Limpiar LCD
void clear_LCD(void){
    RS = 0;
    LCD_DATA = 0b00000001;
    EN = 1;
    __delay_ms(5);
    EN = 0;
}

// Funcion para escribir un caracter
void writeChar_LCD(char dato_LCD){
    // Escribir el dato
    RS = 1;
    LCD_DATA = dato_LCD;
    EN = 1;
    __delay_us(50);
    EN = 0;
}

//Función para escribir una cadena de caracteres
void writeString_LCD(const char *dato_LCD){
    //Escribimos el dato:
    for(int i = 0; dato_LCD[i]!='\0';i++){
        writeChar_LCD(dato_LCD[i]);
    }
}

//Funcion para Indicar la posicion del cursor
void set_Cursor_LCD(char x, char y){
    //Colocamos el cursor de una posición home
    RS = 0;
    switch(x){
        case 1:
            LCD_DATA = 0b10000000+(y-1);
            EN = 1;
            __delay_ms(5);
            EN = 0;
            break;
        case 2:
            LCD_DATA = 0b10000000+0x40+(y-1);
            EN = 1;
            __delay_ms(5);
            EN = 0;
            break;
        default:
            LCD_DATA = 0b10000000;
            EN = 1;
            __delay_ms(5);
            EN = 0;
            break;
    }
}