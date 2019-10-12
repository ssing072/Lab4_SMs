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
    
    enum states {INIT, WAIT, FIRST, SECOND, THIRD, OPEN} state;
    state = INIT;
    /* Insert your solution below */
    while (1) {
        switch(state){
            case INIT:
                state = WAIT;
                break;
            case WAIT:
                if(PINA == 1){
                    state = FIRST;   
                }
                else{
                    state = WAIT;    
                }
                break;
            case FIRST:
                if(PINA == 1){
                    state = FIRST;   
                }
                else if(PINA == 0){
                    state = SECOND;    
                }
                else{
                    state = WAIT;    
                }
                break;
            case SECOND:
                if(PINA == 0){
                    state = SECOND;   
                }
                else if(PINA == 2){
                    state = THIRD;    
                }
                else{
                    state = WAIT;    
                }
                break;
            case THIRD:
                if(PINA == 2){
                    state = THIRD;   
                }
                else if(PINA == 0){
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
            case FIRST:
                break;
            case SECOND:
                break;
            case THIRD:
                break;
            case OPEN:
                PORTB = 0x01;
                break;
        }
    }
    return 1;
}
