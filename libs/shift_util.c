#include "shift_util.h"

uint8_t shift_in(volatile uint8_t* output_port, uint8_t clk_pin, volatile uint8_t* input_pin, uint8_t data_pin, uint8_t bit_order)
{
    uint8_t data = 0;

    for(uint8_t i=0; i < 8; i++)
    {
        SET_PIN_LEVEL(*output_port, clk_pin, HIGH);

        uint8_t input = GET_INPUT_LEVEL(*input_pin, data_pin);
        uint8_t shift_count = bit_order == BITORDER_LSB_FIRST ? i : (7 - i); 

        data |= input << shift_count;
        
        SET_PIN_LEVEL(*output_port, clk_pin, LOW);
    }

    return data;
}
