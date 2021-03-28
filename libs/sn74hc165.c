#include "sn74hc165.h"

uint8_t sn74hc165_get_data(struct SN74HC165_REGISTER_PINS* pins)
{
    // Parallel load
    SET_PIN_LEVEL(*pins->OUTPUT_PORT, pins->SH_LD, LOW);
    _delay_us(0.2);
    SET_PIN_LEVEL(*pins->OUTPUT_PORT, pins->SH_LD, HIGH);
    _delay_us(0.2);

    // Get data
    uint8_t data = shift_in(pins->OUTPUT_PORT, pins->CLK, pins->INPUT_PIN, pins->QH, BITORDER_LSB_FIRST);

    return data;
}
