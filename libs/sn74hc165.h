#ifndef SN74HC165_H
#define SN74HC165_H

#include <avr/io.h>
#include <util/delay.h>

#include "shift_util.h"
#include "pin_util.h"

/*
             SN74HC165
    SH/LD --|‾‾‾‾‾O‾‾‾‾‾|-- VCC
      CLK --|          |-- CLK INH
        E --|          |-- D
        F --|          |-- C
        G --|          |-- B
        H --|          |-- A
      QHC --|          |-- SER
      GND --|          |-- QH
             ‾‾‾‾‾‾‾‾‾‾‾
          _
    QHC = QH
*/

/*
    Input pins and output pins must be in same port.
    Example: PIND and PORTD.
*/
struct SN74HC165_REGISTER_PINS
{
    volatile uint8_t* SH_LD_DDR;
    volatile uint8_t* SH_LD_PORT;
    uint8_t           SH_LD;

    volatile uint8_t* CLK_DDR;
    volatile uint8_t* CLK_PORT;
    uint8_t           CLK;
    
    volatile uint8_t* QH_DDR;
    volatile uint8_t* QH_PIN;
    uint8_t           QH; // INPUT
};

void sn74hc165_init(struct SN74HC165_REGISTER_PINS* pins);
uint8_t sn74hc165_get_data(struct SN74HC165_REGISTER_PINS* pins);

#endif