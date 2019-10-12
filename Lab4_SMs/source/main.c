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
    DDRC = 0xFF; PORTC = 0x00;
    
    enum states {INIT, WAIT, PRESS_#, RELEASE_#, PRESS_Y, OPEN} state;
    state = INIT;
    /* Insert your solution below */
    while (1) {
        switch(state){
            case INIT:
                state = WAIT;
                break;
            case WAIT:
                if((PINA & 0x04) == 1){
                    state = PRESS_#;   
                }
                else{
                    state = WAIT;    
                }
                break;
            case PRESS_#:
                if((PINA & 0x04) == 1){
                    state = PRESS_#;   
                }
                else if(PINA == 0){
                    state = RELEASE_#;    
                }
                else{
                    state = WAIT;    
                }
                break;
            case RELEASE_#:
                if(PINA == 0){
                    state = RELEASE_#;   
                }
                else if((PINA & 0x02) == 1){
                    state = PRESS_Y;    
                }
                else{
                    state = WAIT;    
                }
                break;
            case PRESS_Y:
                if((PINA & 0x02) == 1){
                    state = OPEN;   
                }
                else if((PINA & 0x02) == 0){
                    state = OPEN;    
                }
                else{
                    state = WAIT;    
                }
                break;
            case OPEN:
                if(PINA == 0x80){
                    state = WAIT;
                }
                else{
                    state = OPEN;
                }
                break;

        }   
        switch(state){
            case INIT:
                PORTB = 0x00;
                break;
            case WAIT:
                PORTB = 0x00;
                break;
            case PRESS_#:
                break;
            case RELEASE_#:
                break;
            case PRESS_Y:
                break;
            case OPEN:
                PORTB = 0x01;
                break;
        }
    }
    return 1;
}
