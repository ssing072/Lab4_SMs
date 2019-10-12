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
    unsigned char tempOut = 0x00;
    /* Insert your solution below */
    while (1) {
        switch(state){
            case INIT:
                state = WAIT;
                break;
            case WAIT:
                if(PINA == 1){
                    state = INCREMENT;
                }
                else if(PINA == 2){
                    state = DECREMENT;
                }
                else if(PINA == 0){
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
                tempOut = 7;
                break;
            case WAIT:
                break;
            case RESET:
               tempOut = 0;
                break;
            case INCREMENT:
                if(tempOut < 9){
                    tempOut = tempOut + 1;
                }
                break;
            case DECREMENT:
                if(tempOut > 0){
                    tempOut = tempOut + 1;
                }
                break;
        }
        PORTC = tempOut;
    }
    return 1;
}
