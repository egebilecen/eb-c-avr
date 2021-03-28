#ifndef PIN_UTIL_H
#define PIN_UTIL_H

#include <avr/io.h>

#ifndef INPUT
#define INPUT 0x00
#endif

#ifndef OUTPUT
#define OUTPUT 0x01
#endif

#ifndef LOW
#define LOW 0x00
#endif

#ifndef HIGH
#define HIGH 0x01
#endif

#define SET_PIN_MODE(DDR, PIN, MODE) MODE == OUTPUT ? (DDR |= (1 << PIN)) : (DDR &= ~(1 << PIN))
#define SET_PIN_LEVEL(PORT, PIN, LEVEL) LEVEL == HIGH ? (PORT |= (1 << PIN)) : (PORT &= ~(1 << PIN))
#define GET_INPUT_LEVEL(INPUT_PIN, PIN) (INPUT_PIN & (1 << PIN)) > 0x00 ? HIGH : LOW
#define TOGGLE_PIN_LEVEL(PORT, PIN) PORT ^= (1 << PIN)

#endif
