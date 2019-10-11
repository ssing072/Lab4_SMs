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
    DDRA = 0x00; PORTA: 0xFF;
    DDRB = 0xFF; PORTB: 0x00;
    
    enum states {init, wait, light_change} state;
    state = init;
    
    /* Insert your solution below */
    while (1) {
        switch(state){
            case init:
                state = WAIT;
                break;
            case wait:
                if((PINA & 0x01) == 1){
                    state = light_change;
                }
                else{
                    state = wait;
                }
                break;
            case light_change:
                if((PINA & 0x01) == 1){
                    state = wait;
                }
                else if(PINA == 0){
                    state = light_change;
                }
                break;
        }
        switch (state) {
            case init:
                PORTB = 0x01;
                break;
            case wait:
                break;
            case change_lights:
                if(PORTB == 0x01){
                    PORTB == 0x02;
                }
                else if(PORTB == 0x02){
                    PORTB == 0x01;
                }
                break;
        }
    }
    return 1;
}
