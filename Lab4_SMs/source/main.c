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
    
    enum states {INIT, WAIT, INCREMENT, DECREMENT, RESET} state;
    state = INIT;
    /* Insert your solution below */
    while (1) {
        switch(state){
            case INIT:
                state = WAIT;
                break;
            case WAIT:
                if((PINA & 0x01) == 1){
                    state = INCREMENT;
                }
                else if((PINA & 0x02) == 1){
                    state = DECREMENT;
                }
                else if((PINA & 0x01) == 1 && (PINA & 0x02) == 1){
                    state = RESET;    
                }
                else{
                    state = WAIT;
                }
                break;
            case INCREMENT:
                if(PINA == 0){
                    state = WAIT;
                }
                else{
                    state = INCREMENT;
                }
                break;
            case DECREMENT:
                if(PINA == 0){
                    state = WAIT;
                }
                else{
                    state = INCREMENT;
                }
                break;
            case RESET:
                if(PINA == 0x00){
                    state = WAIT;
                }
                else{
                    state = RESET;    
                }
        }   
        switch(state){
            case INIT:
                PORTC = 7;
                break;
            case WAIT:
                break;
            case RESET:
                PORTC = 0;
                break;
            case INCREMENT:
                if(PORTC < 9){
                    PORTC = PORTC + 1;
                }
                break;
            case DECREMENT:
                if(PORTC > 0){
                    PORTC = PORTC + 1;
                }
                break;
        }
    }
    return 1;
}
