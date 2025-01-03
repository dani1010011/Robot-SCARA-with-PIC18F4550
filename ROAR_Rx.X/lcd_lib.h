#include <xc.h> // include processor files - each processor file is guarded.
#define _XTAL_FREQ 48000000UL

// Macros LCD
#define LCD_DATA_CONF TRISD
#define LCD_DATA LATD
#define RS_CONF TRISBbits.RB3
#define EN_CONF TRISBbits.RB4
#define RS LATBbits.LB3
#define EN LATBbits.LB4

// Prototipos de funciones
void init_LCD(void);
void clear_LCD(void);
void writeChar_LCD(char dato_LCD);
void writeString_LCD(const char *dato_LCD);
void set_Cursor_LCD(char x,char y);



