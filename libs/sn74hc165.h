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

struct SN74HC165_REGISTER_PINS
{
    volatile uint8_t* OUTPUT_PORT;
    volatile uint8_t* INPUT_PIN;
    uint8_t           SH_LD;
    uint8_t           CLK;
    uint8_t           QH; // INPUT
};

uint8_t sn74hc165_get_data(struct SN74HC165_REGISTER_PINS* pins);

#endif