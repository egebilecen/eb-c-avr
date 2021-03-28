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
        F --|          |-- E
        G --|          |-- D
        H --|          |-- C
  (?) SER --|          |-- B
      QHC --|          |-- A
      GND --|          |-- QH
             ‾‾‾‾‾‾‾‾‾‾‾
          _
    QHC = QH

    sn74hc165_get_data() return value mapping:
    abcdefgh
    ||||||||
    00000000
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