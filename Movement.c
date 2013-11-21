/*
 * Movement.c
 *
 *  Created on: Nov 18, 2013
 *      Author: C15Kirsten.Larson
 */

#include <msp430.h>
#include "Movement.h"

void Init_Robot(void){
    P1DIR |= BIT2|BIT1;                // TA0CCR1 on P1.2
    P1SEL |= BIT2|BIT1;				// TA0CCR1 on P1.2
    P2DIR |= BIT1|BIT0;				//C2C Shriner showed me how to implement the second wheel
    P2SEL |= BIT1|BIT0;

    TA0CTL &= ~MC1|MC0;            // stop timer A0
    TA1CTL &= ~MC1|MC0;

    TA0CTL |= TACLR;                // clear timer A0
    TA1CTL |= TACLR;

    TA0CTL |= TASSEL1;           // configure for SMCLK
    TA1CTL |= TASSEL1;

    TA0CCR0 = 100;                // set signal period to 100 clock cycles (~100 microseconds)
    TA0CCR1 = 50; 					// set duty cycle to 25/100 (25%)
    TA1CCR0 = 100;
    TA1CCR1 = 55;



    TA0CTL |= MC0;                // count up
    TA1CTL |= MC0;
}

void Move_Robot(unsigned char movement) {
	switch (movement) {
	case Forward:
		TA0CCTL1 &= ~OUTMOD_5;
	    TA0CCTL1 |= OUTMOD_7;
	    TA0CCTL0 &= ~OUTMOD_7;
	    TA0CCTL0 |= OUTMOD_5;

	    TA0CCR1 = 50;

	    TA1CCTL1 &= ~OUTMOD_5;
	    TA1CCTL1 |= OUTMOD_7;
	    TA1CCTL0 &= ~OUTMOD_7;
	    TA1CCTL0 |= OUTMOD_5;

	    TA1CCR1 = 55;
        __delay_cycles(1000000);
		break;
	case Backward:				//I looked at C2C Shriner's code to figure out how to flip the bits.
		TA0CCTL1 &= ~OUTMOD_7;
		TA0CCTL1 |= OUTMOD_5;
		TA0CCTL0 &= ~OUTMOD_5;
		TA0CCTL0 |= OUTMOD_7;

		TA1CCTL1 &= ~OUTMOD_7;
		TA1CCTL1 |= OUTMOD_5;
		TA1CCTL0 &= ~OUTMOD_5;
		TA1CCTL0 |= OUTMOD_7;
        __delay_cycles(300000);
		break;
	case Left45:
		TA0CCTL1 &= ~OUTMOD_5;
		TA0CCTL1 |= OUTMOD_7;
		TA0CCTL0 &= ~OUTMOD_7;
		TA0CCTL0 |= OUTMOD_5;

        TA0CCR1 = 40;

		TA1CCTL1 &= ~OUTMOD_7;
		TA1CCTL1 |= OUTMOD_5;
		TA1CCTL0 &= ~OUTMOD_5;
		TA1CCTL0 |= OUTMOD_7;
        __delay_cycles(200000);
		break;
	case Right45:
		TA0CCTL1 &= ~OUTMOD_7;
		TA0CCTL1 |= OUTMOD_5;
		TA0CCTL0 &= ~OUTMOD_5;
		TA0CCTL0 |= OUTMOD_7;

		TA1CCTL1 &= ~OUTMOD_5;
		TA1CCTL1 |= OUTMOD_7;
		TA1CCTL0 &= ~OUTMOD_7;
		TA1CCTL0 |= OUTMOD_5;

        TA1CCR1 = 40;
        __delay_cycles(200000);
		break;
	case Left90:
		TA0CCTL1 &= ~OUTMOD_5;
		TA0CCTL1 |= OUTMOD_7;
		TA0CCTL0 &= ~OUTMOD_7;
		TA0CCTL0 |= OUTMOD_5;

        TA0CCR1 = 55;

		TA1CCTL1 &= ~OUTMOD_7;
		TA1CCTL1 |= OUTMOD_5;
		TA1CCTL0 &= ~OUTMOD_5;
		TA1CCTL0 |= OUTMOD_7;
        __delay_cycles(300000);
		break;
	case Right90:
		TA0CCTL1 &= ~OUTMOD_7;
		TA0CCTL1 |= OUTMOD_5;
		TA0CCTL0 &= ~OUTMOD_5;
		TA0CCTL0 |= OUTMOD_7;

		TA1CCTL1 &= ~OUTMOD_5;
		TA1CCTL1 |= OUTMOD_7;
		TA1CCTL0 &= ~OUTMOD_7;
		TA1CCTL0 |= OUTMOD_5;

        TA1CCR1 = 50;
        __delay_cycles(300000);
        break;
	case Stop:
		TA0CCTL1 &= ~OUTMOD_5;
	    TA0CCTL1 |= OUTMOD_7;
	    TA0CCTL0 &= ~OUTMOD_7;
	    TA0CCTL0 |= OUTMOD_5;

	    TA0CCR1 = 0;

	    TA1CCTL1 &= ~OUTMOD_5;
	    TA1CCTL1 |= OUTMOD_7;
	    TA1CCTL0 &= ~OUTMOD_7;
	    TA1CCTL0 |= OUTMOD_5;

	    TA1CCR1 = 0;
        __delay_cycles(1000000);
	    break;
	}

}

