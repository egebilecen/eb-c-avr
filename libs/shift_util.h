#ifndef SHIFT_UTIL_H
#define SHIFT_UTIL_H

#include <avr/io.h>
#include <util/delay.h>

#include "pin_util.h"

#define BITORDER_LSB_FIRST 1U
#define BITORDER_MSB_FIRST 2U

uint8_t shift_in(volatile uint8_t* output_port, uint8_t clk_pin, volatile uint8_t* input_pin, uint8_t data_pin, uint8_t bit_order);

#endif
