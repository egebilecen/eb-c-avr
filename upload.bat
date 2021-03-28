@echo off

set HEX_FILE="main.hex"
set MCU="m328p"
set PROGRAMMER="arduino"
set AVRDUDE_CONF="D:\egebi\Documents\Programming\Convenient Files\AVR\avrdude.conf"

:: Upload hex file via programmer
:: avrdude -C %AVRDUDE_CONF% -v -c %PROGRAMMER% -p %MCU% -U flash:w:%HEX_FILE%:i
:: Upload hex file via Arduino ISP
avrdude -C %AVRDUDE_CONF% -v -c %PROGRAMMER% -P COM3 -b 9600 -p %MCU% -U lfuse:w:0x62:m -U flash:w:%HEX_FILE%:i
pause
