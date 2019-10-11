/*	Author: ssing072
 *  Partner(s) Name: Neha Gupta
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    
    enum states {init, first_wait, light_1, light_2, next_wait} state;
    state = init;
    /* Insert your solution below */
    while (1) {
        switch(state){
            case init:
                state = first_wait;
                break;
            case first_wait:
                if((PINA & 0x01) == 1){
                    state = light_2;
                }
                else{
                    state = first_wait;
                }
                break;
            case light_1:
                if(PINA == 0){
                    state = first_wait;
                }
                else{
                    state = light_1;
                }
                break;
           case light_2:
                if(PINA == 0){
                    state = next_wait;
                }
                else{
                    state = light_2;
                }
                break;
           case next_wait:
                if((PINA & 0x01) == 1){
                    state = light_1;
                }
                else{
                    state = next_wait;
                }
                break;
        }
        switch (state) {
            case init:
                PORTB = 0x01;
                break;
            case first_wait:
                break;
            case next_wait:
                break;
            case light_1:
                PORTB = 0x01;
                break;
            case light_2:
                PORTB = 0x02;
                break;
        }
    }
    return 1;
}
