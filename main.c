#include <msp430.h>
#include "Movement.h"

int main(void)
{
    WDTCTL = WDTPW|WDTHOLD;                 // stop the watchdog timer
    Init_Robot();
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
