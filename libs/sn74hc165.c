#include "sn74hc165.h"

void sn74hc165_init(struct SN74HC165_REGISTER_PINS* pins)
{
    // Configure ports as output
    SET_PIN_MODE(*pins->SH_LD_DDR, pins->SH_LD, OUTPUT);
    SET_PIN_MODE(*pins->CLK_DDR,   pins->CLK,   OUTPUT);

    // Configure ports as input
    SET_PIN_MODE(*pins->QH_DDR, pins->QH, INPUT);

    // Set default output states (HIGH)
    SET_PIN_LEVEL(*pins->SH_LD_PORT, pins->SH_LD, HIGH);

    // Set default output states (LOW)
    SET_PIN_LEVEL(*pins->CLK_PORT,  pins->CLK, LOW);
}

uint8_t sn74hc165_get_data(struct SN74HC165_REGISTER_PINS* pins)
{
    // Parallel load
    SET_PIN_LEVEL(*pins->SH_LD_PORT, pins->SH_LD, LOW);
    _delay_us(0.25);
    SET_PIN_LEVEL(*pins->SH_LD_PORT, pins->SH_LD, HIGH);

    // Get data
    uint8_t data = shift_in(pins->CLK_PORT, pins->CLK, pins->QH_PIN, pins->QH, BITORDER_LSB_FIRST);

    return data;
}
