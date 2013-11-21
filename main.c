#include <msp430.h>
#include "Movement.h"

int main(void)
{
    WDTCTL = WDTPW|WDTHOLD;                 // stop the watchdog timer

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

    while (1) {
        __delay_cycles(1000000);
        Move_Robot(Forward);
        Move_Robot(Stop);
        Move_Robot(Backward);
        Move_Robot(Stop);
        Move_Robot(Left45);
        Move_Robot(Stop);
        Move_Robot(Right45);
        Move_Robot(Stop);
        Move_Robot(Left90);
        Move_Robot(Stop);
        Move_Robot(Right90);
        Move_Robot(Stop);
    }

    return 0;
}
