/*
 * Movement.c
 *
 *  Created on: Nov 18, 2013
 *      Author: C15Kirsten.Larson
 */

#include <msp430.h>
#include "Movement.h"

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

