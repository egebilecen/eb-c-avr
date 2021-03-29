#include "sn74hc165.h"

void sn74hc165_init(uint8_t shift_register_count, struct SN74HC165_REGISTER_PINS* pins)
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

    // Set shift register count
    if(shift_register_count > _max_shift_register_count)
        shift_register_count = _max_shift_register_count;
    else if(shift_register_count < 1)
        shift_register_count = 1;

    _shift_register_count = shift_register_count;
}

struct SHIFT_REGISTER_DATA sn74hc165_get_data(struct SN74HC165_REGISTER_PINS* pins, uint8_t bit_order)
{
    // Parallel load
    SET_PIN_LEVEL(*pins->SH_LD_PORT, pins->SH_LD, LOW);
    _delay_us(0.25);
    SET_PIN_LEVEL(*pins->SH_LD_PORT, pins->SH_LD, HIGH);

    // Get data
    struct SHIFT_REGISTER_DATA data = {0, 0, 0, 0};

    uint32_t sh_reg_data = shift_in32(pins->CLK_PORT, pins->CLK, pins->QH_PIN, pins->QH, bit_order);

    data.sh_reg1 = (sh_reg_data & 0x000000FF) >> 0;
    data.sh_reg2 = (sh_reg_data & 0x0000FF00) >> 8;
    data.sh_reg3 = (sh_reg_data & 0x00FF0000) >> 16;
    data.sh_reg4 = (sh_reg_data & 0xFF000000) >> 24;

    return data;
}
