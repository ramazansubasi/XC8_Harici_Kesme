/* 
 * File:   main.c
 * Author: Ramazan Suba?i (subram)
 *
 * Created on 26 Mayis 2014 Pazartesi, 15:41
 */
#include <xc.h>

#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is digital I/O, MCLR internally tied to VDD)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = ON         // Data EE Memory Code Protection bit (Data EE memory code-protected)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off)
#pragma config CCPMX = RB0      // CCP1 Pin Selection bit (CCP1 function on RB0)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal External Switchover mode disabled)

#define _XTAL_FREQ 4000000
#define Buton RB0
#define LED RB1

void interrupt INT(void){
    unsigned int i;         // i?aretsiz 8 bit de?i?ken tan?mlan?yor
    if (INT0IF==1){         // RBO/INT kesmesi olu?tu mu?
       LED=~LED;            // i her artt???nda LED'in durumu de?i?ecek
        __delay_ms(10);     // Buton ark? için gecikme
    }
    INT0IF=0;               // RBo/INT Kesme Bayra?? S?f?rlan?yor
}
void main(void) {
    TRISB=0b00000001;       // RBO giri?
    PORTB=0x00;             // PORTB Komple S?f?rland?
    INTEDG=1;               // Yükselen Kenar Tetikleme
    INT0IE=1;               // RBO/INT Kesmesi Aktif Edildi
    GIE=1;                  // Tüm Kesmeler Aktif
    while(1){
    }
}

    

