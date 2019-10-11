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
    
    enum states {init, wait, light_1, light_2} state;
    state = init;
    
    unsigned char tempB = 0x00;
    /* Insert your solution below */
    while (1) {
        switch(state){
            case init:
                state = wait;
                break;
            case wait:
                if((PINA & 0x01) == 1){
                    if(tempB == 0x01){
                        state = light_2;
                    }
                    else if(tempB == 0x02){
                        state = light_1;
                    }
                }
                else{
                    state = wait;
                }
                break;
            case light_1:
                if(PINA == 0){
                    state = wait;
                }
                else{
                    state = light_1;
                }
                break;
           case light_2:
                if(PINA == 0){
                    state = wait;
                }
                else{
                    state = light_2;
                }
                break;
        }
        switch (state) {
            case init:
                PORTB = 0x01;
                tempB = 0x01;
                break;
            case wait:
                break;
            case light_1:
                PORTB = 0x01;
                tempB = 0x01;
                break;
            case light_2:
                PORTB = 0x02;
                tempB = 0x02;
                break;
        }
    }
    return 1;
}
