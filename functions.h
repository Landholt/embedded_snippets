#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "macros.h"

void init_F() {                                         // Initialize Port F for LED output and on-board switch input, nothing else
    CLOCK = 0x20;                                       // set bit 5, providing clock to Port F
    FLOCK = 0x4C4F434B;                                 // Unlock the Commit Register
    FCR = 0x01;                                         // Enable writing to the Alternate Function and DEN/PUR/PDR registers of pin 0 (switch 2)
    FDEN = 0x1f;                                        // Enable Digital I/O for switches and RGB pins [4:0]
    FPUR = 0x11;                                        // Enable pull-up resistor for switches (pins 4 and 0)
    FDIR = 0x0E;                                        // Set RGB pins [3:1] as output
}

int i;
void delay() {                                          // Simple to be used for flashing lights
    for (i = 0; i < 200000; i++) {}
}

void light_if_both(uint32_t color) {
    if (BOTH) {
        FDATA |= color;
    }
    FDATA &= ~color;
}

void blink(uint32_t color) {
    FDATA |= color;
    delay();
    FDATA &= ~color;
    delay();
}

#endif
