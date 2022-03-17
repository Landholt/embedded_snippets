#ifndef MACROS_H
#define MACROS_H

#include <stdint.h>

#define CLOCK (*((volatile uint32_t *) 0x400fe608))     // GPIO Run Mode Clock Gating Control
#define FDEN (*((volatile uint32_t *) 0x4002551C))      // Digital Enable Register with offset for Port F's Advanced  Peripheral Bus
#define FLOCK (*((volatile uint32_t *) 0x40025520))     // Data direction register for Port F
#define FCR (*((volatile uint32_t *) 0x40025524))       // Data direction register for Port F
#define FPUR (*((volatile uint32_t *) 0x40025510))      // Pull-up resistor control register for Port F
#define FDIR (*((volatile uint32_t *) 0x40025400))      // Data direction register for Port F
#define FDATA (*((volatile uint32_t *) 0x4002507C))     // Data register for Port F; read bits [4:0] of the mask, which is bits [9:2] of the register

#define RED 0x02
#define BLUE 0x04
#define PURPLE 0x06
#define GREEN 0x08
#define YELLOW 0x0A
#define CYAN 0x0C
#define WHITE 0x0E

#define SW1 ((~FDATA & 0x10)>>4)                        // Left switch pressed
#define SW2 (~FDATA & 0x01)                             // Right switch pressed
#define BOTH (SW1 & SW2)                                // Both switches pressed

#endif
