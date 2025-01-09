#include <xc.h> // include processor files - each processor file is guarded.
#define _XTAL_FREQ 48000000UL

// Macros ADC
#define AN0                 0X0E
#define AN0_AN01            0X0D
#define AN0_AN02            0X0C
#define AN0_AN03            0X0B
#define AN0_AN04            0X0A
#define AN0_AN05            0X09
#define AN0_AN06            0X08
#define AN0_AN07            0X07
#define AN0_AN08            0X06
#define AN0_AN09            0X05
#define AN0_AN10            0X04
#define AN0_AN11            0X03
#define AN0_AN12            0X02

//Prototipo de funciones
void init_ADC(char Puertos_ADC);
unsigned int read_ADC(unsigned char canal);
