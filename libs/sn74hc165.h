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
    ABCDEFGH
    ||||||||
    00000000
*/

static uint8_t       _shift_register_count     = 1;
static uint8_t const _max_shift_register_count = 4;

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

struct SHIFT_REGISTER_DATA
{
  uint8_t sh_reg1;
  uint8_t sh_reg2;
  uint8_t sh_reg3;
  uint8_t sh_reg4;
};

void sn74hc165_init(uint8_t shift_register_count, struct SN74HC165_REGISTER_PINS* pins);
struct SHIFT_REGISTER_DATA sn74hc165_get_data(struct SN74HC165_REGISTER_PINS* pins, uint8_t bit_order);

#endif