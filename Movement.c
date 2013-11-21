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
        TA0CCR1 = 50;
        TA1CCR1 = 55;
		break;
	case Backward:
        TA0CCR1 = 50;
        TA1CCR1 = 55;
		break;
	case Left:
        TA0CCR1 = 50;
        TA1CCR1 = 0;
		break;
	case Right:
        TA0CCR1 = 0;
        TA1CCR1 = 55;
		break;
	}

}

